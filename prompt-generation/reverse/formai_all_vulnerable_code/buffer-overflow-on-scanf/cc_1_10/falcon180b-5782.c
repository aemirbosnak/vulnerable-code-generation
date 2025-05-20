//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_SIZE 33
#define MAX_BIN_SIZE (MAX_NUM_SIZE * 8 + 1)

void binary_to_decimal(char* binary, int* decimal)
{
    int i = 0, j = 0, power = 1;
    while (binary[i] == '0')
    {
        i++;
    }
    *decimal = 0;
    while (binary[i]!= '\0')
    {
        if (binary[i] == '1')
        {
            *decimal += power;
        }
        power *= 2;
        i++;
    }
}

void decimal_to_binary(int decimal, char* binary)
{
    int i = 0;
    while (decimal > 0)
    {
        binary[i] = (decimal % 2) + '0';
        decimal /= 2;
        i++;
    }
    binary[i] = '\0';
    int j = 0;
    while (binary[j] == '0' && j < MAX_NUM_SIZE - 1)
    {
        j++;
    }
    while (j < MAX_NUM_SIZE - 1)
    {
        binary[j] = '0';
        j++;
    }
    binary[j] = '\0';
}

int main()
{
    char binary[MAX_BIN_SIZE];
    char input[MAX_NUM_SIZE];
    int decimal;
    int i;

    printf("Enter a decimal number: ");
    scanf("%s", input);

    decimal_to_binary(atoi(input), binary);

    printf("Decimal number: %d\n", atoi(input));
    printf("Binary number: ");
    for (i = strlen(binary) - 1; i >= 0; i--)
    {
        printf("%c", binary[i]);
    }
    printf("\n");

    binary_to_decimal(binary, &decimal);

    printf("Decimal equivalent: %d\n", decimal);

    return 0;
}