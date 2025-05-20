//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 256

// Function to convert color code
void convert_color(char* input, char* output) {
    int len = strlen(input);
    char hex[3];
    memset(output, 0, MAX_COLORS);

    // Loop through each character in input string
    for (int i = 0; i < len; i++) {
        // Check if character is valid hexadecimal
        if (input[i] >= '0' && input[i] <= '9') {
            sprintf(hex, "%c", input[i]);
            strcat(output, hex);
        } else if (input[i] >= 'A' && input[i] <= 'F') {
            sprintf(hex, "%c", input[i]);
            strcat(output, hex);
        } else if (input[i] >= 'a' && input[i] <= 'f') {
            sprintf(hex, "%c", input[i]);
            strcat(output, hex);
        } else {
            printf("Invalid character: %c\n", input[i]);
            exit(1);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_color_code> <output_color_code>\n", argv[0]);
        exit(1);
    }

    // Convert input color code to hexadecimal
    char hex_input[MAX_COLORS];
    convert_color(argv[1], hex_input);

    // Convert hexadecimal to output color code
    char hex_output[MAX_COLORS];
    sprintf(hex_output, "#%s", hex_input);

    // Output result
    printf("Input color code: %s\n", argv[1]);
    printf("Output color code: %s\n", hex_output);

    return 0;
}