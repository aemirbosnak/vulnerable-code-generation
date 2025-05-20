//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to binary
void decimal_to_binary(int decimal) {
    char binary[33];
    int i = 0;

    // Initialize binary with zeros
    memset(binary, '0', sizeof(binary));

    // Loop through until the number becomes 0
    while (decimal > 0) {
        // Add the remainder to the beginning of the binary string
        binary[i++] = (decimal % 2) + '0';
        // Divide the number by 2
        decimal /= 2;
    }

    // Reverse the binary string
    for (int j = 0; j < i / 2; j++) {
        char temp = binary[j];
        binary[j] = binary[i - j - 1];
        binary[i - j - 1] = temp;
    }

    // Print the binary representation of the decimal number
    printf("Binary representation: %s\n", binary);
}

// Function to convert binary to decimal
int binary_to_decimal(char* binary) {
    int decimal = 0;
    int power = 0;

    // Loop through the binary string from right to left
    for (int i = strlen(binary) - 1; i >= 0; i--) {
        // If the current character is '1', add 2^power to the decimal value
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        // Increment the power for the next bit
        power++;
    }

    return decimal;
}

int main() {
    char input[33];
    int choice, decimal;

    // Loop until the user chooses to exit
    while (1) {
        // Display the menu
        printf("Menu:\n");
        printf("1. Convert decimal to binary\n");
        printf("2. Convert binary to decimal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the selected operation
        switch (choice) {
        case 1:
            // Get the decimal number from the user
            printf("Enter a decimal number: ");
            scanf("%d", &decimal);
            // Convert the decimal number to binary and print the result
            decimal_to_binary(decimal);
            break;
        case 2:
            // Get the binary number from the user
            printf("Enter a binary number: ");
            scanf("%s", input);
            // Convert the binary number to decimal and print the result
            printf("Decimal representation: %d\n", binary_to_decimal(input));
            break;
        case 3:
            // Exit the program
            exit(0);
        default:
            // Invalid choice, display an error message
            printf("Invalid choice!\n");
        }
    }

    return 0;
}