//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function to convert hexadecimal to decimal
int hexToDec(char hex[]) {
    int len = 0, decVal = 0, base = 1, i;

    // count number of characters in hex string
    while (hex[len] != '\0') {
        len++;
    }

    // iterate through each character in hex string
    for (i = len - 1; i >= 0; i--) {
        // if hex character is between 0 and 9
        if (hex[i] >= '0' && hex[i] <= '9') {
            decVal += (hex[i] - 48) * base;
            base *= 16;
        }
        // if hex character is between A and F
        else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decVal += (hex[i] - 55) * base;
            base *= 16;
        }
    }

    return decVal;
}

// function to convert decimal to hexadecimal
void decToHex(int dec) {
    int rem, i = 0;
    char hex[20];

    // convert decimal to hexadecimal
    while (dec != 0) {
        rem = dec % 16;
        if (rem < 10) {
            hex[i++] = 48 + rem;
        } else {
            hex[i++] = 55 + rem;
        }
        dec /= 16;
    }

    // print hexadecimal value in reverse order
    printf("Hexadecimal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
    printf("\n");
}

int main() {
    int choice, decVal;
    char hex[20];

    printf("=========================\n");
    printf(" C Hexadecimal Converter \n");
    printf("=========================\n");
    printf("1. Hexadecimal to Decimal\n");
    printf("2. Decimal to Hexadecimal\n");
    printf("3. Exit\n");

    while (1) {
        // take user input for choice
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // take user input for hex string
                printf("Enter a hexadecimal number: ");
                scanf("%s", hex);
                // convert hex string to decimal
                decVal = hexToDec(hex);
                // print decimal value
                printf("Decimal: %d\n", decVal);
                break;
            case 2:
                // take user input for decimal value
                printf("Enter a decimal number: ");
                scanf("%d", &decVal);
                // convert decimal value to hexadecimal
                decToHex(decVal);
                break;
            case 3:
                // exit program
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}