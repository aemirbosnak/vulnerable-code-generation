//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>

void printHeader() {
    printf("*****************************************\n");
    printf("*       Welcome to Hexadecimal Guru!    *\n");
    printf("*****************************************\n");
    printf("Let's convert some decimal numbers to hexadecimal!\n\n");
}

void printFooter() {
    printf("\n*****************************************\n");
    printf("*        Thank you for using Hex Guru!  *\n");
    printf("*****************************************\n");
}

void convertToHex(int decimal) {
    char hex[20];
    int index = 0;

    // Handle zero case
    if(decimal == 0) {
        printf("Decimal: 0 -> Hexadecimal: 0x0\n");
        return;
    }

    // Convert decimal to hexadecimal
    while (decimal != 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hex[index++] = remainder + '0';  // Convert int to char
        } else {
            hex[index++] = (remainder - 10) + 'A';  // Convert int to char A-F
        }
        decimal /= 16;
    }

    printf("Decimal: %d -> Hexadecimal: 0x", decimal);
    for (int i = index - 1; i >= 0; i--) {
        putchar(hex[i]);  // Print hex in reverse order
    }
    putchar('\n');
}

int main() {
    int number;
    char choice;

    printHeader();

    do {
        printf("\nPlease enter a decimal number (integer): ");
        scanf("%d", &number);

        convertToHex(number);

        printf("\nWould you like to convert another number? (y/n): ");
        scanf(" %c", &choice); // note the space before %c to handle newline

    } while (choice == 'y' || choice == 'Y');

    printFooter();

    return 0;
}