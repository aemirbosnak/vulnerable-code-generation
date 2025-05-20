#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *input, *output;
    char word[10];

    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    input = fopen(argv[1], "r");
    output = fopen(argv[2], "w");

    while (fscanf(input, "%s", word) != EOF) {
        if (strlen(word) > 0) {
            strcpy(word, strcat(word, "ay"));
            word[0] = toupper(word[0]);
        } else {
            strcpy(word, "way");
        }
        fprintf(output, "%s\n", word);
    }

    fclose(input);
    fclose(output);

    return 0;
}
