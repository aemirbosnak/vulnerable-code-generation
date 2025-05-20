//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to binary
void decimalToBinary(int n) {
    // Allocate memory for the binary representation
    char binary[32];
    int index = 0;

    // Handle the case of zero explicitly
    if (n == 0) {
        printf("Decimal: %d -> Binary: 0\n", n);
        return;
    }

    // Loop to convert decimal to binary
    while (n > 0) {
        binary[index++] = (n % 2) + '0'; // Store binary digit
        n = n / 2;                       // Divide by 2
    }

    // Print the binary representation in a peaceful manner
    printf("Decimal: %d -> Binary: ", n);
    for (int j = index - 1; j >= 0; j--) {
        putchar(binary[j]);             // Print in reverse order
    }
    putchar('\n');                      // New line after printing
}

// Function to convert binary to decimal
int binaryToDecimal(const char *binaryStr) {
    int decimalValue = 0;
    int base = 1; // Initial base value (2^0)

    // Calculate the length of the binary string
    int length = strlen(binaryStr);
    
    // Loop to convert binary string to decimal
    for (int i = length - 1; i >= 0; i--) {
        // Ensure only '0' and '1' are processed
        if (binaryStr[i] == '1') {
            decimalValue += base; // Update decimal value
        }
        base *= 2; // Move to the next power of 2
    }
    return decimalValue; // Return the final decimal value
}

// Function to guide the user peacefully
void printGuide() {
    printf("Hello, dear user! Welcome to the peaceful Binary Converter.\n");
    printf("You can either convert a decimal number to binary or a binary number to decimal.\n");
    printf("To stop the program, simply enter 'exit' when prompted.\n");
    printf("Let's embark on this serene conversion journey together!\n\n");
}

// Main function to interact with the user
int main() {
    printGuide(); // Print the guide to the user

    while (1) {
        char choice[10];
        printf("Would you like to convert Decimal (D) or Binary (B)? (Type 'exit' to quit): ");
        fgets(choice, sizeof(choice), stdin); // Retrieve user input

        // Remove newline character from input
        choice[strcspn(choice, "\n")] = 0;

        // Check if the user wants to exit
        if (strcmp(choice, "exit") == 0) {
            printf("Thank you for using the Binary Converter. Stay peaceful and be well!\n");
            break;
        }

        if (strcmp(choice, "D") == 0 || strcmp(choice, "d") == 0) {
            int decimalNumber;
            printf("Please enter a decimal number: ");
            scanf("%d", &decimalNumber); // User input for decimal
            getchar(); // Consume the newline character
            decimalToBinary(decimalNumber); // Call conversion function
        } 
        else if (strcmp(choice, "B") == 0 || strcmp(choice, "b") == 0) {
            char binaryNumber[32];
            printf("Please enter a binary number: ");
            fgets(binaryNumber, sizeof(binaryNumber), stdin); // User input for binary
            binaryNumber[strcspn(binaryNumber, "\n")] = 0; // Remove newline character

            // Validate user input
            if (strspn(binaryNumber, "01") == strlen(binaryNumber)) {
                int decimalValue = binaryToDecimal(binaryNumber); // Call conversion function
                printf("Binary: %s -> Decimal: %d\n", binaryNumber, decimalValue); // Print result
            } else {
                printf("Oops! Please enter a valid binary number consisting of only 0s and 1s.\n");
            }
        } 
        else {
            printf("It seems you entered something unexpected. Let's stick to D for Decimal and B for Binary!\n");
        }
    }

    return 0; // Return success
}