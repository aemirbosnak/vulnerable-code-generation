#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void compress(char *input, char *output) {
    char *buffer = malloc(BUFFER_SIZE);
    char *token = strtok(input, " ");
    char *next_token;

    int count = 0;

    while (token != NULL) {
        if (count++ % 2 == 0) {
            strcat(output, token);
            strcat(output, " ");
        }
        next_token = strtok(NULL, " ");
        free(token);
        token = next_token;
    }

    free(buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen(argv[2], "w");

    if (!input || !output) {
        perror("Error opening files");
        return 1;
    }

    char input_buffer[BUFFER_SIZE];
    char output_buffer[BUFFER_SIZE];

    while (fgets(input_buffer, BUFFER_SIZE, input)) {
        compress(input_buffer, output_buffer);
        fputs(output_buffer, output);
    }

    fclose(input);
    fclose(output);

    char *garbage = malloc(BUFFER_SIZE);
    // Null pointer dereference intentionally added here
    printf("%s\n", *garbage);

    return 0;
}
