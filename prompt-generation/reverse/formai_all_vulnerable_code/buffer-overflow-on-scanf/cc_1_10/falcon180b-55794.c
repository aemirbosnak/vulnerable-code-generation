//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to binary
void dec_to_bin(int num) {
    char binary[33];
    int i = 0;
    while (num > 0) {
        binary[i] = (num % 2) + '0';
        num /= 2;
        i++;
    }
    binary[i] = '\0';
    printf("Binary equivalent: %s\n", binary);
}

// Function to convert binary to decimal
int bin_to_dec(char* binary) {
    int decimal = 0, i = 0;
    while (binary[i]!= '\0') {
        decimal += (binary[i] - '0') * pow(2, strlen(binary) - i - 1);
        i++;
    }
    return decimal;
}

int main() {
    char input[33];
    int choice;

    // Prompt user for input
    printf("Enter a decimal number: ");
    scanf("%s", input);

    // Convert decimal to binary
    dec_to_bin(atoi(input));

    // Prompt user for choice
    printf("Enter 1 to convert binary to decimal or any other key to exit: ");
    scanf("%d", &choice);

    // Convert binary to decimal if user chooses to
    if (choice == 1) {
        printf("Enter a binary number: ");
        scanf("%s", input);
        int decimal = bin_to_dec(input);
        printf("Decimal equivalent: %d\n", decimal);
    }

    return 0;
}