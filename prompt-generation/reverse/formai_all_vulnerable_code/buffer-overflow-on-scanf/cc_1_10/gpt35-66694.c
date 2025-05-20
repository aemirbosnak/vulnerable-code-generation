//FormAI DATASET v1.0 Category: Binary Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

char * binary_converter(int);
void print_binary(char *);

int main()
{
    int decimal_num;
    char *binary_num;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal_num);

    binary_num = binary_converter(decimal_num);

    printf("\nBinary equivalent of decimal number %d is: ", decimal_num);
    print_binary(binary_num);
    printf("\n");

    free(binary_num);  // free dynamically allocated memory
    return 0;
}

// function to convert decimal number to binary
char * binary_converter(int decimal_num)
{
    char *binary = (char *) malloc(sizeof(char) * 32);  // allocate 32 bytes for binary representation
    int index = 0;

    while (decimal_num > 0)
    {
        int remainder = decimal_num % 2;  // get remainder of division by 2
        decimal_num /= 2;
        binary[index++] = remainder + '0';  // add remainder to binary representation
    }
    binary[index] = '\0';
    return binary;
}

// function to print binary number
void print_binary(char *binary_num)
{
    int index = 0;

    while (binary_num[index])
    {
        printf("%c", binary_num[index++]);
    }
}