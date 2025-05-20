//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000000

int main() {
    char input_buffer[MAX_LENGTH];
    char hex_buffer[MAX_LENGTH];
    int i, j, length;
    int hex_length;
    int valid_input = 0;

    printf("Enter a string to convert to hexadecimal: ");
    fgets(input_buffer, MAX_LENGTH, stdin);
    length = strlen(input_buffer);

    // Remove newline character from input
    input_buffer[length - 1] = '\0';

    // Check for valid input
    for (i = 0; i < length; i++) {
        if (!isxdigit(input_buffer[i])) {
            printf("Invalid input. Please enter a string of hexadecimal characters only.\n");
            return 1;
        }
    }

    // Convert input to uppercase
    for (i = 0; i < length; i++) {
        input_buffer[i] = toupper(input_buffer[i]);
    }

    // Convert input to hexadecimal
    hex_length = length * 2;
    for (i = 0, j = 0; i < length; i++) {
        if (isxdigit(input_buffer[i])) {
            sprintf(&hex_buffer[j], "%02X", input_buffer[i]);
            j += 2;
        }
    }

    printf("Hexadecimal representation: ");
    for (i = 0; i < hex_length; i++) {
        printf("%c", hex_buffer[i]);
    }

    return 0;
}