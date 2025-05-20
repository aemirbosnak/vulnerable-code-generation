//Code Llama-13B DATASET v1.0 Category: Binary Converter ; Style: funny
/*
 * Binary Converter Program
 * Convert decimal to binary and vice versa
 * in a funny style
 */

#include <stdio.h>

int main() {
    int decimal, binary;
    char option;

    printf("Welcome to the Binary Converter Program\n");
    printf("Enter 'D' to convert from decimal to binary\n");
    printf("Enter 'B' to convert from binary to decimal\n");
    printf("Enter your option: ");
    scanf("%c", &option);

    if (option == 'D') {
        printf("Enter the decimal number: ");
        scanf("%d", &decimal);
        binary = decimal;
        while (binary >= 1) {
            printf("%d", binary % 2);
            binary /= 2;
        }
        printf("\nThe binary representation is: ");
        while (decimal > 0) {
            printf("%d", decimal % 2);
            decimal /= 2;
        }
    } else if (option == 'B') {
        printf("Enter the binary number: ");
        scanf("%d", &binary);
        decimal = binary;
        while (decimal >= 1) {
            printf("%d", decimal % 2);
            decimal /= 2;
        }
        printf("\nThe decimal representation is: ");
        while (binary > 0) {
            printf("%d", binary % 2);
            binary /= 2;
        }
    } else {
        printf("Invalid option, please try again.\n");
    }

    return 0;
}