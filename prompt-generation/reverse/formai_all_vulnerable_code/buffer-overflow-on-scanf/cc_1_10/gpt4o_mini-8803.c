//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>

void decimalToBinary(int n) {
    // Check for the base case of zero
    if (n == 0) {
        printf("Binary representation: 0\n");
        return;
    }

    int binaryArray[32]; // An array to hold the binary digits
    int index = 0;       // To track the current index for binaryArray

    // Loop to convert decimal to binary
    while (n > 0) {
        binaryArray[index] = n % 2; // Store the remainder (0 or 1)
        n = n / 2;                   // Divide n by 2
        index++;                     // Increment the index
    }

    printf("Binary representation: ");
    // Print the binary digits in reverse order
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binaryArray[i]);
    }
    printf("\n");
}

int main() {
    // Welcome the user with a curious note
    printf("Welcome, curious mind!\n");
    printf("Today, we shall embark on a journey from the decimal realm to the binary domain.\n\n");

    // Variable declaration for the user input
    int number;
    char choice;

    do {
        // Prompt the user
        printf("Please enter a positive decimal number (or -1 to exit): ");
        scanf("%d", &number);

        // Check if the user wants to exit the program
        if (number == -1) {
            printf("Thank you for exploring the mystical world of binary with us!\n");
            break;
        } else if (number < 0) {
            printf("Hmm, we only work with positive numbers in this adventure.\n");
            continue;
        }

        // Convert and display the binary representation
        decimalToBinary(number);

        // Ask if the user wants to continue
        printf("\nWould you like to convert another number? (y/n): ");
        scanf(" %c", &choice); // Note the space before %c to consume any newline left in buffer

    } while (choice == 'y' || choice == 'Y');

    // Farewell note
    printf("Until we meet again, fellow traveler!\n");
    return 0;
}