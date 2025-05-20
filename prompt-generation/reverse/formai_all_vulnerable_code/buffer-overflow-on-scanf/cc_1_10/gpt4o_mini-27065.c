//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Function prototype
void convertToHex(int decimal);

int main() {
    int decimal;
    char choice;

    // Welcome message
    printf("Welcome to the Hex-a-palooza Converter! 🎉\n");
    printf("Here, we turn boring old decimal numbers into hexadecimal glam!\n");
    
    do {
        // Get user input
        printf("Please enter a decimal number (no, I won't judge you!): ");
        scanf("%d", &decimal);

        // Ensuring the user gave us something acceptable (well, sort of)
        if (decimal < 0) {
            printf("Oops! Looks like you've entered a negative number.\n");
            printf("Let's pretend you meant zero instead! 😂\n");
            decimal = 0;
        }

        convertToHex(decimal);

        // Ask the user if they want to convert another number
        printf("Would you like to enter another number? (y/n): ");
        getchar(); // Cleans the input buffer. Say goodbye to that pesky newline!
        choice = getchar();

        if (choice == 'y' || choice == 'Y') {
            printf("Fantastic! Let the conversion fun continue! 🔄\n");
        } else {
            printf("No more numbers? That's okay! Go out and spread hex love! ❤️\n");
        }
    } while (choice == 'y' || choice == 'Y');

    printf("Thanks for playing! Remember, hexadecimal is just decimal's cooler cousin! 😎\n");
    return 0;
}

// A place where decimals turn into hexadecimal magic!
void convertToHex(int decimal) {
    char hex[20]; // Enough space for our hex heroes
    int index = 0;

    // If our decimal number is zero, let's not waste time
    if (decimal == 0) {
        printf("Decimal 0 in hexadecimal is... ah, drum roll please... 0! 🎺\n");
        return;
    }

    while (decimal != 0) {
        int remainder = decimal % 16;

        // Let's convert the remainder into the fabulous hexadecimal format
        if (remainder < 10) {
            hex[index] = remainder + '0'; // Don't convert to character, we're not scary!
        } else {
            hex[index] = (remainder - 10) + 'A'; // Time to get fancy with letters.
        }
        decimal /= 16; // Dividing like a pro!
        index++;
    }

    // The reverse of the hex array is how the cool kids do it
    printf("And the hexadecimal representation is: ");
    for (int j = index - 1; j >= 0; j--) {
        putchar(hex[j]);
    }
    printf("\n");
}