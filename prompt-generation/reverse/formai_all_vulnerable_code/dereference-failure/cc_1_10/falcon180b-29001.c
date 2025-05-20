//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_WORD_SIZE 64

// Function to split a line into words
void split_line(char* line, char* words[], int max_words) {
    int word_count = 0;
    char* token = strtok(line, " ");

    while (token!= NULL && word_count < max_words) {
        strcpy(words[word_count], token);
        word_count++;
        token = strtok(NULL, " ");
    }
}

// Function to count the occurrences of a word in a file
void count_word(char* filename, char* word, int* count) {
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    char line[MAX_LINE_SIZE];
    char words[MAX_WORD_SIZE][MAX_WORD_SIZE];
    int line_count = 0;

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        split_line(line, words, MAX_WORD_SIZE);

        for (int i = 0; i < MAX_WORD_SIZE; i++) {
            if (strcmp(words[i], word) == 0) {
                (*count)++;
            }
        }

        line_count++;
    }

    fclose(file);
    printf("Found %d occurrences of '%s' in %d lines.\n", *count, word, line_count);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <filename> <word>\n", argv[0]);
        exit(1);
    }

    char* filename = argv[1];
    char* word = argv[2];
    int count = 0;

    count_word(filename, word, &count);

    return 0;
}