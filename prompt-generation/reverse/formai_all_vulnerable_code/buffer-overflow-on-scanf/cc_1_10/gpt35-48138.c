//FormAI DATASET v1.0 Category: Binary Converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to convert decimal to binary */
void decimalToBinary(int n)
{
    int binaryNum[1000], i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
}

/* Function to convert binary to decimal */
int binaryToDecimal(char *binary)
{
    int decimal = 0;
    int power = 1;
    int binaryLength = strlen(binary);
    for (int i = binaryLength - 1; i >= 0; i--)
    {
        if (binary[i] == '1')
            decimal += power;
        power *= 2;
    }
    return decimal;
}

int main()
{
    // Prompt user to select an option
    printf("Please select an option:\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");

    // Read the user's choice
    int choice;
    scanf("%d", &choice);

    // Process the user's choice
    switch (choice)
    {
        // If the user chose decimal to binary
        case 1:
        {
            // Read the decimal number
            int decimal;
            printf("Enter the decimal number: ");
            scanf("%d", &decimal);

            // Convert the decimal number to binary and print it
            printf("The binary representation of %d is: ", decimal);
            decimalToBinary(decimal);
            printf("\n");

            break;
        }

        // If the user chose binary to decimal
        case 2:
        {
            // Read the binary number
            char binary[1000];
            printf("Enter the binary number: ");
            scanf("%s", binary);

            // Convert the binary number to decimal and print it
            int decimal = binaryToDecimal(binary);
            printf("The decimal representation of %s is: %d\n", binary, decimal);

            break;
        }

        // If the user did not enter a valid choice
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}