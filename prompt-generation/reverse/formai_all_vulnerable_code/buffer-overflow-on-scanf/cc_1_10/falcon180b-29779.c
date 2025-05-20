//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// function to convert decimal to binary
void decimalToBinary(int n) {
    char bin[33]; // binary number can have maximum 32 digits + 1 for null terminator
    int i = 0;
    while (n > 0) {
        bin[i++] = n % 2 + '0';
        n /= 2;
    }
    bin[i] = '\0'; // add null terminator at the end of binary number
    printf("Binary number: %s\n", bin);
}

// function to convert binary to decimal
int binaryToDecimal(char* bin) {
    int dec = 0, i = 0, j = strlen(bin) - 1;
    while (j >= 0) {
        if (bin[j] == '1') {
            dec += pow(2, i);
        }
        i++;
        j--;
    }
    return dec;
}

// main function
int main() {
    int choice, n;
    char bin[33];

    do {
        printf("Enter 1 to convert decimal to binary\n");
        printf("Enter 2 to convert binary to decimal\n");
        printf("Enter 3 to exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &n);
                decimalToBinary(n);
                break;
            case 2:
                printf("Enter a binary number: ");
                scanf("%s", bin);
                printf("Decimal number: %d\n", binaryToDecimal(bin));
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}