//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct Word {
    char word[20];
    int frequency;
} Word;

Word words[MAX_WORDS];

void readWords(FILE *fp) {
    char word[20];
    int i = 0;
    fp = fopen("words.txt", "r");
    if (fp == NULL) {
        return;
    }
    while (fscanf(fp, "%s", word) != EOF) {
        strcpy(words[i].word, word);
        words[i].frequency = 0;
        i++;
    }
    fclose(fp);
}

void calculateWordFrequencies(char *text) {
    char word[20];
    int i = 0;
    for (i = 0; text[i] != '\0'; i++) {
        word[0] = text[i];
        word[1] = '\0';
        int found = 0;
        for (int j = 0; j < MAX_WORDS; j++) {
            if (strcmp(word, words[j].word) == 0) {
                words[j].frequency++;
                found = 1;
            }
        }
        if (!found) {
            strcpy(words[MAX_WORDS - 1].word, word);
            words[MAX_WORDS - 1].frequency = 1;
        }
    }
}

void printWordFrequencies() {
    for (int i = 0; i < MAX_WORDS; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    readWords(NULL);
    calculateWordFrequencies("This is a sample text.");
    printWordFrequencies();
    return 0;
}