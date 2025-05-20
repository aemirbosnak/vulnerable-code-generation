//Code Llama-13B DATASET v1.0 Category: Binary Converter ; Style: authentic
// Binary Converter Program

#include <stdio.h>
#include <stdlib.h>

// Function to convert binary to decimal
int binary_to_decimal(int num) {
    int decimal = 0, i = 0, rem;
    while (num != 0) {
        rem = num % 10;
        decimal += rem * pow(2, i);
        num = num / 10;
        i++;
    }
    return decimal;
}

// Function to convert decimal to binary
int decimal_to_binary(int num) {
    int binary = 0, i = 1;
    while (num != 0) {
        binary += (num % 2) * i;
        num = num / 2;
        i *= 10;
    }
    return binary;
}

// Main function
int main() {
    int choice, num;
    char ch;
    do {
        printf("Enter your choice:\n");
        printf("1. Binary to Decimal\n");
        printf("2. Decimal to Binary\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter a binary number: ");
                scanf("%d", &num);
                printf("Decimal equivalent of %d is %d\n", num, binary_to_decimal(num));
                break;
            case 2:
                printf("Enter a decimal number: ");
                scanf("%d", &num);
                printf("Binary equivalent of %d is %d\n", num, decimal_to_binary(num));
                break;
            case 3:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
        printf("Do you want to continue? (y/n) ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');
    return 0;
}