//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: surprised
#include <stdio.h>

// Function to convert decimal to hexadecimal
void decimalToHexadecimal(int decimal) {
    char hex[100];
    int i = 0;

    // Handle 0 case
    if (decimal == 0) {
        printf("Wow! Even zero is represented as 0x0 in hexadecimal!\n");
        return;
    }

    // Surprise! We will convert and store each digit in reverse
    while (decimal != 0) {
        int remainder = decimal % 16;
        if (remainder < 10)
            hex[i] = 48 + remainder; // Convert to ASCII for numbers 0-9
        else
            hex[i] = 87 + remainder; // Convert to ASCII for letters a-f
        decimal /= 16;
        i++;
    }
    
    printf("Surprisingly enough, here is the hexadecimal form: 0x");
    // Print in reverse order
    for (int j = i - 1; j >= 0; j--) {
        putchar(hex[j]);
    }
    printf("\n");
}

int main() {
    int number;

    // Welcome message
    printf("Welcome to the Decimal to Hexadecimal Converter!\n");
    printf("What will you convert today?\n");

    while (1) {
        printf("Please enter a positive decimal number (or a negative number to quit): ");
        scanf("%d", &number);

        // Quit if negative number is entered
        if (number < 0) {
            printf("Oh no! You decided to leave the conversion world! Goodbye!\n");
            break;
        }

        // Converting decimal to hexadecimal
        decimalToHexadecimal(number);
    }

    printf("Thank you for using the converter! I had a surprising time!\n");
    return 0;
}