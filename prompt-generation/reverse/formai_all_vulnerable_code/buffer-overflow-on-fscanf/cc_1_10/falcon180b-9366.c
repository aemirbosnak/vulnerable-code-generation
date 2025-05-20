//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LEN 100
#define MAX_WORD_COUNT 1000
#define MAX_FILE_SIZE 100000

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

WordCount word_counts[MAX_WORD_COUNT];
int num_words;

bool is_alpha(char c) {
    return (isalpha(c) || c == '\'');
}

void read_file(FILE *file) {
    char word[MAX_WORD_LEN];
    int word_len = 0;
    int i;

    while (fscanf(file, "%s", word)!= EOF) {
        for (i = 0; i < strlen(word); i++) {
            if (!is_alpha(word[i])) {
                word[i] = '\0';
            }
        }
        word_len = strlen(word);

        if (word_len > 0 && word_len <= MAX_WORD_LEN) {
            for (i = 0; i < num_words; i++) {
                if (strcmp(word, word_counts[i].word) == 0) {
                    word_counts[i].count++;
                    break;
                }
            }

            if (i == num_words) {
                if (num_words >= MAX_WORD_COUNT) {
                    printf("Error: Too many unique words in file.\n");
                    exit(1);
                }

                strcpy(word_counts[num_words].word, word);
                word_counts[num_words].count = 1;
                num_words++;
            }
        }
    }
}

void print_word_counts(void) {
    int i;

    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    char filename[MAX_FILE_SIZE];

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    strcpy(filename, argv[1]);
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Could not open file '%s'.\n", filename);
        exit(1);
    }

    num_words = 0;
    read_file(file);
    fclose(file);

    print_word_counts();

    return 0;
}