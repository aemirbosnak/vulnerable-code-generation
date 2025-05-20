//FormAI DATASET v1.0 Category: Binary Converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to convert binary to decimal
int binaryToDecimal(char *binary) {
    int decimal = 0;
    int length = strlen(binary);

    for (int i = 0; i < length; i++) {
        if (binary[i] == '1') {
            decimal += pow(2, length - 1 - i);
        }
    }

    return decimal;
}

// Function to convert decimal to binary
char* decimalToBinary(int decimal) {
    int remainder, quotient;
    char *binary = malloc(sizeof(char) * 32);
    int index = 0;

    if (binary == NULL) {
        printf("Error: Memory allocation failed.");
        exit(1);
    }

    quotient = decimal;
    while (quotient != 0) {
        remainder = quotient % 2;
        binary[index++] = remainder + '0';
        quotient /= 2;
    }

    // Reverse the binary string
    int length = strlen(binary);
    for (int i = 0; i < length / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[length - 1 - i];
        binary[length - 1 - i] = temp;
    }

    return binary;
}

int main() {
    char input[32];
    int choice;
    int decimal;
    char *binary;

    printf("Welcome to the Binary Converter program!\n");
    printf("1. Convert binary to decimal\n");
    printf("2. Convert decimal to binary\n");
    printf("Please enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter binary number: ");
        scanf("%s", input);
        decimal = binaryToDecimal(input);
        printf("Decimal equivalent: %d\n", decimal);
    } else if (choice == 2) {
        printf("Enter decimal number: ");
        scanf("%d", &decimal);
        binary = decimalToBinary(decimal);
        printf("Binary equivalent: %s\n", binary);
        free(binary);
    } else {
        printf("Invalid choice. Exiting program.\n");
    }

    return 0;
}