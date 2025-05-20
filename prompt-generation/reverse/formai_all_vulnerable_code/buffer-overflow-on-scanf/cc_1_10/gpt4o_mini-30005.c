//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int isWordCharacter(char ch) {
    return isalpha(ch) || ch == '-';
}

int findWordIndex(WordFrequency *words, int count, const char *word) {
    for (int i = 0; i < count; i++) {
        if (strcmp(words[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

void addWord(WordFrequency *words, int *count, const char *word) {
    int index = findWordIndex(words, *count, word);
    if (index == -1) {
        if (*count < MAX_WORDS) {
            strcpy(words[*count].word, word);
            words[*count].frequency = 1;
            (*count)++;
        }
    } else {
        words[index].frequency++;
    }
}

void printWordFrequencies(WordFrequency *words, int count) {
    printf("Word Frequencies:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

void cleanUp(WordFrequency *words) {
    free(words);
}

int main() {
    WordFrequency *words = malloc(sizeof(WordFrequency) * MAX_WORDS);
    if (words == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    int wordCount = 0;
    char buffer[MAX_WORD_LENGTH];
    
    printf("Enter text (Ctrl+D to end input):\n");
    
    while (scanf("%s", buffer) != EOF) {
        // Clean buffer to extract only word characters
        char cleanedBuffer[MAX_WORD_LENGTH];
        int index = 0;
        for (int i = 0; buffer[i]; i++) {
            if (isWordCharacter(buffer[i])) {
                cleanedBuffer[index++] = buffer[i];
            }
        }
        cleanedBuffer[index] = '\0';

        if (index > 0) {
            toLowerCase(cleanedBuffer);
            addWord(words, &wordCount, cleanedBuffer);
        }
    }

    printWordFrequencies(words, wordCount);
    cleanUp(words);

    return EXIT_SUCCESS;
}