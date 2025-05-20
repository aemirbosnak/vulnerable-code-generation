//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

void decimalToHexadecimal(int decimal, char *hexadecimal) {
    int remainder, i = 0, j;
    char temp;

    if (decimal == 0) {
        hexadecimal[i++] = '0';
    } else {
        while (decimal != 0) {
            remainder = decimal % 16;
            if (remainder < 10) {
                hexadecimal[i++] = remainder + '0';
            } else {
                hexadecimal[i++] = remainder - 10 + 'A';
            }
            decimal /= 16;
        }
    }
    hexadecimal[i] = '\0';

    // Reverse the string to get the correct hexadecimal representation
    for (j = 0; j < i / 2; j++) {
        temp = hexadecimal[j];
        hexadecimal[j] = hexadecimal[i - j - 1];
        hexadecimal[i - j - 1] = temp;
    }
}

void printMenu() {
    printf("Hexadecimal Converter\n");
    printf("=====================\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    int decimal;
    char hexadecimal[10];

    while (1) {
        printMenu();
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input. Please enter a number.\n");
            exit(1);
        }

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                if (scanf("%d", &decimal) != 1) {
                    fprintf(stderr, "Invalid input. Please enter a valid decimal number.\n");
                    // Clear stdin
                    while (getchar() != '\n');
                    continue;
                }

                decimalToHexadecimal(decimal, hexadecimal);
                printf("Hexadecimal: %s\n", hexadecimal);
                break;

            case 2:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
                break;

            default:
                fprintf(stderr, "Invalid choice. Please select a valid option.\n");
                break;
        }
        printf("\n");
    }

    return 0;
}