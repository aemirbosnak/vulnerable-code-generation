//Falcon-180B DATASET v1.0 Category: Data mining ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void readTextFile(FILE* file, WordFrequency* wordFrequencies) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(wordFrequencies[i].word, word) == 0) {
                wordFrequencies[i].frequency++;
                break;
            }
        }
        if (i == MAX_WORDS) {
            printf("Reached maximum number of words.\n");
            break;
        }
    }
}

void printWordFrequencies(WordFrequency* wordFrequencies) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (wordFrequencies[i].frequency > 0) {
            printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
        }
    }
}

int main() {
    FILE* file;
    WordFrequency wordFrequencies[MAX_WORDS];

    file = fopen("text_file.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    readTextFile(file, wordFrequencies);

    printWordFrequencies(wordFrequencies);

    fclose(file);

    return 0;
}