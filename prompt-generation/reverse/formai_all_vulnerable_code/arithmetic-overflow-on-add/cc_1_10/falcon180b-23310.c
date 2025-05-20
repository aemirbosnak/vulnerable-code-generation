//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void readFile(FILE *fp, WordFrequency words[MAX_WORDS]) {
    char ch;
    int i = 0;
    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            words[i].word[0] = tolower(ch);
            int j = 1;
            while ((ch = fgetc(fp))!= EOF && isalnum(ch)) {
                if (j >= MAX_WORD_LENGTH) {
                    break;
                }
                words[i].word[j++] = tolower(ch);
            }
            words[i].word[j] = '\0';
            words[i].count++;
            i++;
        }
    }
}

void sortWords(WordFrequency words[MAX_WORDS]) {
    for (int i = 0; i < MAX_WORDS - 1; i++) {
        for (int j = i + 1; j < MAX_WORDS; j++) {
            if (words[i].count < words[j].count) {
                WordFrequency temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void printWords(WordFrequency words[MAX_WORDS]) {
    for (int i = 0; i < MAX_WORDS && words[i].count > 0; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    WordFrequency words[MAX_WORDS];
    readFile(fp, words);
    fclose(fp);

    sortWords(words);
    printWords(words);

    return 0;
}