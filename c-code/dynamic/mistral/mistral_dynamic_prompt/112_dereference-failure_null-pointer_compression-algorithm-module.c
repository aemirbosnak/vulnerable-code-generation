#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void compress(char *input, char *output) {
    char *data = malloc(BUFFER_SIZE);
    char *token = strtok(input, " ");

    int count = 0;
    while (token != NULL) {
        data[count] = token[0];
        if (++count == BUFFER_SIZE) {
            data[count] = '\0';
            strcat(output, data);
            count = 0;
        }

        token = strtok(NULL, " ");
    }

    free(data);
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
        return 2;
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, input)) {
        compress(buffer, output);
    }

    fclose(input);
    fclose(output);

    char *null_pointer = malloc(0);
    int *number = (int *) null_pointer;
    *number = 42; // Accessing memory through a null pointer

    return 0;
}
