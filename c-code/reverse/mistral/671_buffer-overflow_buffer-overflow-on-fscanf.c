#include <stdint.h>
#include <stddef.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    FILE *input, *output;
    char word[256];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    input = fopen(argv[1], "r");
    if (!input) {
        perror("Error opening input file");
        return 2;
    }

    output = fopen(argv[2], "w");
    if (!output) {
        perror("Error opening output file");
        fclose(input);
        return 3;
    }

    while (fscanf(input, "%255s", word) == 1) {
        char *p = word;
        *p = toupper(*p);
        for (p++; *p; p++) {
            *p = tolower(*p);
        }
        strcat(word, "ay");
        fprintf(output, "%s\n", word);
    }

    fclose(input);
    fclose(output);
    return 0;
}
