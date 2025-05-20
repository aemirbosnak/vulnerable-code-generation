//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NUM_SIZE 32
#define BINARY_SIZE 9

int main() {
    char input[MAX_NUM_SIZE];
    char binary[BINARY_SIZE];
    int i, j, num;

    printf("Enter a decimal number: ");
    fgets(input, MAX_NUM_SIZE, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    // Check if input is valid decimal number
    for (i = 0; i < strlen(input); i++) {
        if (!isdigit(input[i])) {
            printf("Invalid input. Please enter a valid decimal number.\n");
            return 1;
        }
    }

    num = atoi(input);

    // Convert decimal to binary
    for (i = 0; i < BINARY_SIZE; i++) {
        binary[i] = '0';
    }
    j = 0;
    while (num > 0) {
        binary[j] = (num % 2) + '0';
        num /= 2;
        j++;
    }

    // Reverse binary string
    for (i = 0; i < j / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[j - i - 1];
        binary[j - i - 1] = temp;
    }

    printf("Binary equivalent: %s\n", binary);

    return 0;
}