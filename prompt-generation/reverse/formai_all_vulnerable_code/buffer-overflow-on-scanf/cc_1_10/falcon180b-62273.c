//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Function to convert decimal to hexadecimal
void decimal_to_hexadecimal(int decimal, char* hexadecimal) {
    int i = 0;
    int remainder;

    while (decimal!= 0) {
        remainder = decimal % 16;
        if (remainder < 10) {
            sprintf(&hexadecimal[i], "%d", remainder);
        } else {
            sprintf(&hexadecimal[i], "%c", remainder + 55);
        }
        decimal /= 16;
        i++;
    }

    hexadecimal[i] = '\0';
}

// Function to convert hexadecimal to decimal
int hexadecimal_to_decimal(char* hexadecimal) {
    int decimal = 0;
    int i = 0;

    while (hexadecimal[i]!= '\0') {
        if (isdigit(hexadecimal[i])) {
            decimal = decimal * 16 + hexadecimal[i] - '0';
        } else {
            decimal = decimal * 16 + hexadecimal[i] - 'A' + 10;
        }
        i++;
    }

    return decimal;
}

int main() {
    char hexadecimal[100];
    int decimal;
    int choice;

    do {
        printf("Enter 1 to convert decimal to hexadecimal\n");
        printf("Enter 2 to convert hexadecimal to decimal\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                decimal_to_hexadecimal(decimal, hexadecimal);
                printf("Hexadecimal representation: %s\n", hexadecimal);
                break;
            case 2:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexadecimal);
                decimal = hexadecimal_to_decimal(hexadecimal);
                printf("Decimal representation: %d\n", decimal);
                break;
            default:
                printf("Invalid choice!\n");
        }

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}