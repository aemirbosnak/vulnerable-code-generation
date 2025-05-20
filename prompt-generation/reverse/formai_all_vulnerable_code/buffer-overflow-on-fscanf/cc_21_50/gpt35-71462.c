//FormAI DATASET v1.0 Category: Spell checking ; Style: standalone
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50 // Maximum length of a single word
#define MAX_FILENAME_LENGTH 100 // Maximum length of a filename

int main() {
    char filename[MAX_FILENAME_LENGTH]; // Filename containing words to be checked
    char current_word[MAX_WORD_LENGTH]; // Current word being checked
    char dictionary_word[MAX_WORD_LENGTH]; // Word in dictionary being compared
    char c; // Current character read from file
    int dictionary_exists = 0; // Flag indicating whether dictionary file exists
    int word_exists = 0; // Flag indicating whether current word is spelled correctly
    int i, j; // Index variables

    // Ask user for the filename containing words to be checked
    printf("Enter the filename containing words to be checked: ");
    fgets(filename, MAX_FILENAME_LENGTH, stdin);
    filename[strcspn(filename, "\n")] = '\0'; // Remove newline character from filename

    // Open file and check if it exists
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File does not exist.\n");
        return 0;
    }

    // Check if "dictionary.txt" exists in the current directory
    FILE *dictionary = fopen("dictionary.txt", "r");
    if (dictionary != NULL) {
        dictionary_exists = 1;
    }

    // Loop through each word in the file
    while (fscanf(file, "%s", current_word) != EOF) {
        word_exists = 0;

        // Check if word is in dictionary
        if (dictionary_exists) {
            while (fscanf(dictionary, "%s", dictionary_word) != EOF) {
                if (strcasecmp(current_word, dictionary_word) == 0) {
                    word_exists = 1; // Word is spelled correctly
                    break;
                }
            }
            rewind(dictionary); // Set file pointer back to beginning of file
        }

        // If word was not found in dictionary, suggest corrections
        if (!word_exists) {
            printf("The word \"%s\" is spelled incorrectly. Suggestions:\n", current_word);

            // Check each character in the word to see if it can be replaced or removed
            for (i = 0; i < strlen(current_word); i++) {
                // Attempt to replace the character at the current index with every alphabetical character
                for (j = 0; j < 26; j++) {
                    char possible_char = 'a' + j;
                    char old_char = current_word[i];

                    current_word[i] = tolower(possible_char);
                    if (dictionary_exists && !word_exists) {
                        while (fscanf(dictionary, "%s", dictionary_word) != EOF) {
                            if (strcasecmp(current_word, dictionary_word) == 0) {
                                word_exists = 1;
                                printf("- Replace '%c' with '%c'\n", old_char, possible_char);
                            }
                        }
                        rewind(dictionary);
                    }
                    current_word[i] = old_char;
                }

                // Attempt to remove the character at the current index
                memmove(&current_word[i], &current_word[i + 1], strlen(current_word) - i);
                if (dictionary_exists && !word_exists) {
                    while (fscanf(dictionary, "%s", dictionary_word) != EOF) {
                        if (strcasecmp(current_word, dictionary_word) == 0) {
                            word_exists = 1;
                            printf("- Remove '%c'\n", current_word[i]);
                        }
                    }
                    rewind(dictionary);
                }

                // Attempt to add an alphabetical character at the current index
                for (j = 25; j >= 0; j--) {
                    char possible_char = 'a' + j;
                    char new_word[MAX_WORD_LENGTH];
                    strncpy(new_word, current_word, i);
                    new_word[i] = possible_char;
                    strncpy(&new_word[i + 1], &current_word[i], strlen(current_word) - i);

                    if (dictionary_exists && !word_exists) {
                        while (fscanf(dictionary, "%s", dictionary_word) != EOF) {
                            if (strcasecmp(new_word, dictionary_word) == 0) {
                                word_exists = 1;
                                printf("- Add '%c' at index %d\n", possible_char, i);
                            }
                        }
                        rewind(dictionary);
                    }
                }

                // Attempt to add an alphabetical character at the end of the word
                char new_word[MAX_WORD_LENGTH];
                strncpy(new_word, current_word, i);
                new_word[i] = 'a';
                new_word[i + 1] = '\0';

                if (dictionary_exists && !word_exists) {
                    while (fscanf(dictionary, "%s", dictionary_word) != EOF) {
                        if (strcasecmp(new_word, dictionary_word) == 0) {
                            word_exists = 1;
                            printf("- Add 'a' at the end of the word\n");
                        }
                    }
                    rewind(dictionary);
                }

                // Reset current_word for next iteration
                strncpy(current_word, fgets(current_word, MAX_WORD_LENGTH, stdin), strlen(current_word));
            }

            // If corrections were not found, suggest to add the word to the dictionary
            if (!word_exists) {
                printf("- Add the word \"%s\" to the dictionary.\n", current_word);
            }
        }
    }

    // Close files
    fclose(file);
    if (dictionary_exists) {
        fclose(dictionary);
    }

    return 0;
}