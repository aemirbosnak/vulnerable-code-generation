//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER 1000

int main() {
    char buffer[MAX_BUFFER];
    char *binary_buffer;
    int binary_length;
    int decimal_input;
    int i, j;
    char c;

    printf("Welcome to the C Binary Converter!\n");
    printf("This program will convert decimal numbers to binary.\n");
    printf("Enter a decimal number: ");
    fgets(buffer, MAX_BUFFER, stdin);

    // Remove newline character from input
    buffer[strcspn(buffer, "\n")] = '\0';

    // Check if input is valid decimal number
    if (sscanf(buffer, "%d", &decimal_input)!= 1) {
        printf("Invalid input. Please enter a valid decimal number.\n");
        return 1;
    }

    // Convert decimal to binary
    binary_length = 0;
    binary_buffer = malloc(MAX_BUFFER * sizeof(char));
    if (binary_buffer == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    while (decimal_input > 0) {
        binary_buffer[binary_length++] = (decimal_input % 2) + '0';
        decimal_input /= 2;
    }

    // Reverse binary string
    for (i = 0, j = binary_length - 1; i < j; i++, j--) {
        c = binary_buffer[i];
        binary_buffer[i] = binary_buffer[j];
        binary_buffer[j] = c;
    }

    // Print binary string
    printf("Binary representation: %s\n", binary_buffer);

    free(binary_buffer);
    return 0;
}