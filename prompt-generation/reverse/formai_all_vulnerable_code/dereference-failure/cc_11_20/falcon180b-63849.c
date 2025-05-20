//Falcon-180B DATASET v1.0 Category: Text processing ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 50
#define MAX_WORD_COUNT 100

typedef struct {
    char *word;
    int count;
} WordCount;

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *word;
    WordCount word_counts[MAX_WORD_COUNT];
    int num_words = 0;
    int i;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        num_words = 0;
        word = strtok(line, " \t\n\r\f\v");
        while (word!= NULL) {
            if (num_words >= MAX_WORD_COUNT) {
                fprintf(stderr, "Error: Too many words\n");
                exit(1);
            }
            for (i = 0; i < num_words; i++) {
                if (strcmp(word, word_counts[i].word) == 0) {
                    word_counts[i].count++;
                    break;
                }
            }
            if (i == num_words) {
                if (num_words >= MAX_WORD_COUNT - 1) {
                    fprintf(stderr, "Error: Too many unique words\n");
                    exit(1);
                }
                word_counts[num_words].word = strdup(word);
                word_counts[num_words].count = 1;
                num_words++;
            }
            word = strtok(NULL, " \t\n\r\f\v");
        }
    }

    fclose(fp);

    printf("Word counts:\n");
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    return 0;
}