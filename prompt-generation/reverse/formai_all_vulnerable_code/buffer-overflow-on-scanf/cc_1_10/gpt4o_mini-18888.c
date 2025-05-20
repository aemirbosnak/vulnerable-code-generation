//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>

void convertToBinary(int n, char *binary) {
    int index = 0;
    // Edge case for zero
    if (n == 0) {
        binary[index++] = '0';
    }

    while (n != 0) {
        binary[index++] = (n % 2) + '0'; // Get remainder
        n /= 2; // Divide n by 2
    }

    binary[index] = '\0'; // Null-terminate string

    // Reverse the binary string
    for (int i = 0; i < index / 2; ++i) {
        char temp = binary[i];
        binary[i] = binary[index - 1 - i];
        binary[index - 1 - i] = temp;
    }
}

void displayStory() {
    printf("Welcome to the mystical world of Binary Town!\n");
    printf("Where every number has a dazzling binary equivalent.\n");
    printf("Prepare to enter a realm where numbers dance in 0s and 1s!\n");
    printf("----------------------------------------------------\n");
}

void getInputAndConvert() {
    int number;
    char binary[32]; // In this case, we choose to support 32-bit integers

    printf("Enter a decimal number to convert to binary: ");
    while (1) {
        if (scanf("%d", &number) != 1) {
            printf("Oops! That's not a valid number. Try again: ");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        break;
    }

    convertToBinary(number, binary);
    
    printf("The binary representation of %d is: %s\n\n", number, binary);
}

void mainLoop() {
    char choice;
    do {
        getInputAndConvert();
        printf("Would you like to convert another number? (y/n): ");
        fflush(stdin); // To clear the input buffer in some environments
        scanf(" %c", &choice); // Spaces before %c helps capture whitespace
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for visiting Binary Town!\n");
    printf("Remember: Each number is just a story waiting to be told.\n");
}

int main() {
    displayStory();
    mainLoop();
    return 0;
}