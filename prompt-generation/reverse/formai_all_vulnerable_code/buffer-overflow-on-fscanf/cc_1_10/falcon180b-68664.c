//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUMBER_OF_WORDS 100

// Structure to represent a word
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

// Function to compare two words
int compareWords(const void* a, const void* b) {
    const Word* wordA = (const Word*)a;
    const Word* wordB = (const Word*)b;

    return strcmp(wordA->word, wordB->word);
}

// Function to read words from a file
void readWordsFromFile(FILE* file, Word* words) {
    char word[MAX_WORD_LENGTH];
    int numberOfWords = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (numberOfWords >= MAX_NUMBER_OF_WORDS) {
            break;
        }

        for (int i = 0; i < strlen(word); i++) {
            if (!isalpha(word[i])) {
                word[i] = '\0';
            }
        }

        strcpy(words[numberOfWords].word, word);
        words[numberOfWords].count = 1;

        numberOfWords++;
    }
}

// Function to count the frequency of words in a file
void countWordsFrequency(Word* words, int numberOfWords) {
    for (int i = 0; i < numberOfWords; i++) {
        for (int j = i + 1; j < numberOfWords; j++) {
            if (strcmp(words[i].word, words[j].word) == 0) {
                words[i].count += words[j].count;
                words[j].count = 0;
            }
        }
    }
}

// Function to display the frequency of words in a file
void displayWordsFrequency(Word* words, int numberOfWords) {
    qsort(words, numberOfWords, sizeof(Word), compareWords);

    for (int i = 0; i < numberOfWords; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    FILE* file = fopen("example.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    Word words[MAX_NUMBER_OF_WORDS];
    int numberOfWords = 0;

    readWordsFromFile(file, words);
    countWordsFrequency(words, numberOfWords);
    displayWordsFrequency(words, numberOfWords);

    fclose(file);

    return 0;
}