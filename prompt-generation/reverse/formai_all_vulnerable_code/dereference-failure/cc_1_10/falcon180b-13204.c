//Falcon-180B DATASET v1.0 Category: Text processing ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE* file, char* buffer, int max_size) {
    int ch;
    int index = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (index >= max_size - 1) {
            fprintf(stderr, "Buffer overflow\n");
            exit(1);
        }
        buffer[index++] = ch;
    }
    buffer[index] = '\0';
}

void tokenize(char* buffer, WordCount* word_counts, int num_word_counts) {
    char* token = strtok(buffer, " \t\n\r\f\v.,!?;:\"'");

    while (token!= NULL && num_word_counts > 0) {
        int i;

        for (i = 0; i < num_word_counts; i++) {
            if (strcmp(token, word_counts[i].word) == 0) {
                word_counts[i].count++;
                break;
            }
        }

        if (i == num_word_counts) {
            if (num_word_counts >= MAX_WORDS) {
                fprintf(stderr, "Too many unique words\n");
                exit(1);
            }
            strncpy(word_counts[num_word_counts].word, token, MAX_WORD_LENGTH - 1);
            word_counts[num_word_counts].word[MAX_WORD_LENGTH - 1] = '\0';
            word_counts[num_word_counts].count = 1;
            num_word_counts++;
        }

        token = strtok(NULL, " \t\n\r\f\v.,!?;:\"'");
    }
}

void print_word_counts(WordCount* word_counts, int num_word_counts) {
    int i;

    for (i = 0; i < num_word_counts; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main(int argc, char** argv) {
    FILE* file;
    char buffer[1024];
    WordCount word_counts[MAX_WORDS];
    int num_word_counts = 0;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    file = fopen(argv[1], "r");

    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }

    while (fread(buffer, 1, sizeof(buffer), file) > 0) {
        read_file(file, buffer, sizeof(buffer));
        tokenize(buffer, word_counts, num_word_counts);
    }

    print_word_counts(word_counts, num_word_counts);

    return 0;
}