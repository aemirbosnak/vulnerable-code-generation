#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 100

void translate_word(char *word) {
    if (word[0] >= 'a' && word[0] <= 'z') {
        word[0] -= 32;
    }
    strcat(word, "ay");
}

int main(int argc, char *argv[]) {
    FILE *input, *output;
    char buffer[BUFFER_SIZE];
    int count = 0;

    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    input = fopen(argv[1], "r");
    output = fopen(argv[2], "w");

    if (!input || !output) {
        perror("Error opening files");
        return 2;
    }

    while (fscanf(input, "%s", buffer) == 1) {
        translate_word(buffer);
        fprintf(output, "%s ", buffer);
        count++;
    }

    fclose(input);
    fclose(output);

    printf("Translated %d words.\n", count);
    return 0;
}
