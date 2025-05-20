//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORD_COUNT 10000
#define MIN_WORD_LENGTH 3

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

struct word_count word_counts[MAX_WORD_COUNT];
int num_words = 0;

void add_word(char* word) {
    if (num_words >= MAX_WORD_COUNT) {
        printf("Error: Maximum word count reached.\n");
        exit(1);
    }

    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(word_counts[i].word, word) == 0) {
            word_counts[i].count++;
            return;
        }
    }

    strcpy(word_counts[num_words].word, word);
    word_counts[num_words].count = 1;
    num_words++;
}

void process_file(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s.\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    int word_length = 0;
    char prev_char = '\0';

    while ((fscanf(file, "%c", &word[word_length]))!= EOF) {
        if (isalpha(word[word_length])) {
            if (word_length > 0 && isalpha(prev_char)) {
                add_word(word);
            }

            word_length++;
        } else {
            if (word_length > MIN_WORD_LENGTH) {
                add_word(word);
            }

            word_length = 0;
        }

        prev_char = word[word_length - 1];
    }

    if (word_length > MIN_WORD_LENGTH) {
        add_word(word);
    }

    fclose(file);
}

void print_misspelled_words(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s.\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while ((fscanf(file, "%s", word))!= EOF) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(word_counts[i].word, word) == 0) {
                break;
            }
        }

        if (i == num_words) {
            printf("Possible misspelling: %s\n", word);
        }
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <text_file> <dictionary_file>\n", argv[0]);
        exit(1);
    }

    process_file(argv[1]);
    print_misspelled_words(argv[2]);

    return 0;
}