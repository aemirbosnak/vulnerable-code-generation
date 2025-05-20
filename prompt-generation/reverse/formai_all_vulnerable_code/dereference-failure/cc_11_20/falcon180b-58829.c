//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64

typedef struct {
    char *word;
    int count;
} WordCount;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    WordCount words[MAX_WORD_LENGTH];
    int num_words = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char *token = strtok(line, " ");
        while (token!= NULL) {
            if (num_words >= MAX_WORD_LENGTH) {
                printf("Error: Too many words in line\n");
                break;
            }

            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(token, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }

            if (i == num_words) {
                if (num_words == 0) {
                    num_words = 1;
                } else {
                    num_words++;
                }

                words[num_words - 1].word = strdup(token);
                words[num_words - 1].count = 1;
            }

            token = strtok(NULL, " ");
        }
    }

    fclose(fp);

    printf("Word\tCount\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }

    return 0;
}