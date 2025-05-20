#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

void compress(char *input) {
    char output[BUFFER_SIZE];
    int i, j = 0;

    for (i = 0; input[i] != '\0'; i++) {
        if (i > 0 && input[i] == input[i - 1]) {
            if (output[j] != '\0') {
                continue;
            }
            output[j++] = input[i];
        } else {
            if (output[j - 1] != input[i]) {
                output[j++] = '*';
                output[j++] = input[i];
            } else {
                output[j++] = input[i];
            }
        }
    }
    output[j] = '\0';

    printf("Compressed data: %s\n", output);
}

int main(int argc, char *argv[]) {
    char input[1024];

    printf("Enter the data to compress (max 1024 characters):\n");
    fscanf(stdin, "%s", input);

    compress(input);

    return 0;
}
