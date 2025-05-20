//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char *word;
    int count;
} WordCount;

void loadWords(char *filename, WordCount *words) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error loading words file\n");
        exit(1);
    }

    char line[100];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            int len = strlen(word);
            if (len > MAX_WORD_LEN) {
                len = MAX_WORD_LEN;
            }
            strncpy(words[words->count].word, word, len);
            words[words->count].word[len] = '\0';
            words[words->count].count++;
            words->count++;
            word = strtok(NULL, " ");
        }
    }

    fclose(fp);
}

int compareWords(const void *a, const void *b) {
    WordCount *wc1 = (WordCount *)a;
    WordCount *wc2 = (WordCount *)b;
    return strcmp(wc1->word, wc2->word);
}

void countWords(char *text, WordCount *words) {
    char *token = strtok(text, " ");
    while (token!= NULL) {
        int len = strlen(token);
        if (len > MAX_WORD_LEN) {
            len = MAX_WORD_LEN;
        }
        strncpy(words[words->count].word, token, len);
        words[words->count].word[len] = '\0';
        words[words->count].count++;
        words->count++;
        token = strtok(NULL, " ");
    }
}

void printWords(WordCount *words) {
    qsort(words, words->count, sizeof(WordCount), compareWords);
    for (int i = 0; i < words->count; i++) {
        printf("%s %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s words_file.txt text_file.txt\n", argv[0]);
        exit(1);
    }

    char *filename1 = argv[1];
    char *filename2 = argv[2];

    FILE *fp1 = fopen(filename1, "r");
    if (fp1 == NULL) {
        printf("Error loading words file\n");
        exit(1);
    }

    WordCount words[MAX_WORDS];
    loadWords(filename1, words);
    fclose(fp1);

    FILE *fp2 = fopen(filename2, "r");
    if (fp2 == NULL) {
        printf("Error loading text file\n");
        exit(1);
    }

    char text[100000];
    fread(text, sizeof(char), sizeof(text), fp2);
    fclose(fp2);

    countWords(text, words);

    printWords(words);

    return 0;
}