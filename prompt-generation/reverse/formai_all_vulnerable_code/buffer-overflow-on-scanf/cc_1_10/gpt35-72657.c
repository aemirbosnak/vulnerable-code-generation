//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

// Function prototypes
void printIntArray(int*, int);
void decToHex(int, char*);
int hexToDec(char*);

int main()
{
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];
    int number, decimal;

    printf("Welcome to the Hexadecimal Converter!\n");
    printf("Enter a decimal number to convert to hexadecimal: ");
    scanf("%d", &number);

    // Convert decimal to hexadecimal
    decToHex(number, output);

    printf("Result: %s\n", output);

    printf("Enter a hexadecimal number to convert to decimal: ");
    scanf("%s", input);

    // Convert hexadecimal to decimal
    decimal = hexToDec(input);

    printf("Result: %d\n", decimal);

    return 0;
}

// Function to convert decimal to hexadecimal
void decToHex(int decimal, char* output)
{
    int remainder, i = 0;

    while(decimal)
    {
        remainder = decimal % 16;

        if(remainder < 10)
        {
            output[i] = remainder + '0';
        }
        else
        {
            output[i] = remainder + 55;
        }

        decimal /= 16;
        i++;
    }

    output[i] = '\0';

    // Reverse the output string
    int len = i;
    char temp;
    for(i = 0; i < len/2; i++)
    {
        temp = output[i];
        output[i] = output[len-i-1];
        output[len-i-1] = temp;
    }
}

// Function to convert hexadecimal to decimal
int hexToDec(char* input)
{
    int decimal = 0, i = 0;

    while(input[i])
    {
        if(input[i] >= '0' && input[i] <= '9')
        {
            decimal = decimal * 16 + (input[i] - '0');
        }
        else if(input[i] >= 'A' && input[i] <= 'F')
        {
            decimal = decimal * 16 + (input[i] - 55);
        }
        else if(input[i] >= 'a' && input[i] <= 'f')
        {
            decimal = decimal * 16 + (input[i] - 87);
        }

        i++;
    }

    return decimal;
}