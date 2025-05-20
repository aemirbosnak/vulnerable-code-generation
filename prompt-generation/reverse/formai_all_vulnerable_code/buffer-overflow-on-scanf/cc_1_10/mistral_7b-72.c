//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    int decimal;
    char binary[33];
} Converted;

bool is_valid_binary(char *binary) {
    size_t len = strlen(binary);
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (binary[i] != '0' && binary[i] != '1') {
            return false;
        }
        if (binary[i] == '1' && (i % 5) == 0 && i != len - 1) {
            count++;
            if (count > 7) {
                return false;
            }
        }
    }
    return true;
}

bool to_binary(int decimal, char *binary, int size) {
    int quotient, remainder;
    memset(binary, '\0', size);
    if (decimal == 0) {
        binary[0] = '0';
        binary[1] = '\0';
        return true;
    }
    for (int i = size - 1; i >= 0; i--) {
        quotient = decimal / 2;
        remainder = decimal % 2;
        binary[i] = remainder + '0';
        decimal = quotient;
    }
    return true;
}

void print_binary(char *binary) {
    printf("The decimal number %d is equivalent to the binary number: %s\n", getdecimalfrombinary(binary), binary);
}

int getdecimalfrombinary(char *binary) {
    int decimal = 0, base = 1;
    for (int i = strlen(binary) - 1; i >= 0; i--) {
        decimal += (binary[i] - '0') * base;
        base *= 2;
    }
    return decimal;
}

int main(int argc, char *argv[]) {
    int choice;
    Converted conversion;
    char binary[33];

    do {
        printf("1. Decimal to Binary\n");
        printf("2. Binary to Decimal\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &conversion.decimal);
                to_binary(conversion.decimal, conversion.binary, sizeof(conversion.binary));
                print_binary(conversion.binary);
                break;
            case 2:
                printf("Enter a binary number: ");
                scanf("%s", binary);
                if (is_valid_binary(binary)) {
                    conversion.decimal = getdecimalfrombinary(binary);
                    print_binary(binary);
                    printf(" is equivalent to the decimal number: %d\n", conversion.decimal);
                } else {
                    printf("Invalid binary number!\n");
                }
                break;
            case 3:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}