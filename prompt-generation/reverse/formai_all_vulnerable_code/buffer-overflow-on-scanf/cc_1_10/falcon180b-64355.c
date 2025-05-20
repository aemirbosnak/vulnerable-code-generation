//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: introspective
// C Binary Converter Example Program

#include <stdio.h>

// Function to convert decimal to binary
void dec_to_bin(int dec) {
    int bin[32]; // Array to store binary digits
    int i = 0; // Index to keep track of number of binary digits

    while (dec > 0) {
        bin[i] = dec % 2; // Get remainder when divided by 2
        dec /= 2; // Divide by 2
        i++; // Increment index
    }

    // Print binary digits in reverse order
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", bin[j]);
    }
}

// Function to convert binary to decimal
int bin_to_dec(char *bin_str) {
    int dec = 0;
    int power = 0;

    while (*bin_str!= '\0') {
        if (*bin_str == '1') {
            dec += pow(2, power);
        }
        power++;
        bin_str++;
    }

    return dec;
}

int main() {
    int choice;
    char input[100];

    do {
        printf("Enter your choice:\n");
        printf("1. Decimal to Binary\n");
        printf("2. Binary to Decimal\n");
        scanf("%d", &choice);

        if (choice == 1) {
            int dec;
            printf("Enter a decimal number: ");
            scanf("%d", &dec);
            dec_to_bin(dec);
            printf("\n");
        } else if (choice == 2) {
            printf("Enter a binary number: ");
            scanf("%s", input);
            int dec = bin_to_dec(input);
            printf("Decimal equivalent: %d\n", dec);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    } while (1);

    return 0;
}