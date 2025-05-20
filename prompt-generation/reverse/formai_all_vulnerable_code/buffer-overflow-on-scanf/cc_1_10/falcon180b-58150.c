//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1024

char *binary_to_decimal(char *binary) {
    int decimal = 0;
    int power = 0;
    int length = strlen(binary);
    char *decimal_str = malloc(MAX_SIZE);
    memset(decimal_str, 0, MAX_SIZE);

    for (int i = length - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }

    sprintf(decimal_str, "%d", decimal);
    return decimal_str;
}

char *decimal_to_binary(int decimal) {
    char *binary_str = malloc(MAX_SIZE);
    memset(binary_str, 0, MAX_SIZE);

    int power = 0;
    while (decimal > 0) {
        int remainder = decimal % 2;
        strcat(binary_str, remainder == 0? "0" : "1");
        decimal /= 2;
        power++;
    }

    for (int i = strlen(binary_str) - 1; i >= 0; i--) {
        strcat(binary_str, "0");
    }

    return binary_str;
}

int main() {
    char *binary_str, *decimal_str;
    int choice;

    do {
        printf("Enter 1 to convert binary to decimal or 2 to convert decimal to binary: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter binary number: ");
            scanf("%s", binary_str);
            decimal_str = binary_to_decimal(binary_str);
            printf("Decimal equivalent: %s\n", decimal_str);
        } else if (choice == 2) {
            printf("Enter decimal number: ");
            scanf("%d", &decimal_str);
            binary_str = decimal_to_binary(decimal_str);
            printf("Binary equivalent: %s\n", binary_str);
        } else {
            printf("Invalid choice. Please try again.\n");
        }

        free(binary_str);
        free(decimal_str);
    } while (choice!= 0);

    return 0;
}