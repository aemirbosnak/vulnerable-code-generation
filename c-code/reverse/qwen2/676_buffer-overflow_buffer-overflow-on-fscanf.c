#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void translate_word(char *word) {
    if (*word >= 'a' && *word <= 'z') {
        *word -= 32;
    }
    strcat(word, "ay");
}

int main() {
    FILE *input_file, *output_file;
    char input_filename[100], output_filename[100];
    char word[50];

    printf("Enter input file name: ");
    scanf("%s", input_filename);
    printf("Enter output file name: ");
    scanf("%s", output_filename);

    input_file = fopen(input_filename, "r");
    if (!input_file) {
        perror("Error opening input file");
        return 1;
    }

    output_file = fopen(output_filename, "w");
    if (!output_file) {
        perror("Error opening output file");
        fclose(input_file);
        return 1;
    }

    while (fscanf(input_file, "%s", word) != EOF) {
        translate_word(word);
        fprintf(output_file, "%s ", word);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}
