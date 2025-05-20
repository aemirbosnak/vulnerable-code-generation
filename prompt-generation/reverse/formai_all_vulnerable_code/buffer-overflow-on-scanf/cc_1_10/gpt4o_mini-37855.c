//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>

void convertToBinary(int n) {
    // Function to convert a number to binary
    if (n == 0) {
        printf("0");
        return;
    }
    
    int binaryNum[32];  // Array to store binary digits
    int i = 0;
    
    while (n > 0) {
        binaryNum[i] = n % 2;  // Store remainder
        n = n / 2;              // Divide the number by 2
        i++;
    }
    
    // Print the binary representation in reverse order
    printf("Binary: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryNum[j]);
    }
    printf("\n");
}

void welcomeMessage() {
    // Function to print a beautiful welcome message
    printf("\n==============================================\n");
    printf("             Welcome to Binary Converter      \n");
    printf("             Let's play with numbers!         \n");
    printf("==============================================\n\n");
}

void instruction() {
    // Function to print instructions
    printf("Enter a positive integer (or -1 to exit): ");
}

int main() {
    int number;

    welcomeMessage();

    while (1) {
        instruction();
        scanf("%d", &number);

        if (number == -1) {
            printf("Thank you for using the Binary Converter! Goodbye!\n");
            break;  // Exit the loop if the user enters -1
        }

        if (number < 0) {
            printf("Please enter a positive integer or -1 to exit. Let's try again!\n");
            continue;  // Skip the conversion if the input is negative
        }

        // Call the conversion function 
        convertToBinary(number);
    }

    return 0;
}