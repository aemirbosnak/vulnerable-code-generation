//FormAI DATASET v1.0 Category: Binary Converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void binary_to_decimal(char binary[], int len_binary);
void decimal_to_binary(int decimal);

int main()
{
    printf("========= Welcome to the Binary Converter Program! =========\n\n");
    printf("Please choose which conversion you want to perform:\n");
    printf("1. Binary to Decimal Conversion\n");
    printf("2. Decimal to Binary Conversion\n");

    int choice;
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("\nEnter a binary number: ");
        char binary[32];
        scanf("%s", binary);
        int len_binary = strlen(binary);

        binary_to_decimal(binary, len_binary);
    }
    else if (choice == 2)
    {
        printf("\nEnter a decimal number: ");
        int decimal;
        scanf("%d", &decimal);

        decimal_to_binary(decimal);
    }
    else
    {
        printf("\nInvalid choice. Please try again.\n");
        return 1;
    }

    return 0;
}

void binary_to_decimal(char binary[], int len_binary)
{
    int decimal = 0;
    int power = 1;

    for (int i = len_binary - 1; i >= 0; i--)
    {
        if (binary[i] == '1')
        {
            decimal += power;
        }
        power *= 2;
    }

    printf("\nDecimal Equivalent: %d\n", decimal);
}

void decimal_to_binary(int decimal)
{
    int binary[32];
    int i = 0;

    while (decimal > 0)
    {
        binary[i] = decimal % 2;
        decimal /= 2;
        i++;
    }

    printf("\nBinary Equivalent: ");

    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", binary[j]);
    }

    printf("\n");
}