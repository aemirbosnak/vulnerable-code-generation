//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert decimal to binary
void decimal_to_binary(int decimal) {
    char binary[33]; // Maximum 32 bits + null terminator
    int i = 0;
    while (decimal > 0) {
        binary[i++] = (decimal % 2) + '0';
        decimal /= 2;
    }
    binary[i] = '\0';
    printf("Binary representation: %s\n", binary);
}

// Function to convert binary to decimal
int binary_to_decimal(char* binary) {
    int decimal = 0;
    int power = 0;
    int length = strlen(binary);
    for (int i = length - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }
    return decimal;
}

int main() {
    char input[33];
    int choice;

    // Welcome message
    printf("Welcome to the Binary Converter!\n");
    printf("Enter 1 to convert decimal to binary.\n");
    printf("Enter 2 to convert binary to decimal.\n");
    printf("Enter 3 to exit.\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter a decimal number: ");
            scanf("%s", input);
            decimal_to_binary(atoi(input));
            break;
        case 2:
            printf("Enter a binary number: ");
            scanf("%s", input);
            int decimal = binary_to_decimal(input);
            printf("Decimal representation: %d\n", decimal);
            break;
        case 3:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}