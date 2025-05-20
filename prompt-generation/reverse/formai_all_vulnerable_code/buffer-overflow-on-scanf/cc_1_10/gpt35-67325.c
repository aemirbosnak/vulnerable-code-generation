//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: detailed
#include <stdio.h>

// function to convert a given decimal number to hexadecimal
void decimalToHexadecimal(int decimal)
{
    int remainder, i=0;
    char hexadecimal[100];

    while(decimal!=0)
    {
        remainder = decimal % 16;

        if(remainder < 10)
            hexadecimal[i] = remainder + 48;
        else
            hexadecimal[i] = remainder + 55;

        i++;
        decimal /= 16;
    }

    printf("Hexadecimal equivalent: ");

    // printing the hexadecimal number
    for(int j=i-1; j>=0; j--)
        printf("%c", hexadecimal[j]);
}

// function to convert a given hexadecimal number to decimal
void hexadecimalToDecimal(char hexadecimal[])
{
    int decimal=0, i=0, digitValue;

    // iterating through each hexadecimal digit
    while(hexadecimal[i])
    {
        // computing the decimal value of current hexadecimal digit
        if(hexadecimal[i]>='0' && hexadecimal[i]<='9')
            digitValue = hexadecimal[i] - 48;
        else if(hexadecimal[i]>='A' && hexadecimal[i]<='F')
            digitValue = hexadecimal[i] - 55;
        else if(hexadecimal[i]>='a' && hexadecimal[i]<='f')
            digitValue = hexadecimal[i] - 87;

        // adding the decimal value of current digit to the result
        decimal = (decimal * 16) + digitValue;

        i++;
    }

    printf("Decimal equivalent: %d", decimal);
}

int main()
{
    int choice, decimal;
    char hexadecimal[100];

    printf("Select conversion type:\n");
    printf("1. Decimal to Hexadecimal\n");
    printf("2. Hexadecimal to Decimal\n");

    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter decimal number: ");
            scanf("%d", &decimal);
            decimalToHexadecimal(decimal);
            break;

        case 2:
            printf("Enter hexadecimal number: ");
            scanf("%s", hexadecimal);
            hexadecimalToDecimal(hexadecimal);
            break;

        default:
            printf("Invalid choice!");
            break;
    }

    return 0;
}