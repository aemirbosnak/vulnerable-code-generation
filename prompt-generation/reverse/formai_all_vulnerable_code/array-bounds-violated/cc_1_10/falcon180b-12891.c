//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 1000

int main(int argc, char *argv[]) {

    char input_string[MAX_CHARS];
    char output_string[MAX_CHARS];
    int string_length;

    // Prompt user for input string
    printf("Enter a string to convert to color code: ");
    fgets(input_string, MAX_CHARS, stdin);

    // Remove newline character from input string
    string_length = strlen(input_string) - 1;
    input_string[string_length] = '\0';

    // Convert input string to uppercase
    for (int i = 0; i < strlen(input_string); i++) {
        input_string[i] = toupper(input_string[i]);
    }

    // Convert input string to color code
    for (int i = 0; i < strlen(input_string); i++) {
        if (input_string[i] == 'A') {
            strcat(output_string, "\033[1;31m"); // Red
        }
        else if (input_string[i] == 'B') {
            strcat(output_string, "\033[1;32m"); // Green
        }
        else if (input_string[i] == 'C') {
            strcat(output_string, "\033[1;33m"); // Yellow
        }
        else if (input_string[i] == 'D') {
            strcat(output_string, "\033[1;34m"); // Blue
        }
        else if (input_string[i] == 'E') {
            strcat(output_string, "\033[1;35m"); // Magenta
        }
        else if (input_string[i] == 'F') {
            strcat(output_string, "\033[1;36m"); // Cyan
        }
        else if (input_string[i] == 'G') {
            strcat(output_string, "\033[1;37m"); // White
        }
        else {
            strcat(output_string, &input_string[i]);
        }
    }

    // Print output string
    printf("Color code: %s\n", output_string);

    return 0;
}