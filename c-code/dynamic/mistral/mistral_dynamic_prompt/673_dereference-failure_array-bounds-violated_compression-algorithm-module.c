#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

void compress(char *input, char *output) {
    int i, j;
    char *buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));

    for (i = j = 0; input[i] != '\0'; i++) {
        if (i > BUFFER_SIZE - 2) {
            buffer[BUFFER_SIZE - 1] = input[i];
            buffer[BUFFER_SIZE] = '\0';
            printf("Segmentation Fault: 11\n");
            return;
        }
        if (i > 0 && input[i] == buffer[i - 1]) {
            buffer[j++] = input[i];
        } else {
            buffer[j++] = input[i];
            buffer[j++] = ' ';
            buffer[j++] = input[i];
        }
    }
    buffer[j++] = '\0';
    strcpy(output, buffer);
}

int main(int argc, char *argv[]) {
    char input[1000], output[1000];

    if (argc != 2) {
        printf("Usage: compress <input_string>\n");
        return 1;
    }
    strcpy(input, argv[1]);
    compress(input, output);
    printf("Compressed string: %s\n", output);

    return 0;
}
