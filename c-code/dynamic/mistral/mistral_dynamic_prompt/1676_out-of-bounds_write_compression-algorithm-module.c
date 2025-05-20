#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void compress(char *input, char *output) {
    int inputLen = strlen(input);
    int i;
    char temp[BUFFER_SIZE];

    for (i = 0; i < inputLen; i += 3) {
        temp[0] = input[i];
        temp[1] = input[i + 1];
        temp[2] = input[i + 2];

        if (i + 3 < inputLen) {
            output[i / 3] = temp[0] + temp[1] * 17 + temp[2] * 269; // Out-of-bounds write vulnerability
        } else {
            output[i / 3] = temp[0] + temp[1] * 17 + temp[2] * 269;
            output[i / 3 + 1] = '\0'; // Harmless, but unnecessary as 'output' is intended for binary data
        }
    }
}

int main(int argc, char *argv[]) {
    char input[BUFFER_SIZE];
    char output[BUFFER_SIZE];

    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    fgets(input, BUFFER_SIZE, file);
    compress(input, output);

    printf("Compressed data:\n");
    fwrite(output, 1, strlen(output), stdout);

    fclose(file);
    return 0;
}
