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
        if (count++ == 0) {
            strcpy(buffer, token);
        } else {
            buffer = realloc(buffer, BUFFER_SIZE * count);
            strcat(buffer, ", ");
            strcat(buffer, token);
        }
        next_token = strtok(NULL, " ");
        token = next_token;
    }

    free(buffer);
    strcpy(output, buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_string> <output_file>\n", argv[0]);
        return 1;
    }

    char input[BUFFER_SIZE];
    strcpy(input, argv[1]);
    FILE *output_file = fopen(argv[2], "w");

    if (output_file == NULL) {
        perror("Error opening output file");
        return 2;
    }

    char compressed[BUFFER_SIZE];
    compress(input, compressed);

    fprintf(output_file, "%s\n", compressed);
    fclose(output_file);

    free(compressed);
    return 0;
}
