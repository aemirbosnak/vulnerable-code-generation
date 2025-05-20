//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>

void decimal_to_hexadecimal(int decimal, char *hex) {
    int temp, i = 0;
    char buffer[20];
    
    if (decimal == 0) {
        sprintf(hex, "0");
        return;
    }

    while (decimal != 0) {
        temp = decimal % 16;
        if (temp < 10) {
            buffer[i++] = temp + '0';
        } else {
            buffer[i++] = (temp - 10) + 'A';
        }
        decimal = decimal / 16;
    }

    buffer[i] = '\0';

    for (int j = 0; j < i; j++) {
        hex[j] = buffer[i - j - 1];
    }
    hex[i] = '\0';
}

void hexadecimal_to_decimal(const char *hex, int *decimal) {
    *decimal = 0;
    while (*hex) {
        *decimal *= 16;
        if (*hex >= '0' && *hex <= '9') {
            *decimal += (*hex - '0');
        } else if (*hex >= 'A' && *hex <= 'F') {
            *decimal += (*hex - 'A' + 10);
        } else if (*hex >= 'a' && *hex <= 'f') {
            *decimal += (*hex - 'a' + 10);
        } else {
            fprintf(stderr, "Invalid hexadecimal digit: %c\n", *hex);
            exit(EXIT_FAILURE);
        }
        hex++;
    }
}

void display_menu() {
    printf("\nHexadecimal Converter\n");
    printf("1. Decimal to Hexadecimal\n");
    printf("2. Hexadecimal to Decimal\n");
    printf("3. Exit\n");
    printf("Please choose an option: ");
}

int main() {
    int choice, decimal;
    char hex[20];

    while (1) {
        display_menu();
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input. Please enter a number.\n");
            exit(EXIT_FAILURE);
        }

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                if (scanf("%d", &decimal) != 1) {
                    fprintf(stderr, "Invalid input. Please enter a valid decimal number.\n");
                    continue;
                }
                decimal_to_hexadecimal(decimal, hex);
                printf("Hexadecimal: %s\n", hex);
                break;

            case 2:
                printf("Enter a hexadecimal number: ");
                if (scanf("%s", hex) != 1) {
                    fprintf(stderr, "Invalid input. Please enter a valid hexadecimal number.\n");
                    continue;
                }
                hexadecimal_to_decimal(hex, &decimal);
                printf("Decimal: %d\n", decimal);
                break;

            case 3:
                printf("Exiting the program.\n");
                exit(EXIT_SUCCESS);

            default:
                fprintf(stderr, "Invalid option. Please choose again.\n");
        }
    }

    return 0;
}