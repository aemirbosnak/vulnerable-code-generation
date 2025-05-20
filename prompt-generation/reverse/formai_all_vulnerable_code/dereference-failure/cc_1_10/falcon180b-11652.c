//Falcon-180B DATASET v1.0 Category: Text processing ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_WORD_LENGTH 32

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE *file, char *line, int max_length) {
    int length = 0;
    while (length < max_length && fgets(line, max_length, file)!= NULL) {
        length += strlen(line);
    }
    line[length - 1] = '\0';
}

void tokenize_line(char *line, char *delimiter, WordCount words[], int max_words) {
    char *token = strtok(line, delimiter);
    int i = 0;
    while (token!= NULL && i < max_words) {
        strcpy(words[i].word, token);
        words[i].count = 1;
        i++;
        token = strtok(NULL, delimiter);
    }
}

void print_word_counts(WordCount words[], int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <file> <delimiter>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    char delimiter = argv[2][0];
    WordCount words[100];
    int num_words = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        tokenize_line(line, &delimiter, words, 100);
        num_words += strlen(line) - 1;
    }

    print_word_counts(words, num_words);

    return 0;
}