//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

char binaryArray[MAX_SIZE];
int decimalNumber;

void convertDecimalToBinary(int decimal) {
    int i = 0;
    while (decimal > 0) {
        binaryArray[i] = decimal % 2 + '0';
        decimal /= 2;
        i++;
    }
    binaryArray[i] = '\0';
    printf("Binary number: %s\n", binaryArray);
}

void convertBinaryToDecimal(char binary[]) {
    int decimal = 0, i = 0;
    while (binary[i]!= '\0') {
        decimal += binary[i] - '0';
        i++;
        decimal *= 2;
    }
    printf("Decimal number: %d\n", decimal);
}

int main() {
    char input[MAX_SIZE];
    int choice;

    do {
        printf("Enter your choice:\n");
        printf("1. Convert decimal to binary\n");
        printf("2. Convert binary to decimal\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter a decimal number: ");
            scanf("%d", &decimalNumber);
            convertDecimalToBinary(decimalNumber);
            break;

        case 2:
            printf("Enter a binary number: ");
            scanf("%s", input);
            convertBinaryToDecimal(input);
            break;

        default:
            printf("Invalid choice\n");
        }
    } while (choice!= 3);

    return 0;
}