//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void readWords(FILE *file, WordCount words[MAX_WORDS]) {
    char word[MAX_WORD_LEN];
    int i = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Too many words in the file!\n");
            exit(1);
        }

        strcpy(words[i].word, word);
        words[i].count = 0;
        i++;
    }
}

void countWords(char *text, WordCount words[MAX_WORDS]) {
    char *token;
    int i = 0;

    token = strtok(text, ",.?!;:");

    while (token!= NULL) {
        int j;

        for (j = 0; j < i; j++) {
            if (strcmp(token, words[j].word) == 0) {
                words[j].count++;
                break;
            }
        }

        if (j == i) {
            if (i >= MAX_WORDS) {
                printf("Too many unique words in the text!\n");
                exit(1);
            }

            strcpy(words[i].word, token);
            words[i].count = 1;
            i++;
        }

        token = strtok(NULL, ",.?!;:");
    }
}

void printWords(WordCount words[MAX_WORDS]) {
    int i;

    for (i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i].word, "")!= 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    WordCount words[MAX_WORDS];

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Cannot open file: %s\n", argv[1]);
        return 1;
    }

    readWords(file, words);
    countWords(argv[1], words);
    printWords(words);

    return 0;
}