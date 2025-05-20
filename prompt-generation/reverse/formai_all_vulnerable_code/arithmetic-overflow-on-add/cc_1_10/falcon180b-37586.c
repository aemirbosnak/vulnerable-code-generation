//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 100000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordFrequency;

void addWord(WordFrequency *wordFreq, char *word) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (strcmp(wordFreq[i].word, word) == 0) {
            wordFreq[i].count++;
            return;
        }
    }
    strcpy(wordFreq[i].word, word);
    wordFreq[i].count = 1;
}

void printWordFrequency(WordFrequency *wordFreq) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (strcmp(wordFreq[i].word, "")!= 0) {
            printf("%s : %d\n", wordFreq[i].word, wordFreq[i].count);
        }
    }
}

int main() {
    FILE *file;
    char ch;
    char word[MAX_WORD_LEN];
    WordFrequency wordFreq[MAX_WORDS];
    int i = 0;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            word[0] = toupper(ch);
            int j = 1;
            while ((ch = fgetc(file))!= EOF && isalnum(ch)) {
                word[j] = toupper(ch);
                j++;
            }
            word[j] = '\0';
            addWord(wordFreq, word);
        }
    }

    fclose(file);

    printWordFrequency(wordFreq);

    return 0;
}