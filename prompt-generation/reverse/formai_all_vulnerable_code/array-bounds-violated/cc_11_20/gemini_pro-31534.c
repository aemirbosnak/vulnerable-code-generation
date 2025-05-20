//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int main() {
    // Create a dictionary of words.
    Word dictionary[MAX_WORDS];
    int num_words = 0;

    // Read the dictionary from a file.
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error opening dictionary file.\n");
        return 1;
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, fp) != NULL) {
        // Remove the newline character from the end of the line.
        line[strlen(line) - 1] = '\0';

        // Convert the line to lowercase.
        for (int i = 0; i < strlen(line); i++) {
            line[i] = tolower(line[i]);
        }

        // Add the word to the dictionary.
        strcpy(dictionary[num_words].word, line);
        dictionary[num_words].count = 0;
        num_words++;
    }

    fclose(fp);

    // Get the text to check for spelling errors.
    char text[10000];
    printf("Enter the text to check for spelling errors:\n");
    fgets(text, 10000, stdin);

    // Convert the text to lowercase.
    for (int i = 0; i < strlen(text); i++) {
        text[i] = tolower(text[i]);
    }

    // Check the spelling of each word in the text.
    char *word_start = text;
    char *word_end;
    while ((word_end = strchr(word_start, ' ')) != NULL) {
        // Get the word.
        char word[MAX_WORD_LENGTH];
        strncpy(word, word_start, word_end - word_start);
        word[word_end - word_start] = '\0';

        // Check the spelling of the word.
        int found = 0;
        for (int i = 0; i < num_words; i++) {
            if (strcmp(word, dictionary[i].word) == 0) {
                found = 1;
                dictionary[i].count++;
                break;
            }
        }

        // If the word was not found in the dictionary, print it.
        if (!found) {
            printf("The word \"%s\" is not in the dictionary.\n", word);
        }

        // Move to the next word.
        word_start = word_end + 1;
    }

    // Get the last word in the text.
    char *last_word = strchr(word_start, '\0');
    if (last_word != NULL) {
        // Check the spelling of the last word.
        int found = 0;
        for (int i = 0; i < num_words; i++) {
            if (strcmp(word_start, dictionary[i].word) == 0) {
                found = 1;
                dictionary[i].count++;
                break;
            }
        }

        // If the last word was not found in the dictionary, print it.
        if (!found) {
            printf("The word \"%s\" is not in the dictionary.\n", word_start);
        }
    }

    // Print the number of times each word was found in the text.
    for (int i = 0; i < num_words; i++) {
        if (dictionary[i].count > 0) {
            printf("The word \"%s\" was found %d times in the text.\n", dictionary[i].word, dictionary[i].count);
        }
    }

    return 0;
}