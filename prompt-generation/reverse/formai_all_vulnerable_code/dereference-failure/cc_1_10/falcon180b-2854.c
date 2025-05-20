//Falcon-180B DATASET v1.0 Category: Text processing ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *) a;
    WordFrequency *wordB = (WordFrequency *) b;

    return strcmp(wordA->word, wordB->word);
}

void readFile(FILE *file, char *buffer, int bufferSize) {
    int ch;
    int index = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (index >= bufferSize - 1) {
            printf("Buffer overflow\n");
            exit(1);
        }

        buffer[index++] = ch;
    }

    buffer[index] = '\0';
}

void processWords(char *text, WordFrequency *wordFrequencies, int numWords) {
    char *token;
    char *saveptr;
    int i;

    token = strtok_r(text, ",.!?;:\"'()[]{}<>", &saveptr);

    while (token!= NULL) {
        for (i = 0; i < numWords; i++) {
            if (strcmp(token, wordFrequencies[i].word) == 0) {
                wordFrequencies[i].frequency++;
                break;
            }
        }

        if (i == numWords) {
            if (numWords >= MAX_WORDS) {
                printf("Maximum number of words reached\n");
                exit(1);
            }

            strcpy(wordFrequencies[numWords].word, token);
            wordFrequencies[numWords].frequency = 1;
            numWords++;
        }

        token = strtok_r(NULL, ",.!?;:\"'()[]{}<>", &saveptr);
    }
}

void sortWords(WordFrequency *wordFrequencies, int numWords) {
    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);
}

void printWords(WordFrequency *wordFrequencies, int numWords) {
    int i;

    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }
}

int main() {
    FILE *file;
    char buffer[1024];
    WordFrequency wordFrequencies[MAX_WORDS];
    int numWords = 0;

    file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    readFile(file, buffer, sizeof(buffer));
    fclose(file);

    processWords(buffer, wordFrequencies, numWords);
    sortWords(wordFrequencies, numWords);
    printWords(wordFrequencies, numWords);

    return 0;
}