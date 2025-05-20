//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert binary to decimal
int binaryToDecimal(char *binary) {
    int decimal = 0, i = 0;
    while (binary[i]!= '\0') {
        if (binary[i] == '1') {
            decimal += pow(2, strlen(binary) - 1 - i);
        }
        i++;
    }
    return decimal;
}

// Function to convert decimal to binary
void decimalToBinary(int decimal) {
    char binary[100];
    int i = 0;
    while (decimal > 0) {
        binary[i] = (decimal % 2) + '0';
        decimal /= 2;
        i++;
    }
    binary[i] = '\0';
    printf("%s", binary);
}

int main() {
    char binary[100], choice;
    int decimal;

    while (1) {
        printf("Enter your choice:\n1. Binary to Decimal\n2. Decimal to Binary\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter binary number: ");
                scanf("%s", binary);
                decimal = binaryToDecimal(binary);
                printf("Decimal equivalent: %d\n", decimal);
                break;

            case '2':
                printf("Enter decimal number: ");
                scanf("%d", &decimal);
                decimalToBinary(decimal);
                break;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}