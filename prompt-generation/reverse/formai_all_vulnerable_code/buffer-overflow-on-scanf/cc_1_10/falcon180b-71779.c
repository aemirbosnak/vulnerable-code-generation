//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to binary
void dec_to_bin(int n) {
    int bin[32]; // Maximum 32 bits
    int i = 0;
    while (n > 0) {
        bin[i] = n % 2;
        n /= 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", bin[j]);
    }
}

// Function to convert binary to decimal
int bin_to_dec(char *bin) {
    int n = strlen(bin);
    int dec = 0, base = 1;
    for (int i = n - 1; i >= 0; i--) {
        if (bin[i] == '1') {
            dec += base;
        }
        base *= 2;
    }
    return dec;
}

int main() {
    char input[32];
    printf("Enter a number to convert: ");
    scanf("%s", input);

    // Check if input is valid
    for (int i = 0; i < strlen(input); i++) {
        if (input[i]!= '0' && input[i]!= '1') {
            printf("Invalid input. Please enter a binary number.\n");
            return 0;
        }
    }

    // Convert binary to decimal
    int dec = bin_to_dec(input);
    printf("Decimal equivalent: %d\n", dec);

    // Convert decimal to binary
    printf("Binary equivalent: ");
    dec_to_bin(dec);
    printf("\n");

    return 0;
}