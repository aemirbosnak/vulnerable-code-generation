//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int main(void) {
    char input[MAX_LENGTH] = "";
    char output[MAX_LENGTH] = "";
    int i, j, k;
    int hex_value;

    printf("Enter a string to convert to hexadecimal: ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove leading/trailing whitespace
    input[strcspn(input, "\n")] = '\0';
    for (i = 0; i < strlen(input); i++) {
        if (isspace(input[i])) {
            memmove(&input[i], &input[i + 1], strlen(input) - i);
            input[strlen(input) - 1] = '\0';
            i--;
        }
    }

    // Convert input to uppercase
    for (i = 0; i < strlen(input); i++) {
        input[i] = toupper(input[i]);
    }

    // Check if input is valid
    for (i = 0; i < strlen(input); i++) {
        if (!isxdigit(input[i])) {
            printf("Invalid input! Please enter a string containing only hexadecimal characters.\n");
            return 1;
        }
    }

    // Convert input to hexadecimal
    for (i = 0, j = 0; i < strlen(input); i++) {
        if (isxdigit(input[i])) {
            hex_value = input[i] - '0';
            if (hex_value > 9) {
                hex_value = hex_value - 7;
            }
            output[j++] = hex_value + '0';
        }
    }

    // Add leading zeros if necessary
    for (i = j; i < 8; i++) {
        output[i] = '0';
    }

    // Reverse the output string
    for (i = 0, k = strlen(output) - 1; i < k; i++, k--) {
        char temp = output[i];
        output[i] = output[k];
        output[k] = temp;
    }

    // Print the output
    printf("Hexadecimal representation: %s\n", output);

    return 0;
}