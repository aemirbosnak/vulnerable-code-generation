//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void readWords(char* filename, WordFrequency* wordFrequencies) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    int wordLength = 0;
    while (fscanf(file, "%s", word)!= EOF) {
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        wordLength = strlen(word);
        if (wordLength > 0 && wordLength <= MAX_WORD_LENGTH) {
            int index = hash(word);
            wordFrequencies[index].frequency++;
        }
    }

    fclose(file);
}

int hash(char* word) {
    int sum = 0;
    for (int i = 0; i < strlen(word); i++) {
        sum += word[i];
    }
    return sum % MAX_WORDS;
}

void printWordFrequencies(WordFrequency* wordFrequencies) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (wordFrequencies[i].frequency > 0) {
            printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
        }
    }
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    WordFrequency wordFrequencies[MAX_WORDS];
    readWords(filename, wordFrequencies);
    printWordFrequencies(wordFrequencies);

    return 0;
}