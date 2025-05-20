//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

#define MAX_HEX_LEN 50

// Function to convert decimal to hexadecimal
void decimalToHexadecimal(long int decimalNumber, char hexNumber[])
{
    int i = 0;
    while(decimalNumber != 0)
    {
        long int remainder = decimalNumber % 16;
        if(remainder < 10)
            hexNumber[i++] = 48 + remainder;
        else
            hexNumber[i++] = 55 + remainder;
        decimalNumber /= 16;
    }
    hexNumber[i] = '\0';
    int j = 0, k = i-1;
    while(j < k)
    {
        char temp = hexNumber[j];
        hexNumber[j] = hexNumber[k];
        hexNumber[k] = temp;
        j++; k--;
    }
}

int main()
{
    printf("Welcome to the Cyberpunk Hexadecimal Converter!\n");
    while(1)
    {
        printf("\nEnter a decimal number to convert to hexadecimal (or enter 'exit' to quit):\n");
        char input[MAX_HEX_LEN];
        scanf("%s", input);
        if(strcmp(input, "exit") == 0)
        {
            printf("\nThank you for using the Cyberpunk Hexadecimal Converter! Goodbye!\n");
            return 0;
        }
        int inputLen = strlen(input);
        if(inputLen > MAX_HEX_LEN || inputLen == 0)
        {
            printf("\nInvalid input, please try again.\n");
            continue;
        }
        long int decimalNumber = 0;
        for(int i = 0; i < inputLen; i++)
        {
            if(input[i] >= '0' && input[i] <= '9')
                decimalNumber = decimalNumber * 10 + (input[i] - '0');
            else
            {
                printf("\nInvalid input, please try again.\n");
                decimalNumber = -1;
                break;
            }
        }
        if(decimalNumber != -1)
        {
            char hexNumber[MAX_HEX_LEN];
            decimalToHexadecimal(decimalNumber, hexNumber);
            printf("\nThe hexadecimal equivalent of %ld is: %s\n", decimalNumber, hexNumber);
        }
    }
    return 0;
}