//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

void printLine() {
    printf("-------------------------------\n");
}

void welcomeMessage() {
    printf("🎉 Welcome to the Hexadecimal Converter! 🎉\n");
    printLine();
    printf("Convert your decimal numbers to hexadecimal with ease!\n");
    printLine();
}

void toHexadecimal(int decimal, char hex[]) {
    int i = 0;
    while (decimal != 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hex[i] = remainder + '0';
        } else {
            hex[i] = remainder - 10 + 'A'; // Convert to hexadecimal representation
        }
        decimal /= 16;
        i++;
    }
    hex[i] = '\0'; // Null-terminate the string

    // Reverse the string to display it in the correct order
    for (int j = 0; j < i / 2; j++) {
        char temp = hex[j];
        hex[j] = hex[i - j - 1];
        hex[i - j - 1] = temp;
    }
}

int main() {
    welcomeMessage();

    int decimalNumber;
    char hexNumber[20]; // Buffer to hold the hexadecimal string

    while (1) {
        printLine();
        printf("Please enter a decimal number (or type -1 to exit): ");
        scanf("%d", &decimalNumber);

        if (decimalNumber == -1) {
            printf("🌟 Thank you for using the Hexadecimal Converter! 🌟\n");
            break; // Exit the loop if the user types -1
        } else if (decimalNumber < 0) {
            printf("❌ Please enter a positive decimal number!\n");
            continue; // Prompt again if the number is negative
        }

        toHexadecimal(decimalNumber, hexNumber);
        printf("The hexadecimal representation of %d is: %s\n", decimalNumber, hexNumber);
    }

    return 0;
}