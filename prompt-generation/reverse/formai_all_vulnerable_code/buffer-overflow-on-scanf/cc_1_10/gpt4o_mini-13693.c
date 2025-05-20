//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: energetic
#include <stdio.h>

void convertToHex(int num) {
    char hex[20];
    int index = 0;

    while(num != 0) {
        int temp = num % 16;

        if (temp < 10) {
            hex[index] = temp + '0';
        } else {
            hex[index] = temp - 10 + 'A';
        }

        num /= 16;
        index++;
    }

    printf("The hexadecimal representation is: ");
    for (index--; index >= 0; index--) {
        putchar(hex[index]);
    }
    printf("\n");
}

void displayMenu() {
    printf("====================================\n");
    printf("      Hexadecimal Converter         \n");
    printf("====================================\n");
    printf("1. Convert a Decimal Number to Hex\n");
    printf("2. Exit the Converter              \n");
    printf("====================================\n");
}

int main() {
    int choice;
    int number;

    do {
        displayMenu();
        printf("Please enter your choice (1/2): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number to convert: ");
                scanf("%d", &number);
                if (number < 0) {
                    printf("Please enter a positive integer!\n");
                } else {
                    convertToHex(number);
                }
                break;

            case 2:
                printf("Thank you for using the Hexadecimal Converter! Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please enter 1 or 2.\n");
        }

    } while (choice != 2);

    return 0;
}