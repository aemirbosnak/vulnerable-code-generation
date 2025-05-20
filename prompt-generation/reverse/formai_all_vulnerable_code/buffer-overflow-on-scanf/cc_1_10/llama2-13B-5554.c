//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_OUTPUT_LENGTH 1024

int main(void) {
    int i, j, k;
    char input[MAX_INPUT_LENGTH];
    char output[MAX_OUTPUT_LENGTH];
    int num_digits;

    printf("Welcome to the Binary Converter! Please enter a decimal number to convert:\n");

    // Get the input number from the user
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Convert the input number to binary
    num_digits = strlen(input);
    for (i = 0; i < num_digits; i++) {
        output[i] = input[i] - '0';
    }

    // Print the binary representation of the input number
    for (i = 0; i < num_digits; i++) {
        printf("%d", output[i]);
    }

    printf("\n");

    // Ask the user if they want to convert the binary back to decimal
    printf("Do you want to convert the binary back to decimal? (y/n): ");
    scanf(" %c", &input);

    if (input[0] == 'y') {
        // Convert the binary back to decimal
        for (i = 0; i < num_digits; i++) {
            output[i] = output[i] * 2 + '0';
        }

        // Print the decimal representation of the input number
        for (i = 0; i < num_digits; i++) {
            printf("%d", output[i]);
        }

        printf("\n");
    }

    return 0;
}