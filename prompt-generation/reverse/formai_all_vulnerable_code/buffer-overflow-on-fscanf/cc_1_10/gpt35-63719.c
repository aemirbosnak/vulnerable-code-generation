//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_UNIQUE_WORDS 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void print_word_frequency(WordFrequency *word_frequency, int num_words) {
    int i;
    printf("\nWORD             FREQUENCY\n");
    printf("=========================\n");
    for (i = 0; i < num_words; i++) {
        printf("%-15s %d\n", word_frequency[i].word, word_frequency[i].frequency);
    }
}

int main(int argc, char *argv[]) {
    char *input_file_path;
    FILE *input_file;
    char word[MAX_WORD_LENGTH];
    WordFrequency word_frequency[MAX_UNIQUE_WORDS];
    int num_words = 0;
    int i, j, k;
    int found;

    if (argc != 2) {
        printf("Usage: %s input_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    input_file_path = argv[1];
    input_file = fopen(input_file_path, "r");

    if (input_file == NULL) {
        printf("Error opening file %s\n", input_file_path);
        exit(EXIT_FAILURE);
    }

    printf("Counting words in file %s\n", input_file_path);

    while (fscanf(input_file, "%s", word) == 1) {
        found = 0;
        for (i = 0; i < num_words; i++) {
            if (strcmp(word_frequency[i].word, word) == 0) {
                word_frequency[i].frequency++;
                found = 1;
                break;
            }
        }
        if (!found) {
            if (num_words >= MAX_UNIQUE_WORDS) {
                printf("Max unique words reached, stopping counting\n");
                break;
            }
            strcpy(word_frequency[num_words].word, word);
            word_frequency[num_words].frequency = 1;
            num_words++;
        }
    }

    print_word_frequency(word_frequency, num_words);

    fclose(input_file);

    return 0;
}