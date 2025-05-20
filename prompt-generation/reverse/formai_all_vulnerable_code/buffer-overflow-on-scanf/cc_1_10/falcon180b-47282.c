//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// function to convert decimal to binary
void dec_to_bin(int dec) {
    int bin = 0, rem, i = 1;
    while (dec!= 0) {
        rem = dec % 2;
        bin += rem * i;
        dec /= 2;
        i *= 10;
    }
    printf("Binary equivalent of %d is: %d", dec, bin);
}

// function to convert binary to decimal
void bin_to_dec(char *bin) {
    int dec = 0, rem, i = strlen(bin) - 1;
    while (bin[i]!= '\0') {
        rem = bin[i] - '0';
        dec += rem * pow(2, i);
        i--;
    }
    printf("Decimal equivalent of %s is: %d", bin, dec);
}

// main function
int main() {
    int choice, dec, bin[100];
    char bin_str[100];

    // loop to perform multiple conversions
    while (1) {
        printf("\nEnter your choice:\n1. Decimal to Binary\n2. Binary to Decimal\n3. Exit");
        scanf("%d", &choice);

        // check for valid choice
        switch (choice) {
            case 1:
                // prompt user for decimal number
                printf("Enter a decimal number: ");
                scanf("%d", &dec);

                // call dec_to_bin function
                dec_to_bin(dec);
                break;

            case 2:
                // prompt user for binary number
                printf("Enter a binary number: ");
                scanf("%s", bin_str);

                // convert binary string to integer
                for (int i = 0; i < strlen(bin_str); i++) {
                    bin[i] = bin_str[i] - '0';
                }

                // call bin_to_dec function
                bin_to_dec(bin_str);
                break;

            case 3:
                // exit program
                exit(0);

            default:
                // prompt user for valid choice
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}