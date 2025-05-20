//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct word_t {
    char word[MAX_WORD_LENGTH];
    int count;
} word_t;

int main() {
    FILE *input_file, *output_file;
    char word[MAX_WORD_LENGTH];
    word_t words[MAX_WORDS];
    int num_words = 0;
    int i, j;

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        return 1;
    }

    while (fscanf(input_file, "%s", word)!= EOF) {
        for (i = 0; i < num_words; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }
        if (i == num_words) {
            if (num_words >= MAX_WORDS) {
                printf("Error: too many unique words.\n");
                return 1;
            }
            strcpy(words[num_words].word, word);
            words[num_words].count = 1;
            num_words++;
        }
    }

    fprintf(output_file, "Word count:\n");
    for (i = 0; i < num_words; i++) {
        fprintf(output_file, "%s: %d\n", words[i].word, words[i].count);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}