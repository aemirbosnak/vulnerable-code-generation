//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_FILE_NAME_LENGTH 256

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

typedef struct {
    WordCount words[26];
} WordFrequency;

void InitializeWordFrequency(WordFrequency *wordFrequency) {
    for (int i = 0; i < 26; i++) {
        wordFrequency->words[i].count = 0;
        strcpy(wordFrequency->words[i].word, "");
    }
}

void UpdateWordFrequency(WordFrequency *wordFrequency, char *word) {
    char lowerCaseWord[MAX_WORD_LENGTH];
    strcpy(lowerCaseWord, word);
    for (int i = 0; i < strlen(lowerCaseWord); i++) {
        lowerCaseWord[i] = tolower(lowerCaseWord[i]);
    }
    int wordIndex = tolower(lowerCaseWord[0]) - 'a';
    wordFrequency->words[wordIndex].count++;
}

void PrintWordFrequency(WordFrequency *wordFrequency) {
    printf("Word\tFrequency\n");
    for (int i = 0; i < 26; i++) {
        if (wordFrequency->words[i].count > 0) {
            printf("%s\t%d\n", wordFrequency->words[i].word, wordFrequency->words[i].count);
        }
    }
}

void CountWordsInFile(FILE *file, WordFrequency *wordFrequency) {
    char word[MAX_WORD_LENGTH];
    char lowerCaseWord[MAX_WORD_LENGTH];
    int wordIndex;
    while (fscanf(file, "%s", word)!= EOF) {
        strcpy(lowerCaseWord, word);
        for (int i = 0; i < strlen(lowerCaseWord); i++) {
            lowerCaseWord[i] = tolower(lowerCaseWord[i]);
        }
        wordIndex = tolower(lowerCaseWord[0]) - 'a';
        UpdateWordFrequency(wordFrequency, lowerCaseWord);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }
    char fileName[MAX_FILE_NAME_LENGTH];
    strcpy(fileName, argv[1]);
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", fileName);
        return 1;
    }
    WordFrequency wordFrequency;
    InitializeWordFrequency(&wordFrequency);
    CountWordsInFile(file, &wordFrequency);
    fclose(file);
    PrintWordFrequency(&wordFrequency);
    return 0;
}