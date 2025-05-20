//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_LENGTH 100

typedef struct {
    char word[MAX_LENGTH];
    int count;
} WordEntry;

WordEntry wordList[MAX_WORDS];
int uniqueWords = 0;

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int addWord(char *word) {
    for (int i = 0; i < uniqueWords; i++) {
        if (strcmp(wordList[i].word, word) == 0) {
            wordList[i].count++;
            return 1;
        }
    }
    if (uniqueWords < MAX_WORDS) {
        strcpy(wordList[uniqueWords].word, word);
        wordList[uniqueWords].count = 1;
        uniqueWords++;
        return 1;
    }
    return 0;
}

void readFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }
    
    char buffer[MAX_LENGTH];
    while (fscanf(file, "%s", buffer) != EOF) {
        // Remove punctuation
        for (int i = 0; buffer[i]; i++) {
            if (ispunct(buffer[i])) {
                buffer[i] = '\0';
            }
        }
        toLowerCase(buffer);
        if (strlen(buffer) > 0) {
            addWord(buffer);
        }
    }
    fclose(file);
}

void sortWords() {
    for (int i = 0; i < uniqueWords - 1; i++) {
        for (int j = i + 1; j < uniqueWords; j++) {
            if (wordList[i].count < wordList[j].count) {
                WordEntry temp = wordList[i];
                wordList[i] = wordList[j];
                wordList[j] = temp;
            }
        }
    }
}

void printWordCount() {
    printf("Word Frequency:\n");
    for (int i = 0; i < uniqueWords; i++) {
        printf("%s: %d\n", wordList[i].word, wordList[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    readFile(argv[1]);
    sortWords();
    printWordCount();
    
    return EXIT_SUCCESS;
}