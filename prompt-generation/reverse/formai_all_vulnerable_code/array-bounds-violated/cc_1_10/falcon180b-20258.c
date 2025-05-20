//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the maximum length of a binary string */
#define MAX_BINARY_LENGTH 33

/* Define the size of the lookup table */
#define TABLE_SIZE 256

/* Define the lookup table */
char binary_table[TABLE_SIZE] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
};

/* Function to convert a decimal number to binary */
void decimal_to_binary(int decimal, char* binary)
{
    int i = 0;
    int remainder;

    /* Initialize the binary string */
    memset(binary, 0, MAX_BINARY_LENGTH);

    /* Convert the decimal number to binary */
    while (decimal!= 0)
    {
        remainder = decimal % 10;
        binary[i++] = binary_table[remainder];
        decimal /= 10;
    }

    /* Reverse the binary string */
    for (int j = 0; j < i / 2; j++)
    {
        char temp = binary[j];
        binary[j] = binary[i - 1 - j];
        binary[i - 1 - j] = temp;
    }

    /* Add leading zeros if necessary */
    while (i < MAX_BINARY_LENGTH)
    {
        binary[i++] = '0';
    }
}

/* Function to convert a binary string to decimal */
int binary_to_decimal(char* binary)
{
    int decimal = 0;
    int power = 0;

    /* Convert the binary string to decimal */
    for (int i = strlen(binary) - 1; i >= 0; i--)
    {
        if (binary[i] == '1')
        {
            decimal += pow(2, power);
        }
        power++;
    }

    return decimal;
}

/* Main function */
int main()
{
    int decimal;
    char binary[MAX_BINARY_LENGTH];

    /* Prompt the user for a decimal number */
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    /* Convert the decimal number to binary */
    decimal_to_binary(decimal, binary);

    /* Display the binary equivalent */
    printf("The binary equivalent is: %s\n", binary);

    /* Convert the binary string back to decimal */
    int binary_decimal = binary_to_decimal(binary);

    /* Display the decimal equivalent */
    printf("The decimal equivalent is: %d\n", binary_decimal);

    return 0;
}