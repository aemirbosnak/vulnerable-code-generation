//FormAI DATASET v1.0 Category: Binary Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to convert decimal to binary */
void decimalToBinary(int decimal)
{
    int binary[32], i = 0;

    /* Calculating binary of decimal */
    while (decimal > 0) {
        binary[i] = decimal % 2;
        decimal /= 2;
        i++;
    }

    /* Printing binary in reverse order */
    printf("Binary conversion: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binary[j]);
    printf("\n");
}

/* Function to convert binary to decimal */
void binaryToDecimal(char *binary)
{
    int decimal = 0, power = 1, length = strlen(binary);

    /* Calculating decimal of binary */
    for (int i = length - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += power;
        }
        power *= 2;
    }

    /* Printing decimal */
    printf("Decimal conversion: %d\n", decimal);
}

int main()
{
    int choice, decimal;
    char binary[100];

    printf("Welcome to Binary Converter!\n");

    while (1) {
        printf("\nChoose your conversion type:\n1. Decimal to Binary\n2. Binary to Decimal\n3. Exit program\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                /* Decimal to Binary conversion */
                printf("Enter decimal: ");
                scanf("%d", &decimal);
                decimalToBinary(decimal);
                break;
            case 2:
                /* Binary to Decimal conversion */
                printf("Enter binary: ");
                scanf("%s", binary);
                binaryToDecimal(binary);
                break;
            case 3:
                /* Exit program */
                printf("Exiting Binary Converter...\n");
                exit(0);
            default:
                /* Invalid choice */
                printf("Invalid choice. Please choose again.\n");
        }
    }
}