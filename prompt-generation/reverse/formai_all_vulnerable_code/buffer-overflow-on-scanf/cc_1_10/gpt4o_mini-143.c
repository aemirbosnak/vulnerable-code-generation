//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: beginner-friendly
#include <stdio.h>

void decimalToHexadecimal(int decimalValue);

int main() {
    int decimalNumber;

    // Display program title
    printf("====================================\n");
    printf("   Decimal to Hexadecimal Converter  \n");
    printf("====================================\n");

    // Prompt the user to enter a decimal number
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    // Validate if the input is a non-negative integer
    if (decimalNumber < 0) {
        printf("Please enter a non-negative integer.\n");
    } else {
        // Call the function to convert and display hexadecimal
        printf("Hexadecimal representation of %d is: ", decimalNumber);
        decimalToHexadecimal(decimalNumber);
        printf("\n");
    }

    return 0;
}

void decimalToHexadecimal(int decimalValue) {
    // An array to store the hexadecimal digits
    char hexDigits[100];
    int index = 0;

    // Handle the zero case explicitly
    if (decimalValue == 0) {
        printf("0");
        return;
    }

    // Loop to convert decimal to hexadecimal
    while (decimalValue != 0) {
        int remainder = decimalValue % 16; // Get the remainder

        // Convert remainder to the corresponding hex character
        if (remainder < 10) {
            hexDigits[index++] = remainder + '0'; // convert int to char
        } else {
            hexDigits[index++] = (remainder - 10) + 'A'; // convert int to char (A-F)
        }

        // Update the decimal number by dividing it by 16
        decimalValue /= 16;
    }

    // Print the hexDigits array in reverse order as we've built it backwards
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", hexDigits[i]);
    }
}