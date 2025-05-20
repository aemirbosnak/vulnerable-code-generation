//FormAI DATASET v1.0 Category: Binary Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertToBinary(unsigned int num) {
    int binArr[32];
    int i = 0;

    while (num > 0) {
        binArr[i] = num % 2;
        num /= 2;
        i++;
    }

    printf("\nBinary equivalent: ");

    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binArr[j]);
    }

    printf("\n");
}

int main() {
    int choice = 0;
    unsigned int num;

    printf("Welcome to the Binary Converter program!\n");

    do {
        printf("\nChoose an option:\n");
        printf("1. Convert decimal to binary\n");
        printf("2. Exit program\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%u", &num);
                convertToBinary(num);
                break;
            
            case 2:
                printf("\nThanks for using the Binary Converter program!\n");
                return 0;
            
            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 2);

    return 0;
}