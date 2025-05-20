//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_NUM_LENGTH 1000 // Maximum length of input number

int main() {
    char input_number[MAX_NUM_LENGTH]; // Input number as a string
    int base; // Base for conversion
    int result_length; // Length of the binary result
    char *result; // Binary result as a string

    printf("Enter a number: ");
    fgets(input_number, MAX_NUM_LENGTH, stdin); // Read input number from user

    // Remove newline character from input
    input_number[strcspn(input_number, "\n")] = '\0';

    // Check if input is valid
    if (strlen(input_number) == 0 || strspn(input_number, "0123456789")!= strlen(input_number)) {
        printf("Invalid input.\n");
        return 1;
    }

    // Convert input to integer
    int number = strtol(input_number, NULL, 10);

    // Get base for conversion from user
    printf("Enter the base for conversion (2-10): ");
    scanf("%d", &base);

    // Validate base
    if (base < 2 || base > 10) {
        printf("Invalid base.\n");
        return 1;
    }

    // Convert number to binary
    result_length = (int)log10(number) + 1; // Length of binary result
    result = malloc(result_length + 1); // Allocate memory for binary result
    result[result_length] = '\0'; // Set terminating null character
    int remainder;
    while (number > 0) {
        remainder = number % base;
        result[result_length - 1] = remainder + '0';
        number /= base;
        result_length--;
    }

    // Print binary result
    printf("Binary result: %s\n", result);

    // Free allocated memory
    free(result);

    return 0;
}