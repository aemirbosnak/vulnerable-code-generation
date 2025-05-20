//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: Donald Knuth
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

void toLowerCase(char *str);
int addWord(WordFrequency *words, int *size, const char *word);
void sortWords(WordFrequency *words, int size);
void printFrequencies(WordFrequency *words, int size);

int main(void) {
    WordFrequency words[MAX_WORDS] = {{0}};
    char buffer[MAX_WORD_LENGTH];
    int size = 0;

    printf("Enter text (CTRL+D to end input):\n");
    
    while (scanf("%s", buffer) != EOF) {
        toLowerCase(buffer);
        if (addWord(words, &size, buffer) == -1) {
            fprintf(stderr, "Error adding word: %s\n", buffer);
            return 1;
        }
    }

    sortWords(words, size);
    printFrequencies(words, size);
    
    return 0;
}

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char) str[i]);
    }
}

int addWord(WordFrequency *words, int *size, const char *word) {
    for (int i = 0; i < *size; i++) {
        if (strcmp(words[i].word, word) == 0) {
            words[i].count++;
            return 0;
        }
    }

    if (*size >= MAX_WORDS) {
        return -1; // No space left to add more words
    }

    strcpy(words[*size].word, word);
    words[*size].count = 1;
    (*size)++;
    return 0;
}

void sortWords(WordFrequency *words, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (words[j].count < words[j + 1].count) {
                WordFrequency temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
}

void printFrequencies(WordFrequency *words, int size) {
    printf("\nWord Frequencies:\n");
    for (int i = 0; i < size; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}