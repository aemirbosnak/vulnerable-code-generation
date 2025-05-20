//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_WORDS 10000
#define MAX_CHARS_PER_WORD 50
#define MIN_WORD_LENGTH 3

typedef struct {
    char word[MAX_CHARS_PER_WORD];
    int count;
} WordCount;

void readWordsFromFile(const char* filename, WordCount words[], int maxWords) {
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    int numWords = 0;
    char word[MAX_CHARS_PER_WORD];

    while (fscanf(file, "%s", word)!= EOF) {
        if (strlen(word) >= MIN_WORD_LENGTH) {
            if (numWords >= maxWords) {
                printf("Warning: reached maximum number of words (%d)\n", maxWords);
                break;
            }

            for (int i = 0; i < strlen(word); i++) {
                word[i] = tolower(word[i]);
            }

            int found = 0;
            for (int i = 0; i < numWords; i++) {
                if (strcmp(words[i].word, word) == 0) {
                    words[i].count++;
                    found = 1;
                    break;
                }
            }

            if (!found) {
                strcpy(words[numWords].word, word);
                words[numWords].count = 1;
                numWords++;
            }
        }
    }

    fclose(file);
}

void printWords(WordCount words[], int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    WordCount words[MAX_WORDS];
    int numWords = 0;

    readWordsFromFile(filename, words, MAX_WORDS);

    printf("Word count:\n");
    printWords(words, numWords);

    return 0;
}