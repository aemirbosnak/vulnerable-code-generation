//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

struct word {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
};

int main() {
    FILE *input_file, *output_file;
    char filename[MAX_WORD_LENGTH];
    char line[MAX_WORD_LENGTH];
    int num_words = 0;
    struct word words[MAX_WORDS];

    printf("Welcome to the Alien Language Translator!\n");
    printf("Please enter the name of the input file: ");
    scanf("%s", filename);

    input_file = fopen(filename, "r");

    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    output_file = fopen("output.txt", "w");

    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, input_file)!= NULL) {
        if (num_words >= MAX_WORDS) {
            printf("Error: Too many words in input file.\n");
            exit(1);
        }

        words[num_words].english[0] = '\0';
        words[num_words].alien[0] = '\0';

        char *token = strtok(line, " ");

        while (token!= NULL) {
            strcpy(words[num_words].english, token);
            strcpy(words[num_words].alien, "hello");

            fprintf(output_file, "English: %s\nAlien: %s\n\n", words[num_words].english, words[num_words].alien);

            num_words++;

            token = strtok(NULL, " ");
        }
    }

    printf("Translation complete!\n");

    fclose(input_file);
    fclose(output_file);

    return 0;
}