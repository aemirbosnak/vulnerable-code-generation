//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_WORD_SIZE 64

struct word_count {
    char word[MAX_WORD_SIZE];
    int count;
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    struct word_count *word_counts = NULL;
    int num_word_counts = 0;

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        char *token = strtok(line, " ");
        while (token!= NULL) {
            struct word_count *word_count = NULL;
            for (int i = 0; i < num_word_counts; i++) {
                if (strcmp(word_counts[i].word, token) == 0) {
                    word_count = &word_counts[i];
                    break;
                }
            }

            if (word_count == NULL) {
                if (num_word_counts >= MAX_WORD_SIZE) {
                    printf("Error: Too many unique words in log file\n");
                    return 1;
                }

                word_count = &word_counts[num_word_counts++];
                strncpy(word_count->word, token, MAX_WORD_SIZE - 1);
                word_count->word[MAX_WORD_SIZE - 1] = '\0';
                word_count->count = 1;
            } else {
                word_count->count++;
            }

            token = strtok(NULL, " ");
        }
    }

    fclose(fp);

    printf("Word count:\n");
    for (int i = 0; i < num_word_counts; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    return 0;
}