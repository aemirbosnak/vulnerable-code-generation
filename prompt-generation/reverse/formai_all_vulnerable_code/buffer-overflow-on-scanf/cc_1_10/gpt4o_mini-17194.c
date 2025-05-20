//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Function declarations
void decimalToBinary(int n);
void reverseString(char str[], int length);
void swap(char *x, char *y);
void decimalToBinaryUsingArray(int n);

// Main function
int main() {
    int choice, number;
    
    printf("Welcome to the Decimal to Binary Converter Program\n");
    printf("Please choose an option:\n");
    printf("1. Convert a single decimal number to binary\n");
    printf("2. Convert a decimal number using array representation\n");
    printf("3. Exit\n");

    while (1) {
        printf("\nEnter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &number);
                printf("Binary representation of %d is: ", number);
                decimalToBinary(number);
                printf("\n");
                break;
            case 2:
                printf("Enter a decimal number: ");
                scanf("%d", &number);
                printf("Binary representation of %d using array is: ", number);
                decimalToBinaryUsingArray(number);
                printf("\n");
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }
    return 0;
}

// Function to convert decimal to binary using recursion
void decimalToBinary(int n) {
    if (n == 0) {
        return;
    }
    decimalToBinary(n / 2);
    printf("%d", n % 2);
}

// Function to convert decimal to binary using an array
void decimalToBinaryUsingArray(int n) {
    if (n == 0) {
        printf("0");
        return;
    }

    char binary[32];
    int index = 0;

    // Fill the array with binary digits
    while (n > 0) {
        binary[index] = (n % 2) + '0'; // Store the remainder as char
        n = n / 2;
        index++;
    }

    // Since the binary number is stored in reverse format,
    // we need to reverse it before printing
    reverseString(binary, index);
    binary[index] = '\0'; // Null terminate the string
    printf("%s", binary);
}

// Function to reverse a string
void reverseString(char str[], int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        swap(&str[start], &str[end]);
        start++;
        end--;
    }
}

// Function to swap two characters
void swap(char *x, char *y) {
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}