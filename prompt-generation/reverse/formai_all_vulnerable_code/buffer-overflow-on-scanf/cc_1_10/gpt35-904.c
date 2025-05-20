//FormAI DATASET v1.0 Category: Binary Converter ; Style: medieval
#include <stdio.h>
#include <string.h>

// This is the header for our binary conversion function
void binary_converter(int decimal_number);

int main() {
    // Declare and initialize variable to store decimal input
    int decimal_input = 0;
    
    // Ask user for decimal input
    printf("Enter a decimal number to convert to binary: ");
    
    // Read user input
    scanf("%d", &decimal_input);
    
    // Call binary conversion function with user input as argument
    binary_converter(decimal_input);
    
    return 0;
}


// Function that converts decimal numbers to binary numbers
void binary_converter(int decimal_number) {
    // Declare and initialize array to hold binary digits
    int binary_digits[32] = {0};
    
    // Declare and initialize counter variables
    int i = 0;
    int j = 0;
    
    // Loop through decimal number and convert to binary digits
    while (decimal_number > 0) {
        binary_digits[i] = decimal_number % 2;
        decimal_number = decimal_number / 2;
        i++;
    }
    
    // Print out binary digits in reverse order
    printf("The binary conversion of the input is: ");
    for (j = i - 1; j >= 0; j--) {
        printf("%d", binary_digits[j]);
    }
    
    // Print out a medieval-style message!
    printf("\n");
    printf("Hark, good sir! Thou hast witnessed the conversion of decimal to binary.\n");
    printf("Mayhaps this knowledge shall aid thee in thy future endeavors!\n");
    printf("Fare thee well!\n");
}