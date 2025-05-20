//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 100
#define MIN_WORD_LEN 3

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} Word;

void read_text(char *filename, char *text) {
    FILE *fp;
    char ch;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int length = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    text = (char *) malloc(length + 1);
    if (text == NULL) {
        printf("Error allocating memory for text\n");
        exit(1);
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            strncat(text, &ch, 1);
        }
    }

    fclose(fp);
}

void tokenize(char *text, Word *words) {
    char *token;
    int i = 0;

    token = strtok(text, " \t\n\r\f\v.,!?;:\"'");
    while (token!= NULL) {
        if (strlen(token) >= MIN_WORD_LEN) {
            strcpy(words[i].word, token);
            words[i].count = 1;
            i++;
        }
        token = strtok(NULL, " \t\n\r\f\v.,!?;:\"'");
    }
}

void count_words(Word *words, int num_words, int threshold) {
    int i;

    for (i = 0; i < num_words; i++) {
        if (words[i].count >= threshold) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <threshold>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    int threshold = atoi(argv[2]);

    char *text;
    Word *words;

    read_text(filename, text);
    tokenize(text, words);
    count_words(words, MAX_WORDS, threshold);

    free(text);
    free(words);

    return 0;
}