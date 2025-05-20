//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordEntry;

int findWord(WordEntry words[], int numWords, const char *word) {
    for (int i = 0; i < numWords; i++) {
        if (strcmp(words[i].word, word) == 0) {
            return i; // Found the word!
        }
    }
    return -1; // Word not found
}

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]); // Convert to lowercase
    }
}

void countWordsInFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Oops! Could not open file %s\n", filename);
        return;
    }

    WordEntry words[MAX_WORDS];
    int numWords = 0;

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) == 1) {
        toLowerCase(word); // Normalize to lowercase
        
        // Clean punctuation from the word!
        char *p = word;
        while (*p) {
            if (ispunct((unsigned char)*p)) {
                *p = '\0'; // Terminate the word on punctuation
                break;
            }
            p++;
        }

        if (*word) { // Check if the cleaned word is not empty
            int index = findWord(words, numWords, word);
            if (index >= 0) {
                // Word exists, increment its count!
                words[index].count++;
            } else {
                // New word, add to the list!
                strcpy(words[numWords].word, word);
                words[numWords].count = 1;
                numWords++;
            }
        }
    }

    fclose(file);

    // Sort the words by frequency in descending order
    for (int i = 0; i < numWords - 1; i++) {
        for (int j = 0; j < numWords - i - 1; j++) {
            if (words[j].count < words[j + 1].count) {
                // Swap the words
                WordEntry temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }

    // Print the word frequencies
    printf("\nWord Frequencies:\n");
    printf("-----------------\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    printf("Welcome to the Awesome Word Frequency Counter!\n");
    printf("===============================================\n");

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    countWordsInFile(argv[1]);
    
    printf("Thank you for using the Word Frequency Counter!\n");
    printf("===============================================\n");
    
    return 0;
}