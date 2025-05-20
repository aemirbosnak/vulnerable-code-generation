//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: cheerful
#include <stdio.h>

void convertToHex(int num) {
    char hex[20];
    int i = 0;

    // Special case for 0
    if (num == 0) {
        printf("The hexadecimal representation is: 0\n");
        return;
    }

    // Handle negative numbers
    if (num < 0) {
        printf("Oops! Negative numbers are not our thing in this fun journey!\n");
        return;
    }

    // Start converting decimal to hexadecimal
    while (num != 0) {
        int remainder = num % 16;

        // Assigning characters for hexadecimal representation
        if (remainder < 10) {
            hex[i] = remainder + '0'; // Converts int to char
        } else {
            hex[i] = (remainder - 10) + 'A'; // Converts int to char (A-F)
        }
        i++;
        num /= 16;
    }

    printf("Yay! You've entered a number, and here comes its hexadecimal counterpart: ");

    // Print hexadecimal in reverse order
    for (int j = i - 1; j >= 0; j--) {
        putchar(hex[j]);
    }
    printf("\n");
}

int main() {
    int decimalNumber;

    // Introduction
    printf("🎉 Welcome to the Amazing Hexadecimal Converter! 🎉\n");
    printf("Enter a non-negative decimal number and we'll turn it into hexadecimal magic!\n");

    // Get user input
    printf("Please enter your number: ");
    if (scanf("%d", &decimalNumber) != 1) {
        printf("Oh no! It seems like we caught a non-integer! Please try again with a number.\n");
        return 1; // Exit with an error code
    }

    // Call conversion function
    convertToHex(decimalNumber);

    // Cheerful closing
    printf("🌟 Thanks for playing with numbers! Have a colorful day! 🌟\n");
    return 0; // Successful execution
}