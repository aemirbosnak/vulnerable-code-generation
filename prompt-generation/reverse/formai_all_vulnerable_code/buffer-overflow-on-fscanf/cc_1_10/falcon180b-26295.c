//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error: Could not open input or output file.\n");
        exit(1);
    }

    int num_words = 0;
    WordCount *word_counts = (WordCount *)malloc(MAX_WORDS * sizeof(WordCount));

    char word[MAX_WORD_LENGTH];
    while (fscanf(input_file, "%s", word)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Error: Maximum number of words reached.\n");
            exit(1);
        }

        WordCount *word_count = &word_counts[num_words];
        strcpy(word_count->word, word);
        word_count->count = 1;

        num_words++;
    }

    fclose(input_file);
    fclose(output_file);

    printf("Checking spelling...\n");

    for (int i = 0; i < num_words; i++) {
        WordCount *word_count = &word_counts[i];

        if (strcmp(word_count->word, "the") == 0) {
            printf("The word '%s' appears %d times.\n", word_count->word, word_count->count);
        } else {
            printf("The word '%s' appears %d times.\n", word_count->word, word_count->count);
        }
    }

    return 0;
}