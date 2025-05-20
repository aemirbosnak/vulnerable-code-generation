//FormAI DATASET v1.0 Category: Binary Converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to binary
void DecimalToBinary(int num) {
    int binary_num[32];
    int i = 0;
    while (num > 0) {
        binary_num[i] = num % 2;
        num = num / 2;
        i++;
    }
    printf("Binary Equivalent: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary_num[j]);
    }
}

// Function to convert binary to decimal
void BinaryToDecimal(char *bin) {
    int len = strlen(bin);
    int decimal = 0;
    int base = 1;
    for (int i = len - 1; i >= 0; i--) {
        if (bin[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }
    printf("Decimal Equivalent: %d", decimal);
}

int main() {
    int choice, num;
    char bin[32];

    printf("Enter choice:\n1. Decimal to Binary\n2. Binary to Decimal\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter decimal number: ");
            scanf("%d", &num);
            DecimalToBinary(num);
            break;
        case 2:
            printf("Enter binary number: ");
            scanf("%s", bin);
            BinaryToDecimal(bin);
            break;
        default:
            printf("Invalid choice");
            break;
    }

    return 0;
}