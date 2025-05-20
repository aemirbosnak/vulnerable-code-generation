#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 1024

void translate_word(char *word) {
    if (strlen(word) > 0) {
        word[0] = toupper(word[0]);
        strcat(word, "AY");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (!output_file) {
        perror("Error opening output file");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(input_file, "%s", word) == 1) {
        translate_word(word);
        fprintf(output_file, "%s ", word);
    }

    fclose(input_file);
    fclose(output_file);

    return EXIT_SUCCESS;
}
