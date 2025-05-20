//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000

// Function to reverse a string
void reverse(char* str) {
    int len = strlen(str);
    char* rev = malloc(len + 1);
    int i, j;
    for (i = 0, j = len - 1; i < len; i++, j--) {
        rev[i] = str[j];
    }
    rev[len] = '\0';
    strcpy(str, rev);
    free(rev);
}

// Function to convert binary to decimal
int binaryToDecimal(char* binary) {
    int decimal = 0;
    int i = 0;
    while (binary[i]!= '\0') {
        if (binary[i] == '1') {
            decimal += pow(2, strlen(binary) - i - 1);
        }
        i++;
    }
    return decimal;
}

// Function to convert decimal to binary
void decimalToBinary(int decimal) {
    char binary[MAX_SIZE];
    int i = 0;
    while (decimal > 0) {
        if (decimal % 2 == 1) {
            binary[i++] = '1';
        } else {
            binary[i++] = '0';
        }
        decimal /= 2;
    }
    binary[i] = '\0';
    reverse(binary);
    printf("%s\n", binary);
}

int main() {
    char binary[MAX_SIZE];
    int decimal;
    int choice;

    do {
        printf("Enter your choice:\n");
        printf("1. Binary to Decimal\n");
        printf("2. Decimal to Binary\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter a binary number:\n");
            scanf("%s", binary);
            decimal = binaryToDecimal(binary);
            printf("Decimal equivalent: %d\n", decimal);
            break;

        case 2:
            printf("Enter a decimal number:\n");
            scanf("%d", &decimal);
            decimalToBinary(decimal);
            break;

        case 3:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}