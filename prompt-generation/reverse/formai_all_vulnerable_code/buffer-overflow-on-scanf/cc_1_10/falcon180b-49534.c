//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: multivariable
#include <stdio.h>

// Function to convert decimal to binary
char* decToBin(int dec) {
    static char bin[33];
    int i = 0;
    while (dec > 0) {
        bin[i++] = dec % 2 + '0';
        dec /= 2;
    }
    bin[i] = '\0';
    return bin;
}

// Function to convert binary to decimal
int binToDec(char* bin) {
    int dec = 0, base = 1;
    int len = strlen(bin);
    for (int i = len - 1; i >= 0; i--) {
        if (bin[i] == '1') {
            dec += base;
        }
        base *= 2;
    }
    return dec;
}

int main() {
    int choice, dec, bin[33];
    char input[33];

    // Menu-driven program for decimal to binary and binary to decimal conversion
    do {
        printf("\n\n******** MENU ********\n");
        printf("1. Decimal to Binary\n");
        printf("2. Binary to Decimal\n");
        printf("3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter a decimal number: ");
                scanf("%d", &dec);
                printf("\nBinary equivalent: %s\n", decToBin(dec));
                break;
            case 2:
                printf("\nEnter a binary number (up to 32 bits): ");
                scanf("%s", input);
                dec = binToDec(input);
                printf("\nDecimal equivalent: %d\n", dec);
                break;
            case 3:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice!= 3);

    return 0;
}