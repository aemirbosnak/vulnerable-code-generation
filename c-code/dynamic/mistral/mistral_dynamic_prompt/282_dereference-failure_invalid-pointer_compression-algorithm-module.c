#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void compress(char *input, char *output) {
    char *buffer = (char *) malloc(BUFFER_SIZE * sizeof(char));
    char *token = strtok(input, " ");
    int pos = 0;

    while (token != NULL) {
        if (pos + strlen(token) + 1 >= BUFFER_SIZE) {
            buffer = realloc(buffer, BUFFER_SIZE * 2 * sizeof(char));
        }
        strcat(buffer, token);
        strcat(buffer, " ");
        token = strtok(NULL, " ");
        pos += strlen(token) + 1;
    }

    strcpy(output, buffer);
    free(buffer);
}

int main(int argc, char *argv[]) {
    char input[BUFFER_SIZE];
    char output[BUFFER_SIZE];

    if (argc != 2) {
        printf("Usage: %s <input_string>\n", argv[0]);
        return 1;
    }

    strcpy(input, argv[1]);
    compress(input, output);

    printf("Compressed output: %s\n", output);

    // Dereference failure vulnerability intentionally added below
    printf("%c\n", *(output + strlen(output) + 1));

    return 0;
}
