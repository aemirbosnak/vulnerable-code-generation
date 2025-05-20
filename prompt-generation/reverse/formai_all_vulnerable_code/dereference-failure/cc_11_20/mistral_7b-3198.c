//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_WORDS 10000
#define WORD_LENGTH 50
typedef struct {
    char word[WORD_LENGTH];
    int count;
} Word;
Word words[MAX_WORDS];
int main(int argc, char *argv[]) {
    FILE *fp;
    char filepath[100], c;
    int i, j, k;
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    strcpy(filepath, argv[1]);
    fp = fopen(filepath, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filepath);
        return 1;
    }
    i = j = 0;
    while ((c = fgetc(fp)) != EOF) {
        if (isalpha(c)) {
            while (isalpha(c = fgetc(fp))) {
                words[i].word[j++] = tolower(c);
                if (j >= WORD_LENGTH) {
                    i++;
                    j = 0;
                    if (i >= MAX_WORDS) {
                        printf("Error: too many words\n");
                        fclose(fp);
                        return 1;
                    }
                }
            }
            words[i].word[j] = '\0';
            for (k = 0; k < i; k++) {
                if (strcmp(words[i].word, words[k].word) == 0) {
                    words[k].count++;
                    break;
                }
            }
            if (k == i) {
                strcpy(words[i].word, words[i].word);
                words[i].count = 1;
            }
        }
    }
    printf("Word frequencies:\n");
    for (i = 0; i < j; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
    fclose(fp);
    return 0;
}