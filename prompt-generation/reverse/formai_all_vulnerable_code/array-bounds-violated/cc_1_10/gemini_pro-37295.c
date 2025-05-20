//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN + 1];
    int count;
} Word;

int compareWords(const void *a, const void *b) {
    return strcmp(((Word *)a)->word, ((Word *)b)->word);
}

int main() {
    // Create an array of words
    Word words[MAX_WORDS];
    int numWords = 0;

    // Open the dictionary file
    FILE *dictFile = fopen("dictionary.txt", "r");
    if (dictFile == NULL) {
        printf("Error opening dictionary file!\n");
        return 1;
    }

    // Read the words from the dictionary file
    char line[MAX_WORD_LEN + 1];
    while (fgets(line, MAX_WORD_LEN + 1, dictFile) != NULL) {
        // Remove the newline character from the word
        line[strlen(line) - 1] = '\0';

        // Convert the word to lowercase
        for (int i = 0; line[i] != '\0'; i++) {
            line[i] = tolower(line[i]);
        }

        // Add the word to the array of words
        strcpy(words[numWords].word, line);
        words[numWords].count = 0;
        numWords++;
    }

    // Close the dictionary file
    fclose(dictFile);

    // Sort the array of words
    qsort(words, numWords, sizeof(Word), compareWords);

    // Open the text file
    FILE *textFile = fopen("text.txt", "r");
    if (textFile == NULL) {
        printf("Error opening text file!\n");
        return 1;
    }

    // Read the text from the text file
    char text[100000];
    while (fgets(text, 100000, textFile) != NULL) {
        // Remove the newline character from the text
        text[strlen(text) - 1] = '\0';

        // Tokenize the text into words
        char *token = strtok(text, " ");
        while (token != NULL) {
            // Convert the word to lowercase
            for (int i = 0; token[i] != '\0'; i++) {
                token[i] = tolower(token[i]);
            }

            // Search for the word in the array of words
            int index = bsearch(token, words, numWords, sizeof(Word), compareWords);

            // If the word is not found, add it to the array of words
            if (index == -1) {
                strcpy(words[numWords].word, token);
                words[numWords].count = 0;
                numWords++;
            }

            // Increment the count of the word
            words[index].count++;

            // Get the next token
            token = strtok(NULL, " ");
        }
    }

    // Close the text file
    fclose(textFile);

    // Print the misspelled words
    printf("Misspelled words:\n");
    for (int i = 0; i < numWords; i++) {
        if (words[i].count == 0) {
            printf("%s\n", words[i].word);
        }
    }

    return 0;
}