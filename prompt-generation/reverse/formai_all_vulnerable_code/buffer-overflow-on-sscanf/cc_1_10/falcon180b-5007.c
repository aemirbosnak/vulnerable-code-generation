//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

void print_usage() {
    printf("Usage:./color_code_converter [input_file] [output_file]\n");
}

void read_file(char* filename, char* buffer, int* buffer_length) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    *buffer_length = ftell(file);
    rewind(file);

    buffer = malloc(*buffer_length + 1);
    if (buffer == NULL) {
        printf("Error: could not allocate memory for buffer\n");
        exit(1);
    }

    fread(buffer, *buffer_length, 1, file);
    fclose(file);
}

void write_file(char* filename, char* buffer, int buffer_length) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    fwrite(buffer, buffer_length, 1, file);
    fclose(file);
}

void convert_color_code(char* buffer, int buffer_length) {
    int i = 0;
    while (i < buffer_length) {
        if (buffer[i] == '#') {
            char hex_code[7] = {0};
            strncat(hex_code, buffer + i + 1, 6);
            int decimal_value = 0;
            sscanf(hex_code, "%x", &decimal_value);

            char rgb_code[10] = {0};
            sprintf(rgb_code, "%.2X%.2X%.2X", (decimal_value >> 16) & 0xFF, (decimal_value >> 8) & 0xFF, (decimal_value >> 0) & 0xFF);

            strncpy(buffer + i, rgb_code, strlen(rgb_code));
            i += strlen(rgb_code) - 1;
        } else {
            i++;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        print_usage();
        return 1;
    }

    char input_buffer[MAX_LENGTH];
    int input_buffer_length = 0;

    char output_buffer[MAX_LENGTH];
    int output_buffer_length = 0;

    read_file(argv[1], input_buffer, &input_buffer_length);

    convert_color_code(input_buffer, input_buffer_length);

    write_file(argv[2], output_buffer, output_buffer_length);

    printf("Conversion complete!\n");

    return 0;
}