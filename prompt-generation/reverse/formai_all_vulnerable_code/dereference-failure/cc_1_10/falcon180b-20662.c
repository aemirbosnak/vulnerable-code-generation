//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LEN 100
#define MAX_LINE_LEN 1000
#define MAX_NUM_WORDS 1000

typedef struct {
    char *word;
    int count;
} WordCount;

void read_file(FILE *fp, char *filename) {
    char line[MAX_LINE_LEN];
    char word[MAX_WORD_LEN];
    int num_words = 0;
    WordCount words[MAX_NUM_WORDS];

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        char *p = line;
        while (*p!= '\0') {
            if (isspace(*p)) {
                *p = '\0';
                if (strlen(word) > 0) {
                    for (int i = 0; i < num_words; i++) {
                        if (strcmp(word, words[i].word) == 0) {
                            words[i].count++;
                            break;
                        }
                    }
                    if (num_words == MAX_NUM_WORDS) {
                        printf("Error: Too many unique words in file.\n");
                        exit(1);
                    }
                    strcpy(words[num_words].word, word);
                    words[num_words].count = 1;
                    num_words++;
                }
                memset(word, 0, MAX_WORD_LEN);
            } else {
                strncat(word, p, 1);
            }
            p++;
        }
    }

    for (int i = 0; i < num_words; i++) {
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
        printf("Error: Could not open file.\n");
        return 1;
    }

    read_file(fp, argv[1]);

    fclose(fp);
    return 0;
}