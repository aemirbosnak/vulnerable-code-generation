//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 100
#define MAX_OUTPUT_SIZE (MAX_INPUT_SIZE * 3)

void print_usage() {
    printf("Usage:./hex_converter [input_file] [output_file]\n");
    exit(1);
}

int main(int argc, char **argv) {
    if (argc!= 4) {
        print_usage();
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    char input_buffer[MAX_INPUT_SIZE];
    char output_buffer[MAX_OUTPUT_SIZE];

    while (fgets(input_buffer, MAX_INPUT_SIZE, input_file)!= NULL) {
        int input_size = strlen(input_buffer);
        int output_size = input_size * 3;

        for (int i = 0; i < input_size; i++) {
            char c = input_buffer[i];

            if (c >= '0' && c <= '9') {
                sprintf(output_buffer, "%02X", c - '0');
            } else if (c >= 'A' && c <= 'F') {
                sprintf(output_buffer, "%02X", c - 'A' + 10);
            } else if (c >= 'a' && c <= 'f') {
                sprintf(output_buffer, "%02X", c - 'a' + 10);
            } else {
                sprintf(output_buffer, "00");
            }

            strcat(output_buffer, " ");
        }

        strcat(output_buffer, "\n");
        fputs(output_buffer, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    printf("Conversion complete.\n");

    return 0;
}