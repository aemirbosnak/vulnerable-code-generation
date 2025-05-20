//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to check if a string is a valid binary number
int is_binary(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i]!= '0' && str[i]!= '1') {
            return 0;
        }
    }
    return 1;
}

// Function to convert binary to decimal
int binary_to_decimal(char* str) {
    int len = strlen(str);
    int dec = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] == '1') {
            dec += pow(2, len - 1 - i);
        }
    }
    return dec;
}

// Function to convert decimal to binary
char* decimal_to_binary(int dec) {
    char* bin = malloc(sizeof(char) * 9);
    int len = 0;
    while (dec > 0) {
        if (dec % 2 == 1) {
            bin[len++] = '1';
        } else {
            bin[len++] = '0';
        }
        dec /= 2;
    }
    bin[len] = '\0';
    return bin;
}

int main() {
    char* input;
    int choice;

    do {
        printf("Enter a binary number: ");
        scanf("%s", input);
        if (!is_binary(input)) {
            printf("Invalid binary number!\n");
        } else {
            int dec = binary_to_decimal(input);
            printf("Decimal equivalent: %d\n", dec);
            char* bin = decimal_to_binary(dec);
            printf("Binary equivalent: %s\n", bin);
        }
        printf("Do you want to convert another number? (1 = Yes, 0 = No): ");
        scanf("%d", &choice);
    } while (choice == 1);

    return 0;
}