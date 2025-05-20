#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 1024

void compress(char *input, char *output) {
    int i, j = 0;

    for (i = 0; input[i] != '\0'; i++) {
        if (i > MAX_INPUT_SIZE) {
            printf("Input string too long.\n");
            exit(1);
        }
        if (input[i] == input[j]) {
            output[j] = input[i];
            j++;
        } else {
            output[j] = input[i];
            j++;
            output[j] = input[j] == '\0' ? input[i] : output[j - 1];
        }
    }
    output[j] = '\0';
}

int main(int argc, char *argv[]) {
    char input[MAX_INPUT_SIZE];
    char output[MAX_INPUT_SIZE];

    if (argc != 2) {
        printf("Usage: compress <input_string>\n");
        return 1;
    }

    strcpy(input, argv[1]);

    compress(input, output);
    printf("Compressed string: %s\n", output);

    return 0;
}
