//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hexToDec(char hex[]) { // converts a hexadecimal string to its equivalent decimal value
    int decimal = 0, base = 1, length = strlen(hex), i;
    for (i = length - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - '0') * base;
            base *= 16;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 55) * base;
            base *= 16;
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f') {
            decimal += (hex[i] - 87) * base;
            base *= 16;
        }
    }
    return decimal;
}

char* decToHex(int decimal) { // converts a decimal value to its equivalent hexadecimal string
    char* hex = malloc(50);
    int i = 0;
    while (decimal != 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hex[i] = remainder + 48;
            i++;
        }
        else {
            hex[i] = remainder + 55;
            i++;
        }
        decimal /= 16;
    }
    hex[i] = '\0';
    if (strlen(hex) == 0) { // if decimal == 0
        hex[0] = '0';
        hex[1] = '\0';
    }
    else if (strlen(hex) == 1) { // if decimal < 16
        hex[1] = '\0';
        hex[0] = hex[0] + 48;
    }
    else { // reverse the order of the characters
        for (int j = 0, k = strlen(hex) - 1; j < k; j++, k--) {
            char temp = hex[j];
            hex[j] = hex[k];
            hex[k] = temp;
        }
    }
    return hex;
}

int main() {
    printf("********************************* HEXADECIMAL CONVERTER *********************************\n\n");
    int choice;
    do {
        printf("Choose an option:\n");
        printf("1. Convert hexadecimal to decimal\n");
        printf("2. Convert decimal to hexadecimal\n");
        printf("3. Exit\n\n");
        printf("Enter your choice (1/2/3): ");
        scanf("%d", &choice);
        if (choice == 1) {
            char hex[50];
            printf("\nEnter a hexadecimal number: ");
            scanf("%s", hex);
            int decimal = hexToDec(hex);
            printf("\nThe decimal equivalent of %s is %d\n\n", hex, decimal);
        }
        else if (choice == 2) {
            int decimal;
            printf("\nEnter a decimal number: ");
            scanf("%d", &decimal);
            char* hex = decToHex(decimal);
            printf("\nThe hexadecimal equivalent of %d is %s\n\n", decimal, hex);
            free(hex); // deallocate the memory allocated by decToHex
        }
        else if (choice == 3) {
            printf("\nThank you for using the hexadecimal converter!\n");
            printf("Exiting...\n\n");
            break;
        }
        else {
            printf("\nInvalid choice. Please try again.\n\n");
        }
    } while (1);
    return 0;
}