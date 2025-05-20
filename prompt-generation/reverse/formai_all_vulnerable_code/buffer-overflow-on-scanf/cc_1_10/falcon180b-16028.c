//Falcon-180B DATASET v1.0 Category: Data mining ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void readFile(char* filename, WordFrequency* wordFrequencies) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        int index = hash(word);
        if (wordFrequencies[index].word[0] == '\0') {
            strcpy(wordFrequencies[index].word, word);
            wordFrequencies[index].frequency = 1;
        } else if (strcmp(wordFrequencies[index].word, word) == 0) {
            wordFrequencies[index].frequency++;
        }
    }

    fclose(file);
}

int hash(char* word) {
    int hashValue = 0;
    for (int i = 0; i < strlen(word); i++) {
        hashValue += word[i];
    }
    return hashValue % MAX_WORDS;
}

void printWordFrequencies(WordFrequency* wordFrequencies) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (wordFrequencies[i].word[0]!= '\0') {
            printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
        }
    }
}

int main() {
    char inputFilename[MAX_WORD_LENGTH];
    printf("Enter the name of the input file: ");
    scanf("%s", inputFilename);

    WordFrequency wordFrequencies[MAX_WORDS];
    readFile(inputFilename, wordFrequencies);

    printf("\nWord frequencies:\n");
    printWordFrequencies(wordFrequencies);

    return 0;
}