//FormAI DATASET v1.0 Category: Binary Converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Convert decimal to binary
void decimalToBinary(int n) {
    int binaryNum[32];
    int i = 0;

    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // Print binary in reverse order
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryNum[j]);
    }
}

// Convert binary to decimal
int binaryToDecimal(char *binary) {
    int decimal = 0;
    int length = strlen(binary);

    for (int i = 0; i < length; i++) {
        if (binary[i] == '1') {
            decimal += 1 << (length - i - 1);
        }
    }

    return decimal;
}

int main() {
    int choice, decimal;
    char binary[32];

    while (1) {
        printf("Please select an option:\n");
        printf("1. Decimal to Binary\n");
        printf("2. Binary to Decimal\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                printf("Binary: ");
                decimalToBinary(decimal);
                printf("\n");
                break;
            case 2:
                printf("Enter a binary number: ");
                scanf("%s", binary);
                printf("Decimal: %d\n", binaryToDecimal(binary));
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    
    return 0;
}