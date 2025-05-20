//FormAI DATASET v1.0 Category: Binary Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char binary[50];

char* decimalToBinary(int decimal) {
    int i = 0;
    while (decimal > 0) {
        binary[i++] = (decimal % 2) + '0';
        decimal /= 2;
    }
    binary[i] = '\0';
    return binary;
}

int binaryToDecimal(char* binary) {
    int decimal = 0;
    int power = 1;
    int index = strlen(binary) - 1;
    while (index >= 0) {
        decimal += (binary[index] - '0') * power;
        power *= 2;
        index--;
    }
    return decimal;
}

int main() {
    
    char choice;
    
    do {
        printf("Enter '1' to convert Decimal to Binary\n");
        printf("Enter '2' to convert Binary to Decimal\n");
        printf("Enter '0' to Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);
        fflush(stdin); // clear any extra input in the buffer
        
        if (choice == '1') {
            int decimal;
            printf("Enter Decimal Number: ");
            scanf("%d", &decimal);
            fflush(stdin); // clear any extra input in the buffer
            printf("Binary: %s\n", decimalToBinary(decimal));
        }
        else if (choice == '2') {
            char binary[50];
            printf("Enter Binary Number: ");
            scanf("%s", binary);
            fflush(stdin); // clear any extra input in the buffer
            printf("Decimal: %d\n", binaryToDecimal(binary));
        }
        else if (choice == '0') {
            break;
        }
        else {
            printf("Invalid Input! Please try again.\n");
        }
        
    } while (choice != '0');
    
    return 0;
}