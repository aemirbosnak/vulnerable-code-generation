//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

// Structure to hold word and its frequency
typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

// Function declarations
void readFileAndProcess(const char *filename);
void countWordsAndLines(const char *filename);
void displayWordFrequency(WordFrequency wordList[], int wordCount);
int compareFrequency(const void *a, const void *b);

int main() {
    char filename[100];
    int choice;

    while (1) {
        printf("Text Processing Program\n");
        printf("1. Count words, lines, and characters\n");
        printf("2. Find word frequency\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter the filename: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove new line character
                countWordsAndLines(filename);
                break;
            case 2:
                printf("Enter the filename: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove new line character
                readFileAndProcess(filename);
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void countWordsAndLines(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file %s for reading.\n", filename);
        return;
    }

    char ch;
    int lines = 0, words = 0, characters = 0;
    int inWord = 0;

    while ((ch = fgetc(file)) != EOF) {
        characters++;
        if (ch == '\n') lines++;
        if (isspace(ch)) {
            if (inWord) {
                words++;
                inWord = 0;
            }
        } else {
            inWord = 1;
        }
    }
    // Check for the last word
    if (inWord) words++;

    fclose(file);
    printf("Lines: %d\nWords: %d\nCharacters: %d\n", lines + 1, words, characters);
}

void readFileAndProcess(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file %s for reading.\n", filename);
        return;
    }

    WordFrequency wordList[MAX_WORDS];
    int wordCount = 0;

    char currentWord[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", currentWord) != EOF) {
        // Convert word to lowercase
        for (int i = 0; currentWord[i]; i++) {
            currentWord[i] = tolower(currentWord[i]);
        }

        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(wordList[i].word, currentWord) == 0) {
                wordList[i].frequency++;
                found = 1;
                break;
            }
        }
        if (!found && wordCount < MAX_WORDS) {
            strcpy(wordList[wordCount].word, currentWord);
            wordList[wordCount].frequency = 1;
            wordCount++;
        }
    }
    fclose(file);

    qsort(wordList, wordCount, sizeof(WordFrequency), compareFrequency);
    displayWordFrequency(wordList, wordCount);
}

void displayWordFrequency(WordFrequency wordList[], int wordCount) {
    printf("Word Frequencies:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordList[i].word, wordList[i].frequency);
    }
}

int compareFrequency(const void *a, const void *b) {
    return ((WordFrequency *)b)->frequency - ((WordFrequency *)a)->frequency;
}