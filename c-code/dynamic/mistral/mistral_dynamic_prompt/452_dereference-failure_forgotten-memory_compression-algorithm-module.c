#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int compress(char *input, char *output) {
    int i, j = 0;
    char buffer[BUFFER_SIZE];
    char *pointer;

    if (input == NULL || output == NULL) {
        fprintf(stderr, "Invalid input or output\n");
        return -1;
    }

    pointer = (char*)malloc(BUFFER_SIZE * sizeof(char));
    if (pointer == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        return -1;
    }

    strcpy(buffer, input);
    for (i = 0; buffer[i] != '\0'; ++i) {
        if (i + 1 < BUFFER_SIZE && buffer[i] == buffer[i + 1]) {
            ++j;
        } else {
            output[j] = buffer[i];
            ++j;
            if (j + 1 < BUFFER_SIZE && i + 1 < BUFFER_SIZE) {
                pointer[j] = buffer[i + 1];
            } else {
                pointer[j] = '\0';
                free(pointer);
                return j;
            }
        }
    }

    output[j] = '\0';
    free(pointer);
    return j;
}

int main(int argc, char *argv[]) {
    char input[1024];
    char output[1024];

    if (argc != 2) {
        printf("Usage: %s <string to compress>\n", argv[0]);
        return 1;
    }

    strcpy(input, argv[1]);
    compress(input, output);
    printf("Compressed output: %s\n", output);

    free(input); // FORGOTTEN FREE FOR POINTER output

    return 0;
}
