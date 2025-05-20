//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void loadWords(FILE *fp, WordCount words[]) {
    int i = 0;
    char word[MAX_WORD_LENGTH];

    while (fscanf(fp, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Error: Too many words!\n");
            exit(1);
        }
        strcpy(words[i].word, word);
        words[i].count = 0;
        i++;
    }
}

void spellCheck(FILE *fp, WordCount words[]) {
    char word[MAX_WORD_LENGTH];
    int i, j, k, len;

    while (fscanf(fp, "%s", word)!= EOF) {
        len = strlen(word);
        for (i = 0; i < len; i++) {
            if (!isalpha(word[i])) {
                word[i] = tolower(word[i]);
            }
        }
        for (j = 0; j < MAX_WORDS; j++) {
            k = 0;
            while (k < MAX_WORD_LENGTH && words[j].word[k] == word[k]) {
                k++;
            }
            if (k == len) {
                words[j].count++;
                break;
            }
        }
    }
}

void printResults(WordCount words[]) {
    int i;

    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    FILE *fp;
    WordCount words[MAX_WORDS];

    fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open words file!\n");
        exit(1);
    }

    loadWords(fp, words);
    fclose(fp);

    fp = fopen("text.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open text file!\n");
        exit(1);
    }

    spellCheck(fp, words);
    fclose(fp);

    printResults(words);

    return 0;
}