//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void print_binary(int decimal);
int get_decimal();

int main() {
    int decimal = 0;
    char choice = 'y';

    while (choice == 'y' || choice == 'Y') {
        printf("Enter a decimal number (0 to exit): ");
        scanf("%d", &decimal);

        if (decimal == 0) {
            printf("Exiting program...\n");
        } else {
            print_binary(decimal);
        }

        printf("Do you want to convert another number? (y/n): ");
        scanf(" %c", &choice);
    }

    return 0;
}

// Function to print binary equivalent of decimal number
void print_binary(int decimal) {
    char binary[33]; // Maximum 32 bits + 1 for null terminator
    int i = 0;
    int remainder;

    // Convert decimal to binary and store in string
    while (decimal > 0) {
        remainder = decimal % 2;
        binary[i] = remainder + '0';
        decimal /= 2;
        i++;
    }

    // Reverse the binary string
    for (int j = 0; j < i / 2; j++) {
        char temp = binary[j];
        binary[j] = binary[i - j - 1];
        binary[i - j - 1] = temp;
    }

    // Print the binary string
    printf("Binary equivalent: %s\n", binary);
}

// Function to get decimal number from user
int get_decimal() {
    int decimal = 0;
    char input[10];

    printf("Enter a decimal number: ");
    scanf("%s", input);

    // Check if input is a valid decimal number
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] < '0' || input[i] > '9') {
            printf("Invalid input. Please enter a decimal number.\n");
            return 0;
        }
    }

    // Convert input string to decimal
    for (int i = strlen(input) - 1; i >= 0; i--) {
        decimal += (input[i] - '0') * pow(10, strlen(input) - i - 1);
    }

    return decimal;
}