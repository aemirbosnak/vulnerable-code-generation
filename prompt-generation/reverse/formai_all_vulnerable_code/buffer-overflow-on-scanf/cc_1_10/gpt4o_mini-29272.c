//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>

void print_menu() {
    printf("\n===================\n");
    printf("  Hexadecimal Converter\n");
    printf("===================\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Exit\n");
    printf("===================\n");
    printf("Please select an option (1-2): ");
}

void decimal_to_hexadecimal(int decimal) {
    char hex[20];
    int index = 0;

    if (decimal == 0) {
        printf("Hexadecimal: 0\n");
        return;
    }

    while (decimal != 0) {
        int temp = decimal % 16;
        if (temp < 10) {
            hex[index++] = temp + '0';
        } else {
            hex[index++] = (temp - 10) + 'A';
        }
        decimal /= 16;
    }

    printf("Hexadecimal: ");
    for (int i = index - 1; i >= 0; i--) {
        putchar(hex[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    int decimal_number;

    do {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimal_number);
                decimal_to_hexadecimal(decimal_number);
                break;
            case 2:
                printf("Thank you for using the Hexadecimal Converter!\n");
                break;
            default:
                printf("Invalid choice. Please enter 1 or 2.\n");
                break;
        }

    } while (choice != 2);

    return 0;
}