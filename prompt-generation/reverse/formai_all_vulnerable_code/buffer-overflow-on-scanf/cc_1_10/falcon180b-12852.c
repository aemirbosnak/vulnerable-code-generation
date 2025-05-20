//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

/* Function to convert binary to decimal */
int binaryToDecimal(int binary) {
    int decimal = 0;
    int power = 0;
    while (binary!= 0) {
        decimal += (binary % 10) * pow(2, power);
        binary /= 10;
        power++;
    }
    return decimal;
}

/* Function to convert decimal to binary */
void decimalToBinary(int decimal) {
    char binary[33];
    int i = 0;
    while (decimal!= 0) {
        binary[i] = decimal % 2 + '0';
        decimal /= 2;
        i++;
    }
    printf("%s", binary);
}

/* Function to display menu */
void displayMenu() {
    printf("*** Post-Apocalyptic Binary Converter ***\n");
    printf("1. Binary to Decimal\n");
    printf("2. Decimal to Binary\n");
    printf("3. Exit\n");
}

/* Main function */
int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter binary number: ");
                int binary;
                scanf("%d", &binary);
                printf("Decimal equivalent: %d\n", binaryToDecimal(binary));
                break;
            case 2:
                printf("Enter decimal number: ");
                int decimal;
                scanf("%d", &decimal);
                decimalToBinary(decimal);
                printf("\n");
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);
    return 0;
}