//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 100

int main() {
    char binary[MAX_BUFFER_SIZE];
    char input[MAX_BUFFER_SIZE];
    int i = 0;
    int j = 0;
    int len = 0;
    int decimal = 0;
    int sign = 1;

    // Get user input
    printf("Enter a decimal number: ");
    fgets(input, MAX_BUFFER_SIZE, stdin);

    // Remove newline character
    len = strlen(input);
    if (input[len - 1] == '\n') {
        input[len - 1] = '\0';
        len--;
    }

    // Check for negative sign
    if (input[0] == '-') {
        sign = -1;
        i++;
    }

    // Convert decimal to binary
    while (i < len) {
        if (isdigit(input[i])) {
            decimal = decimal * 10 + input[i] - '0';
        } else {
            printf("Invalid input.\n");
            return 1;
        }
        i++;
    }

    // Reverse binary representation
    while (decimal > 0) {
        binary[j++] = (decimal % 2) + '0';
        decimal /= 2;
    }

    // Add leading zeros if necessary
    while (j < MAX_BUFFER_SIZE) {
        binary[j++] = '0';
    }

    // Print binary representation
    printf("Binary representation: ");
    for (i = j - 1; i >= 0; i--) {
        printf("%c", binary[i]);
    }

    return 0;
}