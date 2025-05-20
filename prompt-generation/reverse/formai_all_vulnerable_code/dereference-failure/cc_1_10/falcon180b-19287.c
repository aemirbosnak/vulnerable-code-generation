//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void initializeWords(WordFrequency words[]) {
    for (int i = 0; i < MAX_WORDS; i++) {
        words[i].frequency = 0;
    }
}

void readTextFile(char* filename, WordFrequency words[]) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int length = strlen(word);
        if (length >= MAX_WORD_LENGTH) {
            printf("Warning: Word '%s' is too long and will be truncated.\n", word);
            length = MAX_WORD_LENGTH - 1;
        }
        for (int i = 0; i < length; i++) {
            word[i] = tolower(word[i]);
        }
        int index = hash(word);
        words[index].frequency++;
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

void printWordFrequencies(WordFrequency words[]) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].frequency > 0) {
            printf("%s : %d\n", words[i].word, words[i].frequency);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char filename[100];
    strcpy(filename, argv[1]);

    WordFrequency words[MAX_WORDS];
    initializeWords(words);

    readTextFile(filename, words);
    printWordFrequencies(words);

    return 0;
}