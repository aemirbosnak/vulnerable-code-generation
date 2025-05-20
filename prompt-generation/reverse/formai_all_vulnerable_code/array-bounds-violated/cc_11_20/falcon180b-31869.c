//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int main() {
    char line[1000];
    Word words[MAX_WORDS];
    int numWords = 0;
    int i, j;

    printf("Enter text:\n");
    fgets(line, sizeof(line), stdin);

    // Remove trailing newline character
    if (line[strlen(line) - 1] == '\n') {
        line[strlen(line) - 1] = '\0';
    }

    // Tokenize input into words
    char* token = strtok(line, ",.?!;:");
    while (token) {
        if (numWords >= MAX_WORDS) {
            printf("Error: too many words.\n");
            return 1;
        }

        // Convert to lowercase and remove non-alphabetic characters
        char* word = malloc(MAX_WORD_LENGTH);
        strcpy(word, token);
        int len = strlen(word);
        for (i = 0; i < len; i++) {
            if (!isalpha(word[i])) {
                word[i] = '\0';
                len = i;
                break;
            }
        }

        // Check if word is already in array
        for (i = 0; i < numWords; i++) {
            if (strcmp(words[i].word, word) == 0) {
                words[i].count++;
                free(word);
                break;
            }
        }

        // Add new word to array
        if (i == numWords) {
            strcpy(words[numWords].word, word);
            words[numWords].count = 1;
            numWords++;
        }

        token = strtok(NULL, ",.?!;:");
    }

    // Sort words by frequency
    for (i = 0; i < numWords - 1; i++) {
        for (j = i + 1; j < numWords; j++) {
            if (words[j].count > words[i].count) {
                Word temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    // Print word count
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}