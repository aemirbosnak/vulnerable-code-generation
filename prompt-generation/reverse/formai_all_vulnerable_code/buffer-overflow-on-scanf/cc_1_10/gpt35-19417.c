//FormAI DATASET v1.0 Category: Binary Converter ; Style: retro
#include <stdio.h>

int decimalToBinary(int decimalNum);
int binaryToDecimal(long int binaryNum);

int main() {
    int choice;
    long int num;
    printf("Welcome to Retro Binary Converter!\n");
    printf("1. Convert decimal to binary\n");
    printf("2. Convert binary to decimal\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
    scanf("%d", &choice);
    while (choice != 3) {
        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%ld", &num);
                printf("%ld in decimal = %d in binary\n", num, decimalToBinary(num));
                break;
            case 2:
                printf("Enter a binary number: ");
                scanf("%ld", &num);
                printf("%ld in binary = %d in decimal\n", num, binaryToDecimal(num));
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
        printf("\n");
        printf("1. Convert decimal to binary\n");
        printf("2. Convert binary to decimal\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
    }
    printf("Goodbye!\n");
    return 0;
}

int decimalToBinary(int decimalNum) {
    int binaryNum = 0, base = 1;
    while (decimalNum > 0) {
        binaryNum += decimalNum % 2 * base;
        decimalNum /= 2;
        base *= 10;
    }
    return binaryNum;
}

int binaryToDecimal(long int binaryNum) {
    int decimalNum = 0, base = 1;
    while (binaryNum > 0) {
        decimalNum += binaryNum % 10 * base;
        binaryNum /= 10;
        base *= 2;
    }
    return decimalNum;
}