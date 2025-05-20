//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 1000

// Define the color codes
enum color_codes {
    BLACK = 0,
    RED = 1,
    GREEN = 2,
    YELLOW = 3,
    BLUE = 4,
    MAGENTA = 5,
    CYAN = 6,
    WHITE = 7
};

// Define the color code table
const char *color_code_table[] = {
    "\033[0;30m", // BLACK
    "\033[0;31m", // RED
    "\033[0;32m", // GREEN
    "\033[0;33m", // YELLOW
    "\033[0;34m", // BLUE
    "\033[0;35m", // MAGENTA
    "\033[0;36m", // CYAN
    "\033[0;37m" // WHITE
};

// Define the color conversion function
void color_code_converter(char *input, char *output, enum color_codes color_code) {
    strcpy(output, color_code_table[color_code]);
    strcat(output, input);
    strcat(output, "\033[0m");
}

int main() {
    char input_string[MAX_COLORS];
    enum color_codes color_code;

    printf("Enter the input string: ");
    scanf("%[^\n]", input_string);

    printf("Enter the color code (0-7): ");
    scanf("%d", &color_code);

    color_code_converter(input_string, input_string, color_code);

    printf("%s\n", input_string);

    return 0;
}