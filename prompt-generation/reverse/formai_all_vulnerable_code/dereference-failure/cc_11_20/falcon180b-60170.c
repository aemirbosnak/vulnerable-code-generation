//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

struct word {
    char *english;
    char *alien;
};

int main() {
    FILE *input_file, *output_file;
    char line[MAX_WORD_LENGTH];
    char *word;
    int num_words = 0;
    struct word *word_list = malloc(MAX_WORDS * sizeof(struct word));

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        return 1;
    }

    while (fgets(line, MAX_WORD_LENGTH, input_file)!= NULL) {
        word = strtok(line, " ");
        while (word!= NULL) {
            num_words++;
            if (num_words >= MAX_WORDS) {
                printf("Error: Too many words in input file.\n");
                return 1;
            }
            word_list[num_words - 1].english = strdup(word);
            word_list[num_words - 1].alien = malloc(MAX_WORD_LENGTH);
            strcpy(word_list[num_words - 1].alien, "");
            word = strtok(NULL, " ");
        }
    }

    rewind(input_file);

    while (fgets(line, MAX_WORD_LENGTH, input_file)!= NULL) {
        word = strtok(line, " ");
        while (word!= NULL) {
            for (int i = 0; i < num_words; i++) {
                if (strcmp(word, word_list[i].english) == 0) {
                    strcpy(word_list[i].alien, word);
                    break;
                }
            }
            word = strtok(NULL, " ");
        }
    }

    fprintf(output_file, "Alien Language Translator\n");
    fprintf(output_file, "------------------------\n");

    for (int i = 0; i < num_words; i++) {
        fprintf(output_file, "English: %s\n", word_list[i].english);
        fprintf(output_file, "Alien:   %s\n", word_list[i].alien);
        fprintf(output_file, "\n");
    }

    fclose(input_file);
    fclose(output_file);

    for (int i = 0; i < num_words; i++) {
        free(word_list[i].english);
        free(word_list[i].alien);
    }
    free(word_list);

    return 0;
}