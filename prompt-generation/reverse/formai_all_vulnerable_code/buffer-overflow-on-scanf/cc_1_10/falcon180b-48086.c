//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS_PER_LINE 10
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency[MAX_WORDS_PER_LINE];
} WordFrequency;

void loadWords(char *filename, WordFrequency *wordFrequency) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    int frequency[MAX_WORDS_PER_LINE];
    int i = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        for (int j = 0; j < MAX_WORDS_PER_LINE; j++) {
            frequency[j] = 0;
        }
        strcpy(wordFrequency[i].word, word);
        wordFrequency[i].frequency[0] = 1;
        i++;
    }

    fclose(file);
}

void printWords(WordFrequency *wordFrequency) {
    for (int i = 0; i < MAX_WORDS_PER_LINE; i++) {
        if (wordFrequency[i].frequency[0] > 0) {
            printf("%s %d\n", wordFrequency[i].word, wordFrequency[i].frequency[0]);
        }
    }
}

int main() {
    char filename[100];
    printf("Enter the name of the file: ");
    scanf("%s", filename);

    WordFrequency wordFrequency[MAX_WORDS_PER_LINE];

    loadWords(filename, wordFrequency);

    printf("The word frequency is:\n");
    printWords(wordFrequency);

    return 0;
}