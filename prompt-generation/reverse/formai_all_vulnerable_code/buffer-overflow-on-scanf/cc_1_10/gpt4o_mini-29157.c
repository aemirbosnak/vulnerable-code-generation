//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: Dennis Ritchie
#include <stdio.h>

void convertToBinary(int num) {
    if (num == 0) {
        printf("0\n");
        return;
    }

    int binary[32];
    int index = 0;

    while (num > 0) {
        binary[index] = num % 2;  // Store remainder
        num = num / 2;             // Divide num by 2
        index++;
    }

    // Print binary representation in reverse order
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

int main() {
    int number;
    char choice;

    printf("Welcome to the Decimal to Binary Converter!\n");

    do {
        printf("Please enter a positive integer: ");
        if (scanf("%d", &number) != 1 || number < 0) {
            printf("Invalid input! Please enter a positive integer.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue; // prompt again
        }

        printf("The binary representation of %d is: ", number);
        convertToBinary(number);

        printf("Do you want to convert another number? (y/n): ");
        while (getchar() != '\n'); // flush newline from input buffer
        choice = getchar();
        
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the converter. Goodbye!\n");
    return 0;
}