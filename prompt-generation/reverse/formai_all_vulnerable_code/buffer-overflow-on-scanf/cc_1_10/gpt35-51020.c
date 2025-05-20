//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: creative
#include<stdio.h>

/*The hexToInt function converts a hexadecimal symbol into its corresponding integer value*/
int hexToInt(char hexSymbol)
{
    if(hexSymbol >= '0' && hexSymbol <= '9')
    {
        return hexSymbol - '0';
    }
    else if(hexSymbol >= 'a' && hexSymbol <= 'f')
    {
        return hexSymbol - 'a' + 10;
    }
    else if(hexSymbol >= 'A' && hexSymbol <= 'F')
    {
        return hexSymbol - 'A' + 10;
    }

    return -1; /*Returns -1 if the symbol is not a valid hexadecimal character*/
}

/*The hexToDecimal function converts a hexadecimal number into its equivalent decimal value*/
int hexToDecimal(char* hexNumber)
{
    int decimalValue = 0, hexIndex = 0;

    while(hexNumber[hexIndex] != '\0')
    {
        decimalValue = decimalValue * 16 + hexToInt(hexNumber[hexIndex]);
        hexIndex++;
    }

    return decimalValue;
}

/*The decimalToHex function converts a decimal number into its equivalent hexadecimal value*/
void decimalToHex(int decimalValue)
{
    int remainder, quotient;
    char hexValue[100];
    int hexIndex = 0;

    if(decimalValue == 0)
    {
        printf("0");
        return;
    }

    while(decimalValue > 0)
    {
        remainder = decimalValue % 16;
        quotient = decimalValue / 16;

        if(remainder < 10)
        {
            hexValue[hexIndex] = remainder + '0';
        }
        else
        {
            hexValue[hexIndex] = remainder - 10 + 'a';
        }

        hexIndex++;
        decimalValue = quotient;
    }

    hexIndex--;

    while(hexIndex >= 0)
    {
        printf("%c", hexValue[hexIndex]);
        hexIndex--;
    }
}

/*The main function reads input from the user and converts it to either hexadecimal or decimal*/
int main()
{
    char userInput[100];
    int inputType;

    printf("Enter the number to convert: ");
    scanf("%s", userInput);

    printf("Is the number in decimal (1) or hexadecimal (2) format?\n");
    scanf("%d", &inputType);

    switch(inputType)
    {
        case 1:
            printf("The hexadecimal equivalent of %s is: ", userInput);
            decimalToHex(atoi(userInput));
            break;
        case 2:
            printf("The decimal equivalent of %s is: %d", userInput, hexToDecimal(userInput));
            break;
        default:
            printf("Invalid input type");
    }

    return 0;
}