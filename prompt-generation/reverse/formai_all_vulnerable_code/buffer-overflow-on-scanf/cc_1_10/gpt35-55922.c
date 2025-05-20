//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Function prototypes
void displayMenu();
void hexToDecimal();
void decimalToHex();

int main(int argc, char const *argv[]) {
    int choice;

    do {
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1:
                hexToDecimal();
                break;
            case 2:
                decimalToHex();
                break;
            case 3:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n\n");
                break;
        }
    } while (choice != 3);

    return 0;
}

//Displays the menu options
void displayMenu() {
    printf("\n======= HEXADECIMAL CONVERTER =======\n");
    printf("1 - Hexadecimal to Decimal\n");
    printf("2 - Decimal to Hexadecimal\n");
    printf("3 - Quit\n");
    printf("======================================\n");
}

//Converts hexadecimal to decimal
void hexToDecimal() {
    char hex[10];
    int decimal = 0;

    printf("\nEnter a hexadecimal number (max 8 digits): ");
    fgets(hex, sizeof(hex), stdin);

    for (int i = 0; hex[i] != '\n'; i++) {
        if (isxdigit(hex[i])) {
            if (isdigit(hex[i])) {
                decimal = decimal * 16 + hex[i] - '0';
            } else {
                decimal = decimal * 16 + tolower(hex[i]) - 'a' + 10;
            }
        } else {
            printf("\nInvalid hexadecimal number. Try again.\n\n");
            return;
        }
    }

    printf("\nDecimal conversion: %d\n\n", decimal);
}

//Converts decimal to hexadecimal
void decimalToHex() {
    int decimal;
    char hex[10] = {0};
    int i = 0;

    printf("\nEnter a decimal number: ");
    scanf("%d", &decimal);
    getchar();

    while (decimal > 0) {
        int rem = decimal % 16;

        if (rem < 10) {
            hex[i] = rem + '0';
        } else {
            hex[i] = rem - 10 + 'a';
        }

        decimal /= 16;
        i++;
    }

    if (i == 0) {
        printf("\nHexadecimal conversion: 0\n\n");
    } else {
        printf("\nHexadecimal conversion: ");
        for (int j = i - 1; j >= 0; j--) {
            printf("%c", hex[j]);
        }
        printf("\n\n");
    }
}