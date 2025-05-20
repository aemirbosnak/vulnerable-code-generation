//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: brave
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to convert decimal number to hexadecimal
void decimalToHexadecimal(int decimalNumber, char* hexadecimalNumber)
{
    int i = 0, quotient = 0;
    char temp[MAX_LENGTH];
    
    while(decimalNumber != 0)
    {
        quotient = decimalNumber % 16;
        if(quotient < 10)
        {
            temp[i] = quotient + 48;
            i++;
        }
        else
        {
            temp[i] = quotient + 55;
            i++;
        }
        
        decimalNumber = decimalNumber / 16;
    }
    
    int length = strlen(temp);
    
    // Reverse the hexadecimal number
    for(int j = length - 1, k = 0; j >= 0; j--, k++)
    {
        hexadecimalNumber[k] = temp[j];
    }
    
    return;
}

int main()
{
    int decimalNumber;
    char hexadecimalNumber[MAX_LENGTH];
    
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);
    
    decimalToHexadecimal(decimalNumber, hexadecimalNumber);
    
    printf("The hexadecimal value of %d is %s", decimalNumber, hexadecimalNumber);
    
    return 0;
}