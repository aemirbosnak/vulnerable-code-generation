//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void toLower(char str[]) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int isWordCharacter(char c) {
    return isalpha(c) || c == '\''; // Allow apostrophes for possessives
}

int addWord(WordFrequency words[], int totalWords, const char *newWord) {
    for (int i = 0; i < totalWords; i++) {
        if (strcmp(words[i].word, newWord) == 0) {
            words[i].count++;
            return totalWords;
        }
    }
    // If it is a new word, add it to the list.
    strcpy(words[totalWords].word, newWord);
    words[totalWords].count = 1;
    return totalWords + 1;
}

void printWordFrequencies(WordFrequency words[], int totalWords) {
    printf("\nWord Frequency Analysis - A Case for Sherlock Holmes:\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < totalWords; i++) {
        printf("%-15s : %d\n", words[i].word, words[i].count);
    }
}

void analyzeText(FILE *file) {
    WordFrequency words[MAX_WORDS];
    int totalWords = 0;
    char buffer[MAX_WORD_LENGTH];

    while (fscanf(file, "%s", buffer) != EOF) {
        // Clean and validate the word
        char cleanWord[MAX_WORD_LENGTH];
        int index = 0;
        for (int i = 0; buffer[i] != '\0'; i++) {
            if (isWordCharacter(buffer[i])) {
                cleanWord[index++] = buffer[i];
            } else {
                // If the word contains invalid characters, ignore it
                break;
            }
        }
        cleanWord[index] = '\0';

        if (strlen(cleanWord) > 0) {
            toLower(cleanWord);
            totalWords = addWord(words, totalWords, cleanWord);
        }
    }

    printWordFrequencies(words, totalWords);
}

int main() {
    FILE *file = fopen("mystery.txt", "r");
    if (file == NULL) {
        printf("Ah, the game is afoot! However, I cannot find the text file 'mystery.txt'. \n");
        return 1;
    }

    analyzeText(file);
    fclose(file);

    return 0;
}