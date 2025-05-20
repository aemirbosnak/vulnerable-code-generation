//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: shocked
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_UNIQUE_WORDS 10000

int uniqueWordCount = 0;
char words[MAX_NUM_UNIQUE_WORDS][MAX_WORD_LENGTH + 1];
int frequencies[MAX_NUM_UNIQUE_WORDS] = {0};

bool isSeparator(char c) {
    return isspace(c) || ispunct(c);
}

bool isNewWord(char *previousChar, char *currentChar) {
    return isSeparator(*previousChar) && !isSeparator(*currentChar);
}

int indexOfWord(char *word) {
    for (int i = 0; i < uniqueWordCount; i++) {
        if (strcmp(words[i], word) == 0) {
            return i;
        }
    }
    return -1;
}

void addWord(char *word) {
    int index = indexOfWord(word);
    if (index == -1) {
        strcpy(words[uniqueWordCount], word);
        frequencies[uniqueWordCount]++;
        uniqueWordCount++;
    } else {
        frequencies[index]++;
    }
}

void processFile(FILE *file) {
    char previousChar = '\0';
    char currentChar = '\0';
    char currentWord[MAX_WORD_LENGTH + 1];
    memset(currentWord, 0, MAX_WORD_LENGTH + 1);

    while ((currentChar = fgetc(file)) != EOF) {
        if (isNewWord(&previousChar, &currentChar)) {
            addWord(currentWord);
            memset(currentWord, 0, MAX_WORD_LENGTH + 1);
        }
        if (!isSeparator(currentChar)) {
            strncat(currentWord, &currentChar, 1);
        }
        previousChar = currentChar;
    }
}

void printFrequencies() {
    printf("Total number of unique words: %d\n", uniqueWordCount);
    printf("Word frequencies:\n");
    for (int i = 0; i < uniqueWordCount; i++) {
        printf("%s: %d\n", words[i], frequencies[i]);
    }
}

int main() {
    char filePath[MAX_WORD_LENGTH + 1];
    printf("Enter file path: ");
    scanf("%s", filePath);

    FILE *file = fopen(filePath, "r");
    if (file == NULL) {
        printf("Failed to open file\n");
        return 1;
    }

    processFile(file);
    fclose(file);

    printFrequencies();

    return 0;
}