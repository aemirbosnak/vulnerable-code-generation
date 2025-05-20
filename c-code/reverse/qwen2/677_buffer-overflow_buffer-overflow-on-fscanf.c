#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 1024

void translate_to_pig_latin(char *word) {
    if (isalpha(word[0])) {
        char first_char = word[0];
        int len = strlen(word);
        for (int i = 1; i <= len; i++) {
            word[i - 1] = word[i];
        }
        word[len - 1] = first_char;
        strcat(word, "ay");
    }
}

int main() {
    FILE *input_file, *output_file;
    char input_filename[MAX_WORD_LENGTH], output_filename[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];

    printf("Enter the name of the input file: ");
    scanf("%s", input_filename);

    printf("Enter the name of the output file: ");
    scanf("%s", output_filename);

    input_file = fopen(input_filename, "r");
    if (!input_file) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    output_file = fopen(output_filename, "w");
    if (!output_file) {
        perror("Error opening output file");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    while (fscanf(input_file, "%s", word) != EOF) {
        translate_to_pig_latin(word);
        fprintf(output_file, "%s ", word);
    }

    fclose(input_file);
    fclose(output_file);

    return EXIT_SUCCESS;
}
