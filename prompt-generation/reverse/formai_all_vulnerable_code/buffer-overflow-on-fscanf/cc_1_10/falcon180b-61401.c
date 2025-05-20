//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void readWords(FILE *file, WordFrequency words[]) {
    char word[MAX_WORD_LENGTH];
    int i = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Error: Too many words.\n");
            exit(1);
        }

        strcpy(words[i].word, word);
        words[i].count = 1;
        i++;
    }
}

void countWords(WordFrequency words[], int numWords) {
    for (int i = 0; i < numWords; i++) {
        for (int j = i + 1; j < numWords; j++) {
            if (strcmp(words[i].word, words[j].word) == 0) {
                words[i].count += words[j].count;
                words[j].word[0] = '\0';
            }
        }
    }
}

void printWords(WordFrequency words[], int numWords) {
    for (int i = 0; i < numWords; i++) {
        if (words[i].word[0]!= '\0') {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    FILE *file;
    char filename[MAX_WORD_LENGTH];
    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    printf("Enter the name of the text file: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    readWords(file, words);
    countWords(words, numWords);
    printWords(words, numWords);

    fclose(file);

    return 0;
}