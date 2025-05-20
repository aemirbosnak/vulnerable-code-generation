//FormAI DATASET v1.0 Category: Spell checking ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to check if a word is spelled correctly
int check_word(char *word) {
    FILE *dictionary = fopen("dictionary.txt", "r"); // Open the dictionary file in read mode
    char dict_word[50]; // Array to store each word from the dictionary
    int found = 0; // Flag to keep track of whether the word was found in the dictionary or not

    // Loop through each word in the dictionary file and compare it to the given word
    while (fscanf(dictionary, "%s", dict_word) != EOF) {
        if (strcmp(dict_word, word) == 0) { // Words match
            found = 1;
            break;
        }
    }

    fclose(dictionary); // Close the dictionary file
    return found; // Return the flag indicating whether the word was found or not
}

// Main function
int main() {
    char sentence[500]; // Array to store the input sentence
    char word[50]; // Array to store each word in the sentence
    int start_index = 0; // Index of the first character of each word
    int error_count = 0; // Counter for the number of misspelled words

    printf("Enter a sentence: ");
    fgets(sentence, 500, stdin); // Get the input sentence from the user

    // Loop through each character in the sentence
    for (int i = 0; i < strlen(sentence); i++) {
        if (sentence[i] == ' ' || sentence[i] == '\n' || sentence[i] == '\0') {
            // End of word detected
            strncpy(word, sentence + start_index, i - start_index); // Copy the word from the sentence array to the word array
            word[i - start_index] = '\0'; // Add the string terminator to the end of the word array
            start_index = i + 1; // Update the starting index for the next word

            // Check if the word is spelled correctly
            for (int j = 0; j < strlen(word); j++) {
                word[j] = tolower(word[j]); // Convert all letters to lowercase for case-insensitivity
                if (!isalpha(word[j])) { // Check if the character is a letter
                    printf("Invalid input detected: '%c'\n", word[j]);
                    exit(EXIT_FAILURE); // Exit the program with an error message
                }
            }
            if (!check_word(word)) { // Word is misspelled
                printf("Misspelled word detected: '%s'\n", word);
                error_count++;
            }
        }
    }

    // Print the final result
    if (error_count == 0) {
        printf("All words are spelled correctly!\n");
    } else {
        printf("%d misspelled word(s) detected.\n", error_count);
    }

    return 0;
}