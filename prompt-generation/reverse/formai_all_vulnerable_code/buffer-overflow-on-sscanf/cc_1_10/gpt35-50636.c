//FormAI DATASET v1.0 Category: Color Code Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 10

void convert_input(char* input);
void print_output(char* output);

int main() {
    char input[MAX_INPUT_LENGTH];
    fgets(input, MAX_INPUT_LENGTH, stdin);
    convert_input(input);
    return 0;
}

// convert hexadecimal color code to RGB color code
void hex_to_rgb(char* input, char* output) {
    int r, g, b;
    sscanf(input, "#%02x%02x%02x", &r, &g, &b);
    sprintf(output, "RGB(%d, %d, %d)", r, g, b);
}

// convert RGB color code to hexadecimal color code
void rgb_to_hex(char* input, char* output) {
    int r, g, b;
    sscanf(input, "RGB(%d, %d, %d)", &r, &g, &b);
    sprintf(output, "#%02x%02x%02x", r, g, b);
}

// check if input is a valid hexadecimal color code
int is_hex(char* input) {
    int len = strlen(input);
    if (len != 7 || input[0] != '#') {
        return 0;
    }
    for (int i = 1; i < len; i++) {
        if (!isxdigit(input[i])) {
            return 0;
        }
    }
    return 1;
}

// check if input is a valid RGB color code
int is_rgb(char* input) {
    int r, g, b;
    return sscanf(input, "RGB(%d, %d, %d)", &r, &g, &b) == 3;
}

// convert input to either hexadecimal or RGB format
void convert_input(char* input) {
    char output[20];
    if (is_hex(input)) {
        hex_to_rgb(input, output);
        print_output(output);
    } else if (is_rgb(input)) {
        rgb_to_hex(input, output);
        print_output(output);
    } else {
        printf("Invalid input.\n");
        exit(EXIT_FAILURE);
    }
}

// print output in a pretty format
void print_output(char* output) {
    printf("Converted color code: %s\n", output);
}