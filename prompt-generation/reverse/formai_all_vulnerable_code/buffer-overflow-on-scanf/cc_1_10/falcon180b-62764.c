//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int main() {
    char input_file[MAX_WORD_LENGTH];
    char output_file[MAX_WORD_LENGTH];
    FILE *input, *output;
    char word[MAX_WORD_LENGTH];
    int i, j, num_words = 0;
    WordFrequency *word_frequency = (WordFrequency*) malloc(MAX_WORDS * sizeof(WordFrequency));

    printf("Enter input file name: ");
    scanf("%s", input_file);
    printf("Enter output file name: ");
    scanf("%s", output_file);

    input = fopen(input_file, "r");
    if (input == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    output = fopen(output_file, "w");
    if (output == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    while (fscanf(input, "%s", word)!= EOF) {
        for (i = 0; i < num_words; i++) {
            if (strcmp(word, word_frequency[i].word) == 0) {
                word_frequency[i].frequency++;
                break;
            }
        }
        if (i == num_words) {
            if (num_words >= MAX_WORDS) {
                printf("Exceeded maximum number of words.\n");
                exit(1);
            }
            strcpy(word_frequency[num_words].word, word);
            word_frequency[num_words].frequency = 1;
            num_words++;
        }
    }

    for (i = 0; i < num_words; i++) {
        fprintf(output, "%s %d\n", word_frequency[i].word, word_frequency[i].frequency);
    }

    fclose(input);
    fclose(output);
    free(word_frequency);

    return 0;
}