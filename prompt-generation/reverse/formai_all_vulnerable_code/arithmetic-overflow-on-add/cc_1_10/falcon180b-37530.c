//Falcon-180B DATASET v1.0 Category: Text processing ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80
#define MAX_WORD_LENGTH 10

typedef struct {
    char *word;
    int count;
} WordCount;

void print_word_counts(const WordCount *word_counts, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    char *word_list[MAX_WORD_LENGTH];
    int num_words = 0;
    WordCount word_counts[MAX_WORD_LENGTH];

    printf("Enter a list of words separated by spaces:\n");
    while (fgets(line, MAX_LINE_LENGTH, stdin)) {
        int word_length = strlen(line);
        if (word_length == 1 && line[0] == '\n') {
            break;
        }
        char *token = strtok(line, " ");
        while (token!= NULL) {
            if (num_words >= MAX_WORD_LENGTH) {
                printf("Error: too many words\n");
                exit(1);
            }
            strcpy(word_list[num_words], token);
            num_words++;
            token = strtok(NULL, " ");
        }
    }

    printf("Enter a file name to count words:\n");
    FILE *file = fopen(line, "r");
    if (file == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }

    char line_buffer[MAX_LINE_LENGTH];
    while (fgets(line_buffer, MAX_LINE_LENGTH, file)) {
        int line_length = strlen(line_buffer);
        if (line_length == 1 && line_buffer[0] == '\n') {
            break;
        }
        char *token = strtok(line_buffer, " ");
        while (token!= NULL) {
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(token, word_list[i]) == 0) {
                    word_counts[i].count++;
                    break;
                }
            }
            if (i == num_words) {
                printf("Error: unknown word '%s'\n", token);
            }
            token = strtok(NULL, " ");
        }
    }

    print_word_counts(word_counts, num_words);

    return 0;
}