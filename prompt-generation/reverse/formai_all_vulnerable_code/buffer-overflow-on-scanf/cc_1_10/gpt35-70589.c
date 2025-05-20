//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hex_to_int(char hex[], int* decimal) {
    int length = strlen(hex);
    int base = 1;
    *decimal = 0;
    for (int i = length - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            *decimal += (hex[i] - 48) * base;
            base = base * 16;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F') {
            *decimal += (hex[i] - 55) * base;
            base = base * 16;
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f') {
            *decimal += (hex[i] - 87) * base;
            base = base * 16;
        }
    }
}

void int_to_hex(int decimal, char hex[]) {
    int i = 0;
    while (decimal != 0) {
        int temp = 0;
        temp = decimal % 16;
        if (temp < 10) {
            hex[i] = temp + 48;
            i++;
        }
        else {
            hex[i] = temp + 55;
            i++;
        }
        decimal /= 16;
    }
    hex[i] = '\0';
    // Reverse the hex string
    for (int j = 0; j < i / 2; j++) {
        char temp = hex[j];
        hex[j] = hex[i - 1 - j];
        hex[i - 1 - j] = temp;
    }
}

int main() {
    char hex_input[50];
    int dec_output;
    printf("Welcome to the Hexadecimal Converter program.\n");
    while (1) {
        printf("1. Convert hex to decimal\n");
        printf("2. Convert decimal to hex\n");
        printf("3. Exit the program\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("\nEnter the hexadecimal number to convert: ");
            scanf("%s", hex_input);
            hex_to_int(hex_input, &dec_output);
            printf("Decimal value: %d\n", dec_output);
            break;
        case 2:
            printf("\nEnter the decimal number to convert: ");
            scanf("%d", &dec_output);
            int_to_hex(dec_output, hex_input);
            printf("Hexadecimal value: %s\n", hex_input);
            break;
        case 3:
            printf("\nThank you for using the program.\n");
            exit(0);
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
            break;
        }
    }
    return 0;
}