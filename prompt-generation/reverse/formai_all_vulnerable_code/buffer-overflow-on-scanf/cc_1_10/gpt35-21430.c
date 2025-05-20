//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: light-weight
#include <stdio.h>

// Function to convert decimal to hexadecimal
void decimalToHexadecimal(int decimalNumber)
{
    int remainder;

    // array to store the hexadecimal number
    char hexadecimalNumber[100];

    int index = 0;

    // conversion starts
    while(decimalNumber > 0)
    {
        remainder = decimalNumber % 16;

        if(remainder < 10)
        {
            hexadecimalNumber[index] = 48 + remainder;
            index++;
        }
        else
        {
            hexadecimalNumber[index] = 55 + remainder;
            index++;
        }

        decimalNumber = decimalNumber / 16;
    }

    // printing the hexadecimal number
    printf("Hexadecimal number is: ");

    for(int i = index-1; i >= 0; i--)
    {
        printf("%c", hexadecimalNumber[i]);
    }
}


int main()
{
    int decimalNumber;

    printf("Enter the decimal number: ");
    scanf("%d", &decimalNumber);

    decimalToHexadecimal(decimalNumber);

    return 0;
}