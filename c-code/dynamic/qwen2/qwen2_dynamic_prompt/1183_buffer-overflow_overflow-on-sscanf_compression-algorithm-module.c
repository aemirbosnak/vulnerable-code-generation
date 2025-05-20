#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress(const char *input, char *output) {
    int count = 1;
    char current_char = input[0];
    int input_len = 0;

    while (input[input_len] != '\0') {
        input_len++;
    }

    for (int i = 1; i <= input_len; i++) {
        if (input[i] == current_char) {
            count++;
        } else {
            sprintf(output, "%d%c", count, current_char);
            output += strlen(output);
            current_char = input[i];
            count = 1;
        }
    }
}

int main() {
    char input[256];
    char output[256];

    printf("Enter string to compress: ");
    fgets(input, sizeof(input), stdin);

    compress(input, output);

    printf("Compressed string: %s\n", output);

    return 0;
}
