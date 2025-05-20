//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void convertToBinary(int number);
void displayBinary(int bits[], int size);

// This enchanting program converts decimal numbers to binary!
int main() {
    int number;
    char choice;

    printf("Welcome to the Magical Binary Converter!\n");
    printf("Transforming numbers into their binary brethren since 2023.\n\n");

    do {
        printf("Please enter a positive integer (or -1 to exit): ");
        scanf("%d", &number);

        if (number == -1) {
            printf("Exiting the magical realm. Farewell!\n");
            break;
        } else if (number < 0) {
            printf("Nay! A negative number defies the laws of binary!\n");
            continue;
        }

        printf("You entered: %d\n", number);
        printf("Here is your number in binary: ");
        convertToBinary(number);
        printf("\n");

        // Asking if they wish to convert another number
        printf("Would you like to convert another number? (y/n): ");
        getchar(); // To consume newline
        scanf("%c", &choice);
        printf("\n");

    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for visiting the Magical Binary Converter!\n");
    return 0;
}

// Function to convert the given decimal number to binary
void convertToBinary(int number) {
    int bits[32]; // Array to hold binary bits (assuming 32 bits for the purpose)
    int index = 0;

    // Fill the bits array with binary values
    while (number > 0) {
        bits[index] = number % 2; // Get the last binary bit
        number = number / 2; // Divide the number by 2
        index++;
    }

    // Display the binary representation
    displayBinary(bits, index);
}

// Function to display the binary representation in reverse order
void displayBinary(int bits[], int size) {
    for (int i = size - 1; i >= 0; i--) {
        printf("%d", bits[i]);
    }
    printf("\n");
}