//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
void dec_to_bin(int dec) {
    int bin = 0;
    int rem, i = 1;

    while (dec!= 0) {
        rem = dec % 2;
        bin += rem * i;
        i *= 10;
        dec /= 2;
    }

    printf("Binary equivalent of %d is %d\n", dec, bin);
}

// Function to convert binary to decimal
void bin_to_dec(int bin) {
    int dec = 0;
    int rem, i = 1;

    while (bin!= 0) {
        rem = bin % 10;
        dec += rem * i;
        i *= 2;
        bin /= 10;
    }

    printf("Decimal equivalent of %d is %d\n", bin, dec);
}

int main() {
    int choice, dec, bin;

    printf("Enter 1 for Decimal to Binary conversion\n");
    printf("Enter 2 for Binary to Decimal conversion\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter a decimal number: ");
            scanf("%d", &dec);
            dec_to_bin(dec);
            break;
        case 2:
            printf("Enter a binary number: ");
            scanf("%d", &bin);
            bin_to_dec(bin);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}