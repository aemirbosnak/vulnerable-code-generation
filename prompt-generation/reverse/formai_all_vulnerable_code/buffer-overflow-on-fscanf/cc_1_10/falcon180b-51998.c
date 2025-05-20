//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void readWords(char *filename, WordCount *words) {
    FILE *file = fopen(filename, "r");
    char word[MAX_WORD_LEN];
    int i = 0;
    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Error: Too many words in file.\n");
            exit(1);
        }
        strcpy(words[i].word, word);
        words[i].count = 0;
        i++;
    }
    fclose(file);
}

void searchWords(char *filename, WordCount *words) {
    FILE *file = fopen(filename, "r");
    char word[MAX_WORD_LEN];
    int i = 0;
    while (fscanf(file, "%s", word)!= EOF) {
        for (int j = 0; j < i; j++) {
            if (strcmp(word, words[j].word) == 0) {
                words[j].count++;
                break;
            }
        }
        if (i >= MAX_WORDS) {
            printf("Error: Too many words in file.\n");
            exit(1);
        }
        strcpy(words[i].word, word);
        words[i].count = 0;
        i++;
    }
    fclose(file);
}

void printWords(WordCount *words) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <keyword>\n", argv[0]);
        exit(1);
    }
    WordCount words[MAX_WORDS];
    readWords(argv[1], words);
    searchWords(argv[1], words);
    printWords(words);
    return 0;
}