//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function prototypes
void displayInstructions();
void decToBin(int num);
void binToDec(char binStr[]);

int main() {
    int choice, number;
    char binStr[32];

    displayInstructions();

    while (1) {
        printf("Enter your choice (1 for Decimal to Binary, 2 for Binary to Decimal, 0 to exit): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a positive integer to convert to binary: ");
                scanf("%d", &number);
                if (number < 0) {
                    printf("Please enter a non-negative number!\n");
                } else {
                    printf("Binary representation of %d is: ", number);
                    decToBin(number);
                    printf("\n");
                }
                break;

            case 2:
                printf("Enter a binary number (e.g., 1011): ");
                scanf("%s", binStr);
                binToDec(binStr);
                break;

            case 0:
                printf("Exiting the converter. Have a great day!\n");
                exit(0);

            default:
                printf("Invalid choice! Please choose again.\n");
                break;
        }
        printf("\n");
    }

    return 0;
}

// Function to display instructions
void displayInstructions() {
    printf("****************************************\n");
    printf("Welcome to the Mind-Bending Binary Converter!\n");
    printf("****************************************\n");
    printf("This program can convert:\n");
    printf("1. A decimal integer to binary representation.\n");
    printf("2. A binary string to its decimal equivalent.\n");
}

// Function to convert decimal to binary
void decToBin(int num) {
    if (num > 1) {
        decToBin(num / 2);
    }
    printf("%d", num % 2);
}

// Function to convert binary string to decimal
void binToDec(char binStr[]) {
    int length = strlen(binStr);
    int decimalValue = 0;

    for (int i = 0; i < length; i++) {
        if (binStr[i] == '1') {
            decimalValue += (1 << (length - 1 - i));
        } else if (binStr[i] != '0') {
            printf("Invalid binary input! Please enter a valid binary string.\n");
            return;
        }
    }

    printf("Decimal representation of %s is: %d\n", binStr, decimalValue);
}