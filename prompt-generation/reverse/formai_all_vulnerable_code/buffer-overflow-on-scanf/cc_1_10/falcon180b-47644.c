//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

void read_file(FILE *fp, Word words[MAX_WORDS]) {
    char word[MAX_WORD_LENGTH];
    int i = 0;
    while (fscanf(fp, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Error: Too many words in file.\n");
            exit(1);
        }
        strcpy(words[i].word, word);
        words[i].count = 1;
        i++;
    }
}

void print_words(Word words[MAX_WORDS]) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    FILE *fp;
    Word words[MAX_WORDS];
    char filename[100];
    int i, j;

    printf("Enter the name of the text file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    read_file(fp, words);

    printf("Enter the word to search for: ");
    scanf("%s", words[0].word);

    for (i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i].word, words[0].word) == 0) {
            words[i].count++;
        }
    }

    printf("Word count:\n");
    print_words(words);

    return 0;
}