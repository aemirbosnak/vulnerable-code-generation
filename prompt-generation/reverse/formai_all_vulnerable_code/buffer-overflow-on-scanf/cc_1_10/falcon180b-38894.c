//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert binary to decimal
int binaryToDecimal(char* binary) {
    int decimal = 0;
    int power = 0;
    int length = strlen(binary);

    for (int i = length - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += (int) pow(2, power);
        }
        power++;
    }

    return decimal;
}

// Function to convert decimal to binary
void decimalToBinary(int decimal, char* binary) {
    int power = 0;
    int remainder = 0;

    for (int i = 0; i < 8; i++) {
        remainder = decimal % 2;
        binary[i] = remainder + '0';
        decimal /= 2;
    }
}

// Function to get user input
void getInput(char* input) {
    printf("Enter binary or decimal number: ");
    scanf("%s", input);
}

// Function to display menu
void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Binary to decimal\n");
    printf("2. Decimal to binary\n");
    printf("3. Exit\n");
}

int main() {
    char input[10];
    int choice;

    // Initialize menu
    printf("Binary Converter\n\n");
    displayMenu();

    // Get user choice
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            // Convert binary to decimal
            getInput(input);
            int decimal = binaryToDecimal(input);
            printf("Decimal: %d\n", decimal);
            break;
        case 2:
            // Convert decimal to binary
            getInput(input);
            decimalToBinary(atoi(input), input);
            printf("Binary: %s\n", input);
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}