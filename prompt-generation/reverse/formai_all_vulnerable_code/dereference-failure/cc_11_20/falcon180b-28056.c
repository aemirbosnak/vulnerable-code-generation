//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_CHARS 100

typedef struct {
    char word[MAX_CHARS];
    int count;
} word_t;

int main() {
    FILE *input_file, *output_file;
    char line[MAX_CHARS];
    word_t words[MAX_WORDS];
    int num_words = 0;
    int i, j;

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    while (fgets(line, MAX_CHARS, input_file)!= NULL) {
        int word_count = 0;
        char *token = strtok(line, " ");
        while (token!= NULL) {
            if (word_count >= MAX_WORDS) {
                printf("Error: too many words in input.\n");
                exit(1);
            }
            strcpy(words[word_count].word, token);
            words[word_count].count = 1;
            word_count++;
            token = strtok(NULL, " ");
        }
        num_words += word_count;
    }

    fprintf(output_file, "Number of words: %d\n", num_words);
    for (i = 0; i < num_words; i++) {
        fprintf(output_file, "Word %d: %s\n", i+1, words[i].word);
    }

    for (i = 0; i < num_words; i++) {
        for (j = i+1; j < num_words; j++) {
            if (strcmp(words[i].word, words[j].word) == 0) {
                words[i].count += words[j].count;
                words[j].count = 0;
            }
        }
    }

    fprintf(output_file, "\nNumber of unique words: %d\n", num_words);
    for (i = 0; i < num_words; i++) {
        if (words[i].count > 0) {
            fprintf(output_file, "Word %d: %s (%d occurrences)\n", i+1, words[i].word, words[i].count);
        }
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}