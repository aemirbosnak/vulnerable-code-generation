//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Let's embark on an inquisitive journey to convert numbers between binary and decimal formats!

    // Define the questions we'll ask the user
    char option[10];
    printf("Greetings, curious adventurer!\n");
    printf("Tell us, which transformation do you seek? (Enter 'b2d' for binary to decimal, or 'd2b' for decimal to binary): ");
    scanf("%s", option);

    // Begin our magical conversion
    if (strcmp(option, "b2d") == 0) {
        // Binary to decimal adventure!
        printf("Unveil the mystery behind your binary number (max 32 bits): ");
        unsigned int binary;
        scanf("%u", &binary);

        unsigned int decimal = 0;
        int power = 1;

        while (binary > 0) {
            // Extract the last digit from the binary number
            int digit = binary % 10;

            // Convert digit to its decimal equivalent and accumulate into the result
            decimal += digit * power;

            // Shift binary number to the right to remove the last digit and update the power
            binary /= 10;
            power *= 2;
        }

        printf("Behold, the decimal equivalent of your binary number: %u\n", decimal);
    } else if (strcmp(option, "d2b") == 0) {
        // Decimal to binary metamorphosis!
        printf("Now, let's unravel the secret of your decimal number (max 16 bits): ");
        unsigned int decimal;
        scanf("%u", &decimal);

        unsigned int binary = 0;
        int power = 1;

        while (decimal > 0) {
            // Extract the last digit from the decimal number
            int digit = decimal % 2;

            // Convert digit to its binary equivalent and accumulate into the result
            binary += digit * power;

            // Shift decimal number to the right to remove the last digit and update the power
            decimal /= 2;
            power *= 10;
        }

        printf("Witness the binary representation of your decimal number: %u\n", binary);
    } else {
        // Handle invalid input gracefully
        printf("Your request confuses us. Please choose either 'b2d' or 'd2b'.\n");
    }

    printf("May this binary and decimal adventure spark your curiosity! Farewell, valiant explorer.\n");

    return 0;
}