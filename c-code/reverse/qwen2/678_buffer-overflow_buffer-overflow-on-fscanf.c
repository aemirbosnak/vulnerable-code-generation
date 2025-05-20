#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    char word[1024];

    while (fscanf(input, "%s", word) != EOF) {
        fprintf(output, "%sAY ", word);
    }

    fclose(input);
    fclose(output);

    return 0;
}
