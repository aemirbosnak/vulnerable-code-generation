//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

Word wordList[MAX_WORDS];
int totalWords = 0;

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int findWord(const char *word) {
    for (int i = 0; i < totalWords; i++) {
        if (strcmp(wordList[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

void addWord(const char *word) {
    int index = findWord(word);
    if (index != -1) {
        wordList[index].count++;
    } else {
        if (totalWords < MAX_WORDS) {
            strcpy(wordList[totalWords].word, word);
            wordList[totalWords].count = 1;
            totalWords++;
        }
    }
}

void processText(FILE *file) {
    char buffer[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", buffer) != EOF) {
        toLowerCase(buffer);
        // Remove punctuation from the word
        char cleaned[MAX_WORD_LENGTH];
        int j = 0;
        for (int i = 0; buffer[i]; i++) {
            if (isalpha((unsigned char)buffer[i])) {
                cleaned[j++] = buffer[i];
            }
        }
        cleaned[j] = '\0';
        if (j > 0) {
            addWord(cleaned);
        }
    }
}

void printWordFrequencies() {
    printf("Word Frequencies:\n");
    for (int i = 0; i < totalWords; i++) {
        printf("%s: %d\n", wordList[i].word, wordList[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    processText(file);
    fclose(file);

    printWordFrequencies();
    return 0;
}