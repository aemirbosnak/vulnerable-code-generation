//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_CHARS_PER_WORD 50

typedef struct {
    char word[MAX_CHARS_PER_WORD];
    int count;
} WordCount;

void readWords(FILE *fp, WordCount words[]) {
    char word[MAX_CHARS_PER_WORD];
    while (fscanf(fp, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        int found = 0;
        int j;
        for (j = 0; j < MAX_WORDS &&!found; j++) {
            if (strcmp(word, words[j].word) == 0) {
                words[j].count++;
                found = 1;
            }
        }
        if (!found) {
            strcpy(words[j].word, word);
            words[j].count = 1;
            j++;
            if (j >= MAX_WORDS) {
                printf("Maximum number of words (%d) reached.\n", MAX_WORDS);
                exit(1);
            }
        }
    }
}

void printWords(WordCount words[]) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i].word, "")!= 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file '%s'.\n", argv[1]);
        return 1;
    }
    WordCount words[MAX_WORDS];
    readWords(fp, words);
    fclose(fp);
    printWords(words);
    return 0;
}