//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to binary
void decimal_to_binary(int decimal) {
    char binary[33]; // Binary number can have maximum of 32 bits (1 sign bit + 31 value bits)
    int i = 0;
    sprintf(binary, "%b", decimal); // Convert decimal to binary using sprintf
    printf("Binary representation of %d is: %s\n", decimal, binary);
}

// Function to convert binary to decimal
int binary_to_decimal(char binary[]) {
    int decimal = 0, i = 0;
    while (binary[i]!= '\0') {
        if (binary[i] == '1') {
            decimal += pow(2, strlen(binary) - i - 1);
        }
        i++;
    }
    return decimal;
}

int main() {
    int choice, decimal;
    char binary[33];

    do {
        printf("\n");
        printf("1. Decimal to Binary\n");
        printf("2. Binary to Decimal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                decimal_to_binary(decimal);
                break;
            case 2:
                printf("Enter a binary number: ");
                scanf("%s", binary);
                printf("Decimal representation of %s is: %d\n", binary, binary_to_decimal(binary));
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice!= 3);

    return 0;
}