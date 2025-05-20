//Falcon-180B DATASET v1.0 Category: Educational ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void add_word(char* word, WordCount* word_counts, int* num_words) {
    int i;
    for (i = 0; i < *num_words; i++) {
        if (strcmp(word_counts[i].word, word) == 0) {
            word_counts[i].count++;
            return;
        }
    }
    if (*num_words >= MAX_WORDS) {
        printf("Error: Too many unique words.\n");
        exit(1);
    }
    strcpy(word_counts[*num_words].word, word);
    word_counts[*num_words].count = 1;
    (*num_words)++;
}

void print_word_counts(WordCount* word_counts, int num_words) {
    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    char input_file[100];
    char output_file[100];
    char* line = NULL;
    size_t line_size = 0;
    FILE* input = NULL;
    FILE* output = NULL;
    WordCount word_counts[MAX_WORDS];
    int num_words = 0;

    printf("Enter input file name: ");
    scanf("%s", input_file);
    printf("Enter output file name: ");
    scanf("%s", output_file);

    input = fopen(input_file, "r");
    if (input == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    output = fopen(output_file, "w");
    if (output == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    while ((line_size = getline(&line, &line_size, input))!= -1) {
        char* word = strtok(line, ",.!?;:");
        while (word!= NULL) {
            add_word(word, word_counts, &num_words);
            word = strtok(NULL, ",.!?;:");
        }
    }

    fclose(input);
    fclose(output);

    print_word_counts(word_counts, num_words);

    return 0;
}