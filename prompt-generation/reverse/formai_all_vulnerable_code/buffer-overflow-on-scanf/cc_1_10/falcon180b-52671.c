//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: creative
#include <stdio.h>

// Function to convert decimal to binary
void DecimalToBinary(int n) {
    int binary[100];
    int i = 0, j = 0;
    while (n > 0) {
        binary[i++] = n % 2;
        n /= 2;
    }
    printf("The binary equivalent of %d is: ", n);
    for (i = i - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
}

// Function to convert binary to decimal
int BinaryToDecimal(char binary[]) {
    int decimal = 0, i = 0;
    while (binary[i]!= '\0') {
        decimal += (binary[i] - '0') * pow(2, strlen(binary) - i - 1);
        i++;
    }
    return decimal;
}

int main() {
    char binary[100];
    int decimal, choice;

    do {
        printf("\n\nEnter your choice:\n");
        printf("1. Decimal to Binary\n");
        printf("2. Binary to Decimal\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                DecimalToBinary(decimal);
                break;
            case 2:
                printf("Enter a binary number: ");
                scanf("%s", binary);
                printf("The decimal equivalent of %s is: %d\n", binary, BinaryToDecimal(binary));
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 3);

    return 0;
}