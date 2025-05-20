//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Function Declarations
void printBinary(int n);
void reverseArray(char *arr, int start, int end);
void decimalToBinary(int n);
void displayArt();

int main() {
    displayArt();
    
    int decimalNumber;
    
    // User Prompt
    printf("Enter a decimal number to convert to binary: ");
    scanf("%d", &decimalNumber);
    
    // Print the binary representation
    printf("The binary representation of %d is: ", decimalNumber);
    decimalToBinary(decimalNumber);
    
    printf("\n");
    return 0;
}

// Artistic Function to display beautiful messages
void displayArt() {
    printf("*****************************\n");
    printf("*   Welcome to Binary Land   *\n");
    printf("*****************************\n");
    printf("\n");
    printf("Here the numbers dance in binary!\n");
    printf("Let’s transform your decimal dreams!\n");
    printf("\n");
}

// Convert decimal number to binary
void decimalToBinary(int n) {
    // Creating an array to store binary characters
    char binary[32]; // Sufficient for 32-bit integers
    int index = 0;
    
    // Handling the case of 0
    if (n == 0) {
        printf("0");
        return;
    }
    
    // Convert the number to binary
    while (n > 0) {
        binary[index++] = (n % 2) + '0'; // Store the remainder
        n = n / 2; // Division by 2
    }
    
    // Reverse the array for correct order
    reverseArray(binary, 0, index - 1);
    
    // Output the binary representation
    for (int i = 0; i < index; i++) {
        printf("%c", binary[i]);
    }
}

// Reverse the character array for correct display
void reverseArray(char *arr, int start, int end) {
    char temp;
    while (start < end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}