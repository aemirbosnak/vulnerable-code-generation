//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: medieval
#include <stdio.h>

// Function to convert decimal to binary
void decimal_to_binary(int decimal) {
    int binary[32]; // Maximum 32 bits
    int j = 0;
    while (decimal > 0) {
        binary[j] = decimal % 2;
        decimal = decimal / 2;
        j++;
    }
    for (int i = j - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

// Function to convert binary to decimal
int binary_to_decimal(char binary[]) {
    int decimal = 0;
    int power = 0;
    int length = strlen(binary) - 1;
    for (int i = length; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }
    return decimal;
}

int main() {
    char binary[32]; // Maximum 32 bits
    int decimal;
    int choice;

    do {
        printf("Choose an option:\n");
        printf("1. Decimal to Binary\n");
        printf("2. Binary to Decimal\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter a decimal number: ");
            scanf("%d", &decimal);
            decimal_to_binary(decimal);
            break;

        case 2:
            printf("Enter a binary number: ");
            scanf("%s", binary);
            decimal = binary_to_decimal(binary);
            printf("Decimal equivalent: %d\n", decimal);
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