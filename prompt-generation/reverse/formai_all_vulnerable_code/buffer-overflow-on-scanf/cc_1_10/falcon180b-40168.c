//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void binaryToDecimal(char* binary) {
    int decimal = 0, i = 0, j = strlen(binary) - 1;
    while (i <= j) {
        if (binary[i] == '1') {
            decimal += pow(2, j - i);
        }
        i++;
    }
    printf("Decimal: %d\n", decimal);
}

void decimalToBinary(int decimal) {
    char binary[MAX_SIZE];
    int i = 0, j = 0;

    while (decimal > 0) {
        binary[i++] = (decimal % 2) + '0';
        decimal /= 2;
    }

    for (int k = 0; k < i / 2; k++) {
        char temp = binary[k];
        binary[k] = binary[i - k - 1];
        binary[i - k - 1] = temp;
    }

    binary[i] = '\0';
    printf("Binary: %s\n", binary);
}

int main() {
    char choice;
    int decimal;

    do {
        printf("Enter your choice:\n");
        printf("1. Binary to Decimal\n");
        printf("2. Decimal to Binary\n");
        printf("3. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            printf("Enter binary number: ");
            scanf("%s", binaryToDecimal);
            break;

        case '2':
            printf("Enter decimal number: ");
            scanf("%d", &decimal);
            decimalToBinary(decimal);
            break;

        case '3':
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice!= '3');

    return 0;
}