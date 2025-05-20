//Falcon2-11B DATASET v1.0 Category: Binary Converter ; Style: light-weight
#include <stdio.h>

void decimalToBinary(int n)
{
    int binary[20] = {0};
    int i, rem;

    for(i = 0; n > 0; i++)
    {
        rem = n % 2;
        binary[i] = rem;
        n = n / 2;
    }

    for(i = 0; i < 20; i++)
    {
        printf("%d", binary[i]);
    }
}

void binaryToDecimal(char *binary)
{
    int i = 0, j = 0, decimal = 0;

    while (binary[i]!= '\0')
    {
        decimal += binary[i] - '0';
        i++;
    }

    printf("The binary number is %d.\n", decimal);
}

int main()
{
    int n;
    char binary[20];

    printf("Enter a decimal number: ");
    scanf("%d", &n);

    decimalToBinary(n);

    printf("Enter a binary number: ");
    scanf("%s", binary);

    binaryToDecimal(binary);

    return 0;
}