//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 1000
#define MAX_LINE_SIZE 80

int main(int argc, char *argv[]) {
    char input_buffer[MAX_BUFFER_SIZE];
    char output_buffer[MAX_BUFFER_SIZE];
    int input_buffer_index = 0;
    int output_buffer_index = 0;
    FILE *input_file;
    FILE *output_file;
    char *output_file_path;
    char *input_file_path = argv[1];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <input_file_path>\n", argv[0]);
        return 1;
    }

    output_file_path = malloc(strlen(input_file_path) + 5);
    strcpy(output_file_path, input_file_path);
    strcat(output_file_path, ".bin");

    output_file = fopen(output_file_path, "wb");
    if (output_file == NULL) {
        fprintf(stderr, "Error: Could not open output file.\n");
        return 1;
    }

    input_file = fopen(input_file_path, "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error: Could not open input file.\n");
        return 1;
    }

    while (fgets(input_buffer + input_buffer_index, MAX_BUFFER_SIZE - input_buffer_index, input_file)!= NULL) {
        input_buffer_index += strlen(input_buffer + input_buffer_index);
    }

    fclose(input_file);

    while (input_buffer_index > 0) {
        if (isspace(input_buffer[input_buffer_index - 1])) {
            input_buffer[input_buffer_index - 1] = '\0';
        }
        input_buffer_index--;
    }

    while (input_buffer_index > 0) {
        if (isdigit(input_buffer[input_buffer_index - 1])) {
            output_buffer[output_buffer_index++] = input_buffer[input_buffer_index - 1];
        }
        input_buffer_index--;
    }

    output_buffer[output_buffer_index] = '\0';

    fwrite(output_buffer, strlen(output_buffer), 1, output_file);

    fclose(output_file);

    printf("Conversion successful. Output saved to %s.\n", output_file_path);

    return 0;
}