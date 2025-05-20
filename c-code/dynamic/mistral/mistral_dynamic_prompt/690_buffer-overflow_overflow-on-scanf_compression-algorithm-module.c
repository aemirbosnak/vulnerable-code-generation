#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

void compress_file(char *input_file, char *output_file) {
    FILE *input, *output;
    char buffer[BUFFER_SIZE];
    unsigned int size;

    input = fopen(input_file, "r");
    output = fopen(output_file, "w");

    if (!input || !output) {
        fprintf(stderr, "Error: Could not open files.\n");
        return;
    }

    printf("Compressing file...\n");

    while ((size = fread(buffer, sizeof(char), BUFFER_SIZE, input)) > 0) {
        fwrite(buffer, sizeof(char), size, output);
    }

    fclose(input);
    fclose(output);
    printf("Compression completed.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    compress_file(argv[1], argv[2]);

    char additional_input[BUFFER_SIZE];
    printf("Enter extra data for compression (Enter to finish):\n");
    scanf("%s", additional_input);

    FILE *output_file_handle;
    output_file_handle = fopen(argv[2], "a");
    fputs(additional_input, output_file_handle);
    fclose(output_file_handle);

    return 0;
}
