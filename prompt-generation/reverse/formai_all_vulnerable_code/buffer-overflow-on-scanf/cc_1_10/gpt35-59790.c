//FormAI DATASET v1.0 Category: Binary Converter ; Style: random
#include <stdio.h>
#include <string.h>
#include <math.h>

// Function to convert binary to decimal
int binaryToDecimal(long int binary) {
    int decimal = 0, i = 0, remainder;
    while (binary != 0) {
        remainder = binary % 10;
        binary /= 10;
        decimal += remainder * pow(2, i);
        ++i;
    }
    return decimal;
}

// Function to convert decimal to binary
long int decimalToBinary(int decimal) {
    long int binary = 0;
    int remainder, i = 1;
    while (decimal != 0) {
        remainder = decimal % 2;
        decimal /= 2;
        binary += remainder * i;
        i *= 10;
    }
    return binary;
}

int main() {
    int choice;
    printf("Welcome to the Binary Converter Program!\n");
    do {
        printf("\nPlease choose an option:\n");
        printf("1. Convert binary to decimal\n");
        printf("2. Convert decimal to binary\n");
        printf("3. Exit program\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                long int binary;
                printf("Enter binary number: ");
                scanf("%ld", &binary);
                printf("Decimal equivalent: %d\n", binaryToDecimal(binary));
                break;
            }
            case 2: {
                int decimal;
                printf("Enter decimal number: ");
                scanf("%d", &decimal);
                printf("Binary equivalent: %ld\n", decimalToBinary(decimal));
                break;
            }
            case 3: {
                printf("Thanks for using the Binary Converter Program!\n");
                break;
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    } while (choice != 3);

    return 0;
}