//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int decimal = 0, power = 0;
    while (*binary) {
        if (*binary == '1') {
            decimal += pow(2, power);
        }
        power++;
        binary++;
    }
    return decimal;
}

int main() {
    char input[100];
    int choice, decimal;

    // Prompt user for choice
    printf("Enter 1 to convert decimal to binary\n");
    printf("Enter 2 to convert binary to decimal\n");
    scanf("%d", &choice);

    // Get input from user
    switch (choice) {
        case 1:
            printf("Enter a decimal number: ");
            scanf("%d", &decimal);
            decimal_to_binary(decimal);
            break;
        case 2:
            printf("Enter a binary number: ");
            scanf("%s", input);
            decimal = binary_to_decimal(input);
            printf("Decimal representation: %d\n", decimal);
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}