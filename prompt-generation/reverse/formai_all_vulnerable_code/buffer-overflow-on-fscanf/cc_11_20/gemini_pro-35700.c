//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int count;
} Word;

int main() {
    FILE *fp;
    char *filename = "dictionary.txt";
    char word[MAX_WORD_LENGTH + 1];
    Word dictionary[MAX_WORDS];
    int num_words = 0;

    // Open the dictionary file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening dictionary file %s\n", filename);
        return -1;
    }

    // Read the words from the dictionary file
    while (fscanf(fp, "%s\n", word) != EOF) {
        // Convert the word to lowercase
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        // Add the word to the dictionary
        strcpy(dictionary[num_words].word, word);
        dictionary[num_words].count = 0;
        num_words++;
    }

    // Close the dictionary file
    fclose(fp);

    // Get the text to check for spelling errors
    printf("Enter the text to check for spelling errors:\n");
    fgets(word, sizeof(word), stdin);

    // Convert the text to lowercase
    for (int i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }

    // Check the spelling of the words in the text
    char *start = word;
    char *end = word;
    while (*end != '\0') {
        // Find the next word
        while (*end != ' ' && *end != '\0') {
            end++;
        }

        // Check the spelling of the word
        char word[MAX_WORD_LENGTH + 1];
        strncpy(word, start, end - start);
        word[end - start] = '\0';

        int found = 0;
        for (int i = 0; i < num_words; i++) {
            if (strcmp(word, dictionary[i].word) == 0) {
                found = 1;
                break;
            }
        }

        // Print an error message if the word is not found
        if (!found) {
            printf("The word '%s' is not in the dictionary.\n", word);
        }

        // Move to the next word
        start = end + 1;
        end = start;
    }

    return 0;
}