//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to convert binary to decimal
int binaryToDecimal(char binary[]) {
    int decimal = 0;
    int power = 0;
    int length = strlen(binary);

    for (int i = length - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }

    return decimal;
}

// Function to convert decimal to binary
void decimalToBinary(int decimal, char binary[]) {
    int length = 0;
    while (decimal > 0) {
        int remainder = decimal % 2;
        binary[length++] = remainder + '0';
        decimal /= 2;
    }
    binary[length] = '\0';
    for (int i = 0; i < length / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[length - i - 1];
        binary[length - i - 1] = temp;
    }
}

int main() {
    char binary[MAX_LENGTH];
    char decimal[MAX_LENGTH];
    int choice;

    do {
        printf("Enter your choice:\n");
        printf("1. Binary to Decimal\n");
        printf("2. Decimal to Binary\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter binary number: ");
            scanf("%s", binary);
            printf("Decimal equivalent: %d\n", binaryToDecimal(binary));
            break;
        case 2:
            printf("Enter decimal number: ");
            scanf("%s", decimal);
            decimalToBinary(atoi(decimal), binary);
            printf("Binary equivalent: %s\n", binary);
            break;
        case 3:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}