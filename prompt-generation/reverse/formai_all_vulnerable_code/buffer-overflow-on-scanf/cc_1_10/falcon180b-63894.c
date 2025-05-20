//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 7

// Function prototypes
void generate_random_color_code(char code[MAX_CODE_LENGTH]);
int is_valid_color_code(char code[MAX_CODE_LENGTH]);
void convert_color_code(char input_code[MAX_CODE_LENGTH], char *output_color);

int main() {
    char input_code[MAX_CODE_LENGTH];
    char output_color[20];

    printf("Enter a color code (e.g. #FF0000): ");
    scanf("%s", input_code);

    if (is_valid_color_code(input_code)) {
        convert_color_code(input_code, output_color);
        printf("The color code '%s' is equivalent to '%s'.\n", input_code, output_color);
    } else {
        printf("Invalid color code.\n");
    }

    return 0;
}

// Generates a random color code in the format #RRGGBB
void generate_random_color_code(char code[MAX_CODE_LENGTH]) {
    int i;
    for (i = 0; i < MAX_CODE_LENGTH; i++) {
        if (i == 0) {
            code[i] = '#';
        } else {
            code[i] = (char) (rand() % 10 + 48);
        }
    }
    code[MAX_CODE_LENGTH - 1] = '\0';
}

// Checks if a given color code is valid
int is_valid_color_code(char code[MAX_CODE_LENGTH]) {
    if (strlen(code)!= MAX_CODE_LENGTH) {
        return 0;
    }

    if (code[0]!= '#') {
        return 0;
    }

    int i;
    for (i = 1; i < MAX_CODE_LENGTH; i++) {
        if (!isdigit(code[i])) {
            return 0;
        }
    }

    return 1;
}

// Converts a color code to its equivalent color name
void convert_color_code(char input_code[MAX_CODE_LENGTH], char *output_color) {
    int red, green, blue;

    // Extract red, green, and blue values from the input code
    sscanf(input_code, "#%02X%02X%02X", &red, &green, &blue);

    // Convert RGB values to hexadecimal format
    sprintf(output_color, "#%02X%02X%02X", red, green, blue);
}