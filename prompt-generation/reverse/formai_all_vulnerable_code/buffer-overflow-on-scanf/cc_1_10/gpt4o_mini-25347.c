//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

void print_welcome_message() {
    printf("---------------------------------------------------\n");
    printf("    🎉 Welcome to the C Hexadecimal Converter! 🎉\n");
    printf("---------------------------------------------------\n");
    printf("   Convert your decimal numbers to hexadecimal easily.\n");
    printf("   Let's get started on this colorful journey! 🌈\n");
    printf("---------------------------------------------------\n");
}

void print_conversion_result(int decimal, char* hex) {
    printf("   Decimal: %d  is  Hexadecimal: %s\n", decimal, hex);
}

void convert_decimal_to_hexadecimal(int decimal) {
    char hex[20];  // Allocate space for the hexadecimal representation
    sprintf(hex, "%X", decimal); // Convert decimal to hexadecimal

    print_conversion_result(decimal, hex);
}

int main() {
    print_welcome_message();

    int number, choice;

    do {
        printf("   Please enter a non-negative decimal number to convert: ");
        if(scanf("%d", &number) != 1 || number < 0) {
            printf("   🌟 Oops! That's not a valid non-negative number. Try again! 🌟\n");
            while(getchar() != '\n'); // Clear the input buffer
            continue;
        }
        
        convert_decimal_to_hexadecimal(number);

        printf("---------------------------------------------------\n");
        printf("   Would you like to convert another number? \n");
        printf("   Press 1 for Yes or 0 to Exit: ");
        scanf("%d", &choice);

        if (choice != 1 && choice != 0) {
            printf("   🌈 That's not a valid option! No worries. 🌈\n");
            choice = 0; // Exit if invalid input for choice
        }

    } while (choice == 1);

    printf("---------------------------------------------------\n");
    printf("   🎉 Thank you for using the C Hexadecimal Converter! 🎉\n");
    printf("   Have a colorful day! 🌞\n");
    printf("---------------------------------------------------\n");

    return 0;
}