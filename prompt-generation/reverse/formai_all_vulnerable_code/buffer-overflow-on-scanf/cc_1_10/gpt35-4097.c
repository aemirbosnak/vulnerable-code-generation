//FormAI DATASET v1.0 Category: Binary Converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decimalToBinary(int decimalNum) {
    int binaryArr[32], i = 0;

    while (decimalNum > 0) {
        int remainder = decimalNum % 2;
        binaryArr[i] = remainder;
        i++;
        decimalNum = decimalNum / 2;
    }

    printf("The binary representation of %d: ", decimalNum);
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryArr[j]);
    }
    printf("\n\n");
}

void binaryToDecimal(char binaryNum[]) {
    int decimalNum = 0;
    int length = strlen(binaryNum);
    int base = 1;

    for (int i = length - 1; i >= 0; i--) {
        if (binaryNum[i] == '1') {
            decimalNum += base;
        }
        base = base * 2;
    }

    printf("The decimal representation of %s: %d\n\n", binaryNum, decimalNum);
}

int main() {
    printf("\n*** Welcome to the Binary Converter ***\n\n");
    int menuChoice;
    do {
        printf("Choose an option:\n1. Decimal to Binary\n2. Binary to Decimal\n3. Exit\n\n");
        printf("Option: ");
        scanf("%d", &menuChoice);
        switch(menuChoice) {
            case 1: {
                int decimalNum;
                printf("\nEnter a decimal number: ");
                scanf("%d", &decimalNum);
                decimalToBinary(decimalNum);
                break;
            }
            case 2: {
                char binaryNum[100];
                printf("\nEnter a binary number: ");
                scanf("%s", binaryNum);
                binaryToDecimal(binaryNum);
                break;
            }
            case 3: {
                printf("\nGoodbye!\n\n");
                exit(0);
            }
            default: {
                printf("\nInvalid option! Please choose again.\n\n");
                break;
            }
        }
    } while (1);
    return 0;
}