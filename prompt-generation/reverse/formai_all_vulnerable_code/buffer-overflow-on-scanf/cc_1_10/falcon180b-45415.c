//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to check if a character is a hexadecimal digit
int is_hex_digit(char c) {
    if (c >= '0' && c <= '9') {
        return 1;
    } else if (c >= 'A' && c <= 'F') {
        return 1;
    } else if (c >= 'a' && c <= 'f') {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char input[MAX_LENGTH]; // Input string
    char output[MAX_LENGTH * 2]; // Output string
    int i, j;

    // Prompt user for input
    printf("Enter a hexadecimal number: ");
    scanf("%s", input);

    // Check if input is a valid hexadecimal number
    for (i = 0; i < strlen(input); i++) {
        if (!is_hex_digit(input[i])) {
            printf("Invalid input. Please enter a valid hexadecimal number.\n");
            exit(1);
        }
    }

    // Convert input to uppercase
    for (i = 0; i < strlen(input); i++) {
        if (is_hex_digit(input[i])) {
            input[i] = toupper(input[i]);
        }
    }

    // Convert hexadecimal to ASCII
    i = 0;
    for (j = 0; j < strlen(input); j += 2) {
        sprintf(&output[i], "%c", (int)strtol(input + j, NULL, 16));
        i++;
    }

    // Print output
    printf("The ASCII representation of %s is: %s\n", input, output);

    return 0;
}