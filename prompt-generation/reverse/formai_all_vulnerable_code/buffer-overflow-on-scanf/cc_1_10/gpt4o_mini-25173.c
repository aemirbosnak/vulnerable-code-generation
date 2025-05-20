//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: mathematical
#include <stdio.h>

void decimalToHexadecimal(int decimal, char *hexadecimal) {
    int remainder;
    int i = 0;

    // Handle the case when decimal is 0
    if (decimal == 0) {
        hexadecimal[i++] = '0';
    }

    while (decimal != 0) {
        remainder = decimal % 16;

        // Convert the remainder into a hexadecimal character
        if (remainder < 10) {
            hexadecimal[i++] = remainder + '0';
        } else {
            hexadecimal[i++] = remainder - 10 + 'A';
        }
        
        decimal /= 16;
    }
    
    // Reverse the hexadecimal string
    hexadecimal[i] = '\0';
    for (int j = 0; j < i / 2; j++) {
        char temp = hexadecimal[j];
        hexadecimal[j] = hexadecimal[i - j - 1];
        hexadecimal[i - j - 1] = temp;
    }
}

void displayMenu() {
    printf("\nHexadecimal Converter\n");
    printf("-----------------------\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Exit\n");
}

int main() {
    int choice;
    int decimal;
    char hexadecimal[100];

    do {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);

                // Validating the input for negativity
                if (decimal < 0) {
                    printf("Please enter a non-negative integer.\n");
                } else {
                    decimalToHexadecimal(decimal, hexadecimal);
                    printf("Decimal: %d | Hexadecimal: %s\n", decimal, hexadecimal);
                }
                break;

            case 2:
                printf("Exiting the program. Thank you for using the Hexadecimal Converter.\n");
                break;

            default:
                printf("Invalid option! Please select 1 or 2.\n");
        }
    } while (choice != 2);

    return 0;
}