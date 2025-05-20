//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void loadWords(char* filename, WordFrequency words[]) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    char word[MAX_WORD_LENGTH];
    int count = 0;
    while (fscanf(file, "%s", word)!= EOF) {
        if (count >= MAX_WORDS) {
            printf("Error: too many words in file\n");
            exit(1);
        }
        strcpy(words[count].word, word);
        words[count].count = 0;
        count++;
    }
    fclose(file);
}

void spellCheck(char* text, WordFrequency words[]) {
    char* token = strtok(text, ",.?!;:");
    while (token!= NULL) {
        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(token, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }
        if (i == MAX_WORDS) {
            printf("Unknown word: %s\n", token);
        }
        token = strtok(NULL, ",.?!;:");
    }
}

void printFrequencies(WordFrequency words[]) {
    printf("Word frequencies:\n");
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    char* filename = "words.txt";
    WordFrequency words[MAX_WORDS];
    loadWords(filename, words);

    char* text = "The quick brown fox jumps over the lazy dog.";
    spellCheck(text, words);

    printFrequencies(words);

    return 0;
}