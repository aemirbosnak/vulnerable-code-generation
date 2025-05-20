//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS_PER_LINE 100
#define MAX_LINE_LENGTH 1024

bool is_whitespace(char c) {
    return (c == ' ' || c == '\t' || c == '\n');
}

int count_words(const char *line, int *num_words) {
    int num_words_in_line = 0;
    int word_start = 0;

    for (int i = 0; i < strlen(line); i++) {
        if (is_whitespace(line[i])) {
            if (num_words_in_line > 0) {
                num_words[word_start++]++;
                num_words_in_line = 0;
            }
        } else {
            if (num_words_in_line == 0) {
                num_words[word_start++] = 1;
            }
            num_words_in_line++;
        }
    }

    if (num_words_in_line > 0) {
        num_words[word_start++]++;
    }

    return word_start;
}

int main() {
    FILE *file = fopen("text.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    int num_words[MAX_WORDS_PER_LINE];
    int num_words_in_line;

    int total_words = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        num_words_in_line = count_words(line, num_words);
        total_words += num_words_in_line;
    }

    fclose(file);

    printf("Total number of words in the file: %d\n", total_words);

    return 0;
}