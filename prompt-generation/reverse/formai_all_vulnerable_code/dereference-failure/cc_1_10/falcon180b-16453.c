//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char* argv[]) {
    FILE* input_file = NULL;
    FILE* output_file = NULL;
    char input_buffer[MAX_LINE_LENGTH];
    char* output_buffer = NULL;
    size_t output_buffer_size = 0;

    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening input file: %s\n", argv[1]);
        return 1;
    }

    output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error opening output file: %s\n", argv[2]);
        fclose(input_file);
        return 1;
    }

    // Read input file into buffer
    while (fgets(input_buffer, MAX_LINE_LENGTH, input_file)!= NULL) {
        // Indent each line with 4 spaces
        size_t input_buffer_length = strlen(input_buffer);
        output_buffer = realloc(output_buffer, output_buffer_size + input_buffer_length + 1);
        strcat(output_buffer, "    ");
        strcat(output_buffer, input_buffer);
        strcat(output_buffer, "\n");
        output_buffer_size += input_buffer_length + 5; // 4 spaces + newline
    }

    // Write buffer to output file
    fwrite(output_buffer, output_buffer_size, 1, output_file);

    // Free memory and close files
    free(output_buffer);
    fclose(input_file);
    fclose(output_file);

    return 0;
}