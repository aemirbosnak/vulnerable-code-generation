//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char input[100];
    char output[100];
    int i, j, len;

    // Prompt user for input
    printf("Enter a binary number: ");
    fgets(input, 100, stdin);

    // Remove newline character from input
    len = strlen(input) - 1;
    input[len] = '\0';

    // Validate input
    for (i = 0; i < strlen(input); i++) {
        if (!isdigit(input[i])) {
            printf("Invalid input. Please enter a binary number.\n");
            return 1;
        }
    }

    // Convert binary to decimal
    int decimal = 0;
    int power = 0;
    for (i = strlen(input) - 1; i >= 0; i--) {
        if (input[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }

    // Convert decimal to binary
    sprintf(output, "%d", decimal);
    for (i = strlen(output) - 1; i >= 0; i--) {
        if (output[i] == '0' || output[i] == '1') {
            j = i;
            while (j < strlen(output)) {
                output[j] = output[j + 1];
                j++;
            }
            output[strlen(output) - 1] = '\0';
        }
    }

    // Print result
    printf("Decimal equivalent: %s\n", output);

    return 0;
}