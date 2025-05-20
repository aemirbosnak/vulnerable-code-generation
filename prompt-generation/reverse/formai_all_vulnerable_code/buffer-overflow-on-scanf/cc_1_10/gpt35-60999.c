//FormAI DATASET v1.0 Category: Binary Converter ; Style: brave
#include <stdio.h>

int main() {

    printf("Welcome to my Binary Converter!\n");
    printf("Enter a positive integer: ");

    int decimalNum;
    scanf("%d", &decimalNum);

    printf("Binary representation of %d is: ", decimalNum);

    int binaryNum[32];
    int i = 0;

    while (decimalNum > 0) {
        binaryNum[i] = decimalNum % 2;
        decimalNum = decimalNum / 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryNum[j]);
    }
    printf("\n");

    printf("Would you like to convert another number? (Y/N): ");

    char choice;
    scanf(" %c", &choice);

    while (choice == 'Y' || choice == 'y') {

        printf("Enter a positive integer: ");
        scanf("%d", &decimalNum);

        printf("Binary representation of %d is: ", decimalNum);

        int binaryNum[32];
        int i = 0;

        while (decimalNum > 0) {
            binaryNum[i] = decimalNum % 2;
            decimalNum = decimalNum / 2;
            i++;
        }

        for (int j = i - 1; j >= 0; j--) {
            printf("%d", binaryNum[j]);
        }
        printf("\n");

        printf("Would you like to convert another number? (Y/N): ");
        scanf(" %c", &choice);
    }

    printf("Thank you for using my Binary Converter!\n");

    return 0;
}