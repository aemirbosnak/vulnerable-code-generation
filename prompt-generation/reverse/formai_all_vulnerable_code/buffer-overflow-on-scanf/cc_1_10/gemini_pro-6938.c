//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: enthusiastic
#include <stdio.h>
#include <stdint.h>

// A symphony of functions to weave the binary magic
void decimalToBinary(uint32_t number);
void binaryToDecimal(uint32_t binary);
void printBinary(uint32_t binary);

// The grand entrance of our binary converter
int main() {
    // Welcome message, setting the tone for an engaging experience
    printf("Welcome to the Binary Converter Extravaganza!\n");
    printf("Prepare to witness the seamless transformation of numbers between decimal and binary.\n\n");

    // Prompt the user to choose a conversion direction
    uint8_t choice;
    do {
        printf("Enter your choice:\n");
        printf("1. Decimal to Binary\n");
        printf("2. Binary to Decimal\n");
        printf("3. Exit\n");
        scanf(" %hhu", &choice);
    } while (choice < 1 || choice > 3);

    // A graceful loop to handle user input and perform conversions
    uint32_t number;
    while (choice != 3) {
        switch (choice) {
            case 1:
                // Decimal to Binary conversion
                printf("Enter a decimal number: ");
                scanf(" %u", &number);
                decimalToBinary(number);
                break;
            case 2:
                // Binary to Decimal conversion
                printf("Enter a binary number: ");
                scanf(" %u", &number);
                binaryToDecimal(number);
                break;
            default:
                // An elegant exit message, bidding farewell with flair
                printf("Thank you for joining the Binary Conversion Extravaganza! Goodbye!\n");
                break;
        }

        // Prompting the user for the next conversion
        do {
            printf("\nDo you wish to continue? (1/0): ");
            scanf(" %hhu", &choice);
        } while (choice < 0 || choice > 1);
    }

    // A delightful outro, expressing gratitude for the user's participation
    printf("\nThank you for choosing our Binary Converter Extravaganza! We hope you enjoyed the experience.\n");
    return 0;
}

// An enchanting function to convert decimal numbers to binary
void decimalToBinary(uint32_t number) {
    printf("Binary representation: ");
    uint8_t binary[32];
    uint8_t index = 0;

    // A graceful loop to extract binary digits from the decimal number
    while (number > 0) {
        binary[index++] = number % 2;
        number /= 2;
    }

    // Displaying the binary digits in reverse order for a mesmerizing visual effect
    for (int i = index - 1; i >= 0; i--) {
        printf("%u", binary[i]);
    }
    printf("\n");
}

// A mystical function to convert binary numbers to decimal
void binaryToDecimal(uint32_t binary) {
    uint32_t decimal = 0;
    uint8_t power = 1;

    // A beautiful dance between the bits and the digits
    while (binary > 0) {
        if (binary % 10 == 1) {
            decimal += power;
        }
        power *= 2;
        binary /= 10;
    }

    printf("Decimal representation: %u\n", decimal);
}

// A mesmerizing function to print binary numbers in a captivating format
void printBinary(uint32_t binary) {
    printf("Binary representation: ");
    uint8_t index = 0;

    // A graceful loop to extract individual binary digits
    while (binary > 0) {
        index++;
        if (binary % 2 == 1) {
            printf("1");
        } else {
            printf("0");
        }
        binary /= 2;

        // A touch of elegance, separating binary octets with spaces
        if (index % 8 == 0 && index > 0) {
            printf(" ");
        }
    }
    printf("\n");
}