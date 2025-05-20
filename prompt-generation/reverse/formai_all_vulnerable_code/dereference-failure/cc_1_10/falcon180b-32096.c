//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

// Function to read a line from the input file
char* read_line(FILE* input_file) {
    char* line = malloc(MAX_LINE_LENGTH);
    if (fgets(line, MAX_LINE_LENGTH, input_file) == NULL) {
        fprintf(stderr, "Error reading line from input file\n");
        exit(1);
    }
    return line;
}

// Function to parse a color code in the format #RRGGBB
int parse_color_code(char* color_code) {
    int value = 0;
    int i = 0;
    while (i < strlen(color_code)) {
        if (color_code[i] == '#') {
            i++;
        }
        if (color_code[i] >= '0' && color_code[i] <= '9') {
            value = value * 16 + (color_code[i] - '0');
        } else if (color_code[i] >= 'A' && color_code[i] <= 'F') {
            value = value * 16 + (color_code[i] - 'A' + 10);
        } else if (color_code[i] >= 'a' && color_code[i] <= 'f') {
            value = value * 16 + (color_code[i] - 'a' + 10);
        } else {
            fprintf(stderr, "Invalid character in color code\n");
            exit(1);
        }
        i++;
    }
    return value;
}

// Function to convert a color code from hex to RGB
void convert_color_code(int color_code, int* red, int* green, int* blue) {
    *red = (color_code >> 16) & 0xff;
    *green = (color_code >> 8) & 0xff;
    *blue = color_code & 0xff;
}

// Function to write the converted color code to the output file
void write_converted_color_code(FILE* output_file, int color_code) {
    char* color_string = malloc(8);
    sprintf(color_string, "#%06x", color_code);
    fprintf(output_file, "%s\n", color_string);
    free(color_string);
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        exit(1);
    }
    FILE* input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening input file\n");
        exit(1);
    }
    FILE* output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error opening output file\n");
        exit(1);
    }
    char* line = read_line(input_file);
    while (line!= NULL) {
        int color_code = parse_color_code(line);
        int red, green, blue;
        convert_color_code(color_code, &red, &green, &blue);
        write_converted_color_code(output_file, color_code);
        line = read_line(input_file);
    }
    fclose(input_file);
    fclose(output_file);
    return 0;
}