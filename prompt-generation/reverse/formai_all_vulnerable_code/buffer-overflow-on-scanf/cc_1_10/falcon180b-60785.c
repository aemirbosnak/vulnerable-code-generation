//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int decimal, binary[100];
    char choice;
    int length, i;

    // Ask user for input
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    // Convert decimal to binary
    length = 0;
    while (decimal!= 0) {
        binary[length] = decimal % 2;
        decimal /= 2;
        length++;
    }

    // Print binary number
    printf("Binary number: ");
    for (i = length - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }

    // Ask user if they want to convert another number
    printf("\nConvert another number? (y/n): ");
    scanf(" %c", &choice);

    while (choice == 'y' || choice == 'Y') {
        printf("Enter a decimal number: ");
        scanf("%d", &decimal);

        // Convert decimal to binary
        length = 0;
        while (decimal!= 0) {
            binary[length] = decimal % 2;
            decimal /= 2;
            length++;
        }

        // Print binary number
        printf("\nBinary number: ");
        for (i = length - 1; i >= 0; i--) {
            printf("%d", binary[i]);
        }

        // Ask user if they want to convert another number
        printf("\nConvert another number? (y/n): ");
        scanf(" %c", &choice);
    }

    return 0;
}