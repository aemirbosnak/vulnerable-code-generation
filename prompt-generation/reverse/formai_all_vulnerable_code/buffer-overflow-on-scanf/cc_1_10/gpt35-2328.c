//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: paranoid
#include <stdio.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

void paranoid_clear_buffer(char * buffer, int size) {
    for (int i = 0; i < size; i++) {
        buffer[i] = '\0';
    }
}

int paranoid_hex_character_to_decimal(char hex) {
    int decimal;
    if (isdigit(hex)) {
        decimal  = hex - '0';
    } else {
        decimal = tolower(hex) - 'a' + 10;
    }
    return decimal;
}

int paranoid_hex_string_to_decimal(char * hex_string, int size) {
    int decimal = 0;
    for (int i = 0; i < size; i++) {
        int digit = paranoid_hex_character_to_decimal(hex_string[i]);
        decimal = decimal * 16 + digit;
    }
    return decimal;
}

int paranoid_decimal_to_hex_string(int decimal, char * hex_string) {
    int digits = 0;
    while (decimal > 0) {
        int digit = decimal % 16;
        if (digit < 10) {
            hex_string[digits++] = digit + '0';
        } else {
            hex_string[digits++] = digit - 10 + 'a';
        }
        decimal /= 16;
    }
    for (int i = 0; i < digits / 2; i++) {
        char temp = hex_string[i];
        hex_string[i] = hex_string[digits - i - 1];
        hex_string[digits - i - 1] = temp;
    }
    return digits;
}

void paranoid_convert_hex_to_decimal() {
    char buffer[BUFFER_SIZE];
    paranoid_clear_buffer(buffer, BUFFER_SIZE);
    printf("Enter a hexadecimal number to convert to decimal: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    int decimal = paranoid_hex_string_to_decimal(buffer, BUFFER_SIZE);
    printf("%s in hexadecimal is %d in decimal.\n", buffer, decimal);
}

void paranoid_convert_decimal_to_hex() {
    char buffer[BUFFER_SIZE];
    paranoid_clear_buffer(buffer, BUFFER_SIZE);
    int decimal;
    printf("Enter a decimal number to convert to hexadecimal: ");
    scanf("%d", &decimal);
    int digits = paranoid_decimal_to_hex_string(decimal, buffer);
    printf("%d in decimal is ", decimal);
    for (int i = 0; i < digits; i++) {
        printf("%c", buffer[i]);
    }
    printf(" in hexadecimal.\n");
}

int paranoid_menu() {
    int choice;
    printf("\n1. Convert a hexadecimal number to decimal.");
    printf("\n2. Convert a decimal number to hexadecimal.");
    printf("\n3. Exit.");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    int choice;
    do {
        choice = paranoid_menu();
        switch (choice) {
            case 1:
                paranoid_convert_hex_to_decimal();
                break;
            case 2:
                paranoid_convert_decimal_to_hex();
                break;
            case 3:
                printf("Goodbye!");
                break;
            default:
                printf("Invalid choice. Try again.");
                break;
        }
    } while (choice != 3);
    return 0;
}