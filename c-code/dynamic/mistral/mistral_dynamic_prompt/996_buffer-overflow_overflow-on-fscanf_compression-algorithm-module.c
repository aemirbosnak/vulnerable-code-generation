#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 100

void compress(char *input) {
    char output[BUFFER_SIZE];
    int i, j = 0;

    for (i = 0; input[i] != '\0'; i++) {
        if (i > 0 && input[i] == input[i - 1]) {
            if (output[j] != '\0') {
                output[j]++;
            } else {
                output[j] = input[i];
                j++;
            }
        } else {
            if (output[j] != '\0') {
                output[j] = input[i];
                j++;
            }
            output[j] = input[i];
            j++;
        }
    }

    printf("Compressed data: %s\n", output);
}

int main(int argc, char *argv[]) {
    char buffer[10];

    if (argc != 2) {
        printf("Usage: %s <input data>\n", argv[0]);
        return 1;
    }

    fscanf(stdin, "%s", buffer);
    compress(buffer);

    return 0;
}
