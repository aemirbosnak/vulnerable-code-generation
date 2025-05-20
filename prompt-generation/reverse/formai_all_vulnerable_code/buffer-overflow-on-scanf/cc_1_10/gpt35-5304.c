//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function to convert decimal to hexadecimal
char* decToHex(int decimal)
{
    char hexNum[100];
    int i = 0;
    while (decimal != 0)
    {
        int temp = 0;
        temp = decimal % 16;
        if (temp < 10)
        {
            hexNum[i] = temp + 48;
            i++;
        }
        else
        {
            hexNum[i] = temp + 55;
            i++;
        }
        decimal = decimal / 16;
    }

    //creating a string to store hexadecimal equivalent
    char* hex = (char*)malloc(sizeof(char) * (i + 1));
    int j;
    for (j = 0; i > 0; j++, i--)
    {
        hex[j] = hexNum[i - 1];
    }
    hex[j] = '\0';
    return hex;
}

//function to convert hexadecimal to decimal
int hexToDec(char* hex)
{
    int len = strlen(hex);
    int base = 1;
    int decimal = 0;

    //iterating from right to left to get decimal equivalent
    for (int i = len - 1; i >= 0; i--)
    {
        if (hex[i] >= '0' && hex[i] <= '9')
        {
            decimal += (hex[i] - 48) * base;
            base = base * 16;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F')
        {
            decimal += (hex[i] - 55) * base;
            base = base * 16;
        }
    }
    return decimal;
}

int main()
{
    int choice;
    char input[100];
    printf("Enter the number you want to convert: ");
    scanf("%s", input);

    printf("\nEnter your choice: \n");
    printf("1. Convert decimal to hexadecimal\n");
    printf("2. Convert hexadecimal to decimal\n");

    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        //converting decimal to hexadecimal
        printf("\nDecimal %s is equivalent to hexadecimal %s\n", input, decToHex(atoi(input)));
        break;

    case 2:
        //converting hexadecimal to decimal
        printf("\nHexadecimal %s is equivalent to decimal %d\n", input, hexToDec(input));
        break;

    default:
        printf("\nInvalid choice!\n");
        break;
    }

    return 0;
}