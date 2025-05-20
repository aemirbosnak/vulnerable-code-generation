//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void read_file(const char *filename, WordFrequency *word_frequencies, int *num_words) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    char *word = NULL;
    char *token = NULL;
    size_t token_len = 0;
    int line_num = 1;

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        line_num++;
        word_frequencies[*num_words].frequency = 0;
        strcpy(word_frequencies[*num_words].word, "");

        token = strtok_r(line, ",.!?:;\"'", &token_len);
        while (token!= NULL) {
            if (strlen(token) > MAX_WORD_LENGTH) {
                printf("Error: word \"%s\" is too long on line %d\n", token, line_num);
                exit(1);
            }

            if (isalpha(token[0])) {
                if (strlen(word_frequencies[*num_words].word) == 0) {
                    strcpy(word_frequencies[*num_words].word, token);
                }
                word_frequencies[*num_words].frequency++;
            }

            token = strtok_r(NULL, ",.!?:;\"'", &token_len);
        }

        if (strlen(word_frequencies[*num_words].word) > 0) {
            (*num_words)++;
        }
    }

    fclose(file);
}

void sort_word_frequencies(WordFrequency *word_frequencies, int num_words) {
    for (int i = 0; i < num_words - 1; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (word_frequencies[i].frequency < word_frequencies[j].frequency) {
                WordFrequency temp = word_frequencies[i];
                word_frequencies[i] = word_frequencies[j];
                word_frequencies[j] = temp;
            }
        }
    }
}

void print_word_frequencies(WordFrequency *word_frequencies, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_frequencies[i].word, word_frequencies[i].frequency);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    WordFrequency word_frequencies[MAX_WORDS];
    int num_words = 0;

    read_file(argv[1], word_frequencies, &num_words);
    sort_word_frequencies(word_frequencies, num_words);
    print_word_frequencies(word_frequencies, num_words);

    return 0;
}