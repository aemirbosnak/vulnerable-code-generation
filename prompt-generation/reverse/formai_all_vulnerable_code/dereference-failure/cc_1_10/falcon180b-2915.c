//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: decentralized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void addWord(char* word) {
    FILE* file = fopen("dictionary.txt", "a");
    if (file == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }
    fprintf(file, "%s\n", word);
    fclose(file);
}

int compareWords(const void* a, const void* b) {
    const WordFrequency* w1 = (const WordFrequency*)a;
    const WordFrequency* w2 = (const WordFrequency*)b;
    return strcmp(w1->word, w2->word);
}

void countWords(char* text) {
    char word[MAX_WORD_LENGTH];
    int i = 0;
    while (i < strlen(text)) {
        if (isalpha(text[i])) {
            strcpy(word, "");
            while (isalpha(text[i])) {
                strcat(word, tolower(text[i]));
                i++;
            }
            addWord(word);
        } else {
            i++;
        }
    }
}

void printWords(FILE* file, WordFrequency* words, int numWords) {
    qsort(words, numWords, sizeof(WordFrequency), compareWords);
    for (int i = 0; i < numWords; i++) {
        fprintf(file, "%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    char text[MAX_WORDS];
    printf("Enter text to spell check: ");
    fgets(text, MAX_WORDS, stdin);
    countWords(text);
    WordFrequency* words = (WordFrequency*)malloc(MAX_WORDS * sizeof(WordFrequency));
    FILE* file = fopen("dictionary.txt", "r");
    if (file == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }
    int numWords = 0;
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        strcpy(words[numWords].word, word);
        words[numWords].count = 0;
        numWords++;
    }
    fclose(file);
    printWords(stdout, words, numWords);
    free(words);
    return 0;
}