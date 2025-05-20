//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000
#define DICTIONARY_SIZE 10000
#define MAX_LINE_LENGTH 256

// Function prototypes
void loadDictionary(const char *filename, char dictionary[][MAX_WORD_LENGTH], int *dictSize);
int spellCheckWord(const char *word, char dictionary[][MAX_WORD_LENGTH], int dictSize);
void loadTextFile(const char *filename, char lines[][MAX_LINE_LENGTH], int *lineCount);
void checkSpelling(char lines[][MAX_LINE_LENGTH], int lineCount, char dictionary[][MAX_WORD_LENGTH], int dictSize);
void suggestCorrections(const char *word, char dictionary[][MAX_WORD_LENGTH], int dictSize);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return 1;
    }

    char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH];
    int dictSize = 0;
    loadDictionary(argv[1], dictionary, &dictSize);

    char lines[MAX_WORDS][MAX_LINE_LENGTH];
    int lineCount = 0;
    loadTextFile(argv[2], lines, &lineCount);

    checkSpelling(lines, lineCount, dictionary, dictSize);

    return 0;
}

void loadDictionary(const char *filename, char dictionary[][MAX_WORD_LENGTH], int *dictSize) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open dictionary file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s", dictionary[*dictSize]) != EOF) {
        (*dictSize)++;
        if (*dictSize >= DICTIONARY_SIZE) break;
    }

    fclose(file);
}

void loadTextFile(const char *filename, char lines[][MAX_LINE_LENGTH], int *lineCount) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open text file");
        exit(EXIT_FAILURE);
    }

    while (fgets(lines[*lineCount], MAX_LINE_LENGTH, file)) {
        (*lineCount)++;
        if (*lineCount >= MAX_WORDS) break;
    }

    fclose(file);
}

int spellCheckWord(const char *word, char dictionary[][MAX_WORD_LENGTH], int dictSize) {
    for (int i = 0; i < dictSize; i++) {
        if (strcasecmp(word, dictionary[i]) == 0) {
            return 1; // Word found in the dictionary
        }
    }
    return 0; // Word not found
}

void suggestCorrections(const char *word, char dictionary[][MAX_WORD_LENGTH], int dictSize) {
    printf("Suggestions for '%s':\n", word);
    for (int i = 0; i < dictSize; i++) {
        // Check for similarity with the given threshold (here, length difference)
        if (abs((int)strlen(word) - (int)strlen(dictionary[i])) <= 1) {
            printf(" - %s\n", dictionary[i]);
        }
    }
}

void checkSpelling(char lines[][MAX_LINE_LENGTH], int lineCount, char dictionary[][MAX_WORD_LENGTH], int dictSize) {
    for (int i = 0; i < lineCount; i++) {
        char *word = strtok(lines[i], " \n");
        while (word) {
            if (!spellCheckWord(word, dictionary, dictSize)) {
                printf("Misspelled word: '%s' in line %d\n", word, i + 1);
                suggestCorrections(word, dictionary, dictSize);
            }
            word = strtok(NULL, " \n");
        }
    }
}