//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int main(int argc, char **argv) {
    FILE *fp;
    char buf[MAX_WORD_LEN];
    char *filename = "input.txt";
    WordCount words[MAX_WORDS];
    int num_words = 0;

    if (argc > 1) {
        filename = argv[1];
    }

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    while (fscanf(fp, "%s", buf)!= EOF) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(buf, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }
        if (i == num_words) {
            if (num_words >= MAX_WORDS) {
                printf("Too many words\n");
                exit(1);
            }
            strcpy(words[num_words].word, buf);
            words[num_words].count = 1;
            num_words++;
        }
    }

    fclose(fp);

    printf("Word count:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}