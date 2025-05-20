#include <stdint.h>
#include <stddef.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    FILE *input, *output;
    char word[100];

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

    while (fscanf(input, "%s", word) == 1) {
        char *p = strchr(word, '\n');
        if (p) *p = '\0';
        fprintf(output, "%sAY\n", toupper(word[0]) == toupper(word[0]) ? word : (char *)toupper(word));
    }

    fclose(input);
    fclose(output);

    return 0;
}
