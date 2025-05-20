//FormAI DATASET v1.0 Category: Binary Converter ; Style: calm
#include <stdio.h>

void decimal_to_binary(int decimal) {
    long quotient, remainder;
    int binary[100], i = 1, j;
    
    quotient = decimal;
    
    while (quotient != 0) {
        binary[i++] = quotient % 2;
        quotient /= 2;
    }
    
    printf("Binary: ");
    
    for (j = i - 1; j > 0; j--) {
        printf("%d", binary[j]);
    }
    
    printf("\n");
}

void binary_to_decimal(long binary) {
    int decimal = 0, base = 1, remainder;
    
    while (binary != 0) {
        remainder = binary % 10;
        decimal += remainder * base;
        binary /= 10;
        base *= 2;
    }
    
    printf("Decimal: %d\n", decimal);
}

int main() {
    int choice, decimal;
    long binary;
    
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("Enter decimal number: ");
            scanf("%d", &decimal);
            decimal_to_binary(decimal);
            break;
          
        case 2:
            printf("Enter binary number: ");
            scanf("%ld", &binary);
            binary_to_decimal(binary);
            break;
          
        default:
            printf("Invalid choice.");
    }
    
    return 0;
}