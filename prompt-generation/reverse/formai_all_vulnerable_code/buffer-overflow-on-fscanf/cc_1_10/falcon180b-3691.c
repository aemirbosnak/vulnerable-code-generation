//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wordA = (WordCount*)a;
    WordCount *wordB = (WordCount*)b;
    return strcmp(wordA->word, wordB->word);
}

int main() {
    char input[MAX_WORD_LENGTH];
    char fileName[MAX_WORD_LENGTH];
    WordCount words[MAX_WORDS];
    int numWords = 0;
    FILE *file;
    int i;

    // Get filename from user
    printf("Enter filename: ");
    scanf("%s", fileName);

    // Open file for reading
    file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Read words from file and count occurrences
    while ((fscanf(file, "%s", input))!= EOF) {
        for (i = 0; i < numWords; i++) {
            if (strcmp(input, words[i].word) == 0) {
                // Word already exists, increment count
                words[i].count++;
                break;
            }
        }
        if (i == numWords) {
            // New word, add to array
            strcpy(words[numWords].word, input);
            words[numWords].count = 1;
            numWords++;
            if (numWords == MAX_WORDS) {
                printf("Error: Maximum number of words reached.\n");
                fclose(file);
                return 1;
            }
        }
    }

    // Sort words alphabetically
    qsort(words, numWords, sizeof(WordCount), compareWords);

    // Print word count
    printf("Word count:\n");
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    // Close file
    fclose(file);
    return 0;
}