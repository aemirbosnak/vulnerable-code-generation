//FormAI DATASET v1.0 Category: Binary Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Shape shifting function to convert decimal to binary
void decimalToBinary(int num) {
    int binaryArr[32];
    int i = 0;
    while (num > 0) {
        binaryArr[i] = num % 2;
        num = num / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryArr[j]);
    }
}

// Shape shifting function to convert binary to decimal
void binaryToDecimal(char* binary) {
    int decimal = 0;
    int len = 0;
    while (binary[len] != '\0') {
        len++;
    }
    for (int i = len - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += pow(2, len - i - 1);
        }
    }
    printf("%d", decimal);
}

int main() {
    int choice, num;
    char* binary = (char*)malloc(32*sizeof(char));
    printf("Enter 1 to convert decimal to binary, or enter 2 to convert binary to decimal: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter a decimal number: ");
            scanf("%d", &num);
            printf("Binary: ");
            decimalToBinary(num);
            break;
        case 2:
            printf("Enter a binary number: ");
            scanf("%s", binary);
            printf("Decimal: ");
            binaryToDecimal(binary);
            break;
        default:
            printf("Invalid choice");
            break;
    }
    free(binary);
    return 0;
}