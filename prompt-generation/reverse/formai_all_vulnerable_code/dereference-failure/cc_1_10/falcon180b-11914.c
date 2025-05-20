//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_FILE_SIZE 100000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(const char *filename, char *buffer) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char c;
    int i = 0;
    while ((c = fgetc(fp))!= EOF) {
        if (i >= MAX_FILE_SIZE) {
            printf("Error: file is too large\n");
            exit(1);
        }
        buffer[i++] = c;
    }
    buffer[i] = '\0';

    fclose(fp);
}

void count_words(char *buffer, WordCount *word_counts, int num_word_counts) {
    char *word = strtok(buffer, " \t\n\r\f\v,.?!;:");
    while (word!= NULL) {
        int i;
        for (i = 0; i < num_word_counts; i++) {
            if (strcmp(word, word_counts[i].word) == 0) {
                word_counts[i].count++;
                break;
            }
        }
        if (i == num_word_counts) {
            if (num_word_counts >= MAX_WORD_LENGTH) {
                printf("Error: too many unique words\n");
                exit(1);
            }
            strcpy(word_counts[num_word_counts].word, word);
            word_counts[num_word_counts].count = 1;
            num_word_counts++;
        }
        word = strtok(NULL, " \t\n\r\f\v,.?!;:");
    }
}

void print_word_counts(WordCount *word_counts, int num_word_counts) {
    printf("Word count:\n");
    for (int i = 0; i < num_word_counts; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <word>\n", argv[0]);
        return 1;
    }

    char filename[MAX_WORD_LENGTH];
    strcpy(filename, argv[1]);

    char word[MAX_WORD_LENGTH];
    strcpy(word, argv[2]);

    char buffer[MAX_FILE_SIZE];
    read_file(filename, buffer);

    int num_word_counts = 0;
    WordCount word_counts[MAX_WORD_LENGTH];
    for (int i = 0; i < MAX_WORD_LENGTH; i++) {
        strcpy(word_counts[i].word, "");
        word_counts[i].count = 0;
    }

    count_words(buffer, word_counts, num_word_counts);

    print_word_counts(word_counts, num_word_counts);

    return 0;
}