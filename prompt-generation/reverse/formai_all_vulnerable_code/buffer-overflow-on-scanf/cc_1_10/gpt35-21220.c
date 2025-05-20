//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 30
#define MAX_WORDS_COUNT 20000

// A structure to hold a word and its frequency
typedef struct wordCount {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int getWordCount(FILE* inputFile);
void getWords(FILE* inputFile, WordCount* words, int wordsCount);
void printWords(WordCount* words, int wordsCount);
void sortWords(WordCount* words, int wordsCount);

int main() {
    char fileName[50];
    int wordsCount;

    printf("Please enter the name of the file to process: ");
    scanf("%s", fileName);

    FILE* inputFile = fopen(fileName, "r");
    if (inputFile == NULL) {
        printf("Error opening the file %s\n", fileName);
        return 1;
    }
    
    wordsCount = getWordCount(inputFile);
    if (wordsCount == 0) {
        printf("No words found in file %s\n", fileName);
        return 1;
    }

    rewind(inputFile);

    WordCount* words = (WordCount*) malloc(wordsCount * sizeof(WordCount));
    if (words == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }

    getWords(inputFile, words, wordsCount);

    fclose(inputFile);

    sortWords(words, wordsCount);

    printWords(words, wordsCount);

    free(words);

    printf("Program finished successfully!\n");

    return 0;
}

// Count the number of words inside the file
int getWordCount(FILE* inputFile) {
    int wordsCount = 0;
    char ch;

    while ((ch = fgetc(inputFile)) != EOF) {
        if (ch == ' ' || ch == '\n' || ch == '\t') {
            wordsCount++;
        }
    }

    return wordsCount;
}

// Read all the words inside the file and fill an array of WordCount structures
void getWords(FILE* inputFile, WordCount* words, int wordsCount) {
    int i, j, wordIndex;
    char word[MAX_WORD_LEN] = "";

    wordIndex = 0;

    while (fscanf(inputFile, "%s", word) != EOF) {
        // Remove punctuation from the word
        for (i = 0, j = 0; i < strlen(word); i++) {
            if (ispunct(word[i]) == 0) {
                word[j++] = tolower(word[i]);
            }
        }
        word[j] = '\0';

        // Check if the word is already in the words array
        for (i = 0; i < wordIndex; i++) {
            if (strcmp(words[i].word, word) == 0) {
                words[i].count++;
                break;
            }
        }

        // If the word is not in the array, add it
        if (i == wordIndex) {
            strncpy(words[i].word, word, sizeof(words[i].word));
            words[i].count = 1;
            wordIndex++;
        }

        if (wordIndex == wordsCount) {
            break;
        }
    }
}

// Print the words and their frequencies
void printWords(WordCount* words, int wordsCount) {
    int i;

    printf("\n-------------------------\n");
    printf("| %-20s| %10s |\n", "Word", "Frequency");
    printf("-------------------------\n");

    for (i = 0; i < wordsCount; i++) {
        printf("| %-20s| %10d |\n", words[i].word, words[i].count);
    }
    printf("-------------------------\n");
}

// Sort the words array in descending order based on their frequency
void sortWords(WordCount* words, int wordsCount) {
    int i, j;
    WordCount tempWord;

    for (i = 0; i < wordsCount - 1; i++) {
        for (j = 0; j < wordsCount - i - 1; j++) {
            if (words[j].count < words[j + 1].count) {
                tempWord = words[j];
                words[j] = words[j + 1];
                words[j + 1] = tempWord;
            }
        }
    }
}