//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function for decimal to hexadecimal conversion
void decimalToHexadecimal(int n)
{
    char hexaDecimal[100];
    int temp = n, i = 0;

    while(temp)
    {
        int remainder = temp % 16;

        if(remainder < 10)
            hexaDecimal[i++] = remainder + 48;
        else
            hexaDecimal[i++] = remainder + 55;

        temp /= 16;
    }

    printf("Hexadecimal representation of %d is: ", n);

    for(int j=i-1; j>=0; j--)
        printf("%c", hexaDecimal[j]);
    printf("\n");
}

// Function for hexadecimal to decimal conversion
int hexadecimalToDecimal(char hexaDecimal[])
{
    int decimal = 0, length = strlen(hexaDecimal);

    for(int i=0; i<length; i++)
    {
        if(hexaDecimal[i] >= '0' && hexaDecimal[i] <= '9')
            decimal += (hexaDecimal[i] - '0') * (1 << (4 * (length - 1 - i)));
        else if(hexaDecimal[i] >= 'A' && hexaDecimal[i] <= 'F')
            decimal += (hexaDecimal[i] - 55) * (1 << (4 * (length - 1 - i)));
        else if(hexaDecimal[i] >= 'a' && hexaDecimal[i] <= 'f')
            decimal += (hexaDecimal[i] - 87) * (1 << (4 * (length - 1 - i)));
        else
        {
            printf("Invalid hexadecimal number.");
            exit(0);
        }
    }

    return decimal;
}

int main()
{
    int choice, decimalNum;
    char hexadecimalNum[100];

    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Convert Hexadecimal to Decimal\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter a decimal number: ");
            scanf("%d", &decimalNum);
            decimalToHexadecimal(decimalNum);
            break;
        case 2:
            printf("Enter a hexadecimal number: ");
            scanf("%s", hexadecimalNum);
            printf("Decimal representation of %s is: %d\n", hexadecimalNum, hexadecimalToDecimal(hexadecimalNum));
            break;
        default:
            printf("Invalid choice.");
    }

    return 0;
}