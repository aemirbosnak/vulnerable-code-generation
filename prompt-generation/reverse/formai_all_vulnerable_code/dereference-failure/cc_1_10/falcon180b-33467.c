//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void addWord(char* sentence, int length, WordFrequency* wordFrequency, int numWords) {
    if (length > 0 && isalpha(sentence[0])) {
        char word[MAX_WORD_LENGTH];
        int i = 0;
        while (isalpha(sentence[i]) && i < length) {
            word[i] = tolower(sentence[i]);
            i++;
        }
        word[i] = '\0';

        for (int j = 0; j < numWords; j++) {
            if (strcmp(word, wordFrequency[j].word) == 0) {
                wordFrequency[j].frequency++;
                return;
            }
        }

        if (numWords >= MAX_WORDS) {
            printf("Error: Maximum number of words reached.\n");
            exit(1);
        }

        strcpy(wordFrequency[numWords].word, word);
        wordFrequency[numWords].frequency = 1;
        numWords++;
    }
}

void printWordFrequency(WordFrequency* wordFrequency, int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequency[i].word, wordFrequency[i].frequency);
    }
}

int main() {
    FILE* file;
    char* sentence;
    size_t len = 0;
    ssize_t read;
    WordFrequency wordFrequency[MAX_WORDS];
    int numWords = 0;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    while ((read = getline(&sentence, &len, file))!= -1) {
        addWord(sentence, read, wordFrequency, numWords);
    }

    printWordFrequency(wordFrequency, numWords);

    free(sentence);
    fclose(file);

    return 0;
}