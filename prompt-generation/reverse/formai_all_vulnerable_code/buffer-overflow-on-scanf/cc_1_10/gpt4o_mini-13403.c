//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

void decimalToHexadecimal(int decimal, char *hex) {
    int i = 0;
    while (decimal != 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hex[i++] = remainder + '0';
        } else {
            hex[i++] = (remainder - 10) + 'A';
        }
        decimal /= 16;
    }
    hex[i] = '\0';

    // Reverse the hex string
    for (int j = 0; j < i / 2; j++) {
        char temp = hex[j];
        hex[j] = hex[i - j - 1];
        hex[i - j - 1] = temp;
    }
}

void surprisingMessage() {
    printf("🌟 Surprise! 🌟 Welcome to the Decimal to Hexadecimal Converter! 🌟\n");
    printf("Prepare yourself to witness the transformation of numbers!\n");
}

int main() {
    surprisingMessage();

    int decimalNumber;
    char hex[20];

    printf("🎉 Enter a decimal number (non-negative integer): ");
    if (scanf("%d", &decimalNumber) != 1 || decimalNumber < 0) {
        printf("😱 Uh oh! That's not a valid non-negative integer! Please run the program again.\n");
        return 1;
    }

    decimalToHexadecimal(decimalNumber, hex);

    printf("🎉 Magnificent! The hexadecimal representation of %d is: 0x%s\n", decimalNumber, hex);

    // Additional fun feature: Conversion of multiple numbers
    char choice;
    do {
        printf("Would you like to convert another decimal number? (y/n): ");
        getchar(); // To consume newline from previous input
        choice = getchar();

        if (choice == 'y' || choice == 'Y') {
            printf("🤗 Alright! Enter a new decimal number: ");
            if (scanf("%d", &decimalNumber) != 1 || decimalNumber < 0) {
                printf("😱 Oops! That's still not valid! Let's just exit now.\n");
                break;
            }
            decimalToHexadecimal(decimalNumber, hex);
            printf("🎉 Voila! The hexadecimal representation is: 0x%s\n", hex);
        } else if (choice == 'n' || choice == 'N') {
            printf("🎈 Thank you for playing! Have a hexadecimal day! 🎈\n");
        } else {
            printf("😳 Hmm, I didn’t get that. Please make sure to type 'y' or 'n'!\n");
        }
    } while (choice != 'n' && choice != 'N');

    return 0;
}