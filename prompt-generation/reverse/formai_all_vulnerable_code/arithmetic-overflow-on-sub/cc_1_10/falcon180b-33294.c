//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 100000

int main() {
    char input[MAX_LENGTH];
    int length = 0;
    int i = 0;
    char *token;
    int decimal = 0;
    int binary[MAX_LENGTH];
    int j = 0;

    // Get user input
    printf("Enter a decimal number: ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove leading and trailing spaces
    input[strcspn(input, "\n")] = '\0';

    // Check if input is a valid decimal number
    if (!isdigit(input[0])) {
        printf("Invalid input.\n");
        return 1;
    }

    // Convert decimal to binary
    while (input[length]!= '\0') {
        decimal = decimal * 10 + input[length] - '0';
        length++;
    }

    // Reverse the binary number
    while (decimal!= 0) {
        binary[j++] = decimal % 2;
        decimal /= 2;
    }

    // Print binary number
    printf("Binary number: ");
    for (i = j - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");

    return 0;
}