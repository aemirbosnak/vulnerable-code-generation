//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

void printMenu() {
    printf("\n=== Hexadecimal Converter ===\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Convert Hexadecimal to Decimal\n");
    printf("3. Exit\n");
    printf("============================\n");
}

void decimalToHexadecimal(int decimal) {
    char hex[100];
    int index = 0;

    do {
        int remainder = decimal % 16;
        hex[index++] = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'A');
        decimal /= 16;
    } while (decimal > 0);

    printf("Hexadecimal: ");
    for (int i = index - 1; i >= 0; i--) {
        putchar(hex[i]);
    }
    putchar('\n');
}

void hexadecimalToDecimal(const char *hex) {
    int decimal = 0;
    while (*hex) {
        decimal *= 16;
        if (*hex >= '0' && *hex <= '9') {
            decimal += *hex - '0';
        } else if (*hex >= 'A' && *hex <= 'F') {
            decimal += *hex - 'A' + 10;
        } else if (*hex >= 'a' && *hex <= 'f') {
            decimal += *hex - 'a' + 10;
        } else {
            printf("Invalid Hexadecimal Input!\n");
            return;
        }
        hex++;
    }
    printf("Decimal: %d\n", decimal);
}

void handleConversion() {
    int choice;
    while (1) {
        printMenu();
        printf("Select an option: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // clear the input buffer
            continue;
        }

        if (choice == 1) {
            int decimal;
            printf("Enter a decimal number: ");
            if (scanf("%d", &decimal) != 1 || decimal < 0) {
                printf("Invalid decimal input.\n");
                while (getchar() != '\n'); // clear the input buffer
                continue;
            }
            decimalToHexadecimal(decimal);
        } else if (choice == 2) {
            char hex[100];
            printf("Enter a hexadecimal number: ");
            scanf("%s", hex);
            hexadecimalToDecimal(hex);
        } else if (choice == 3) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid option. Please select again.\n");
        }
    }
}

int main() {
    printf("Welcome to the Shape-shifting Hexadecimal Converter!\n");
    handleConversion();
    return 0;
}