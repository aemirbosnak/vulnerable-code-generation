//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert decimal to binary
void DecimalToBinary(int decimal) {
    char binary[33] = {0}; // Maximum 32 bits + null terminator
    int i = 0;

    // Iterate until the decimal becomes 0
    while (decimal!= 0) {
        // Add the remainder to the binary string
        binary[i++] = (decimal % 2) + '0';
        // Divide the decimal by 2
        decimal /= 2;
    }

    // Reverse the binary string
    for (int j = 0; j < i / 2; j++) {
        char temp = binary[j];
        binary[j] = binary[i - j - 1];
        binary[i - j - 1] = temp;
    }

    // Print the binary string
    printf("Binary: %s\n", binary);
}

// Function to convert binary to decimal
int BinaryToDecimal(char* binary) {
    int decimal = 0, power = 0;

    // Iterate through the binary string
    for (int i = strlen(binary) - 1; i >= 0; i--) {
        // If the character is 1, add 2^power to the decimal
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        // Increment the power
        power++;
    }

    return decimal;
}

int main() {
    char input[33] = {0}; // Maximum 32 bits + null terminator
    int choice;

    // Loop until the user chooses to exit
    while (1) {
        printf("\n\nChoose an option:\n");
        printf("1. Convert decimal to binary\n");
        printf("2. Convert binary to decimal\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        // Clear the input buffer
        memset(input, 0, sizeof(input));

        // Get the input from the user
        switch (choice) {
        case 1:
            printf("Enter a decimal number: ");
            scanf("%s", input);
            DecimalToBinary(atoi(input));
            break;
        case 2:
            printf("Enter a binary number: ");
            scanf("%s", input);
            printf("Decimal: %d\n", BinaryToDecimal(input));
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
    }

    return 0;
}