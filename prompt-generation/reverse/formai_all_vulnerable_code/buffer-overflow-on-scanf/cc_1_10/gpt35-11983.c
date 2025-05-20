//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: synchronous
#include <stdio.h>
#include <string.h>

// Function to convert decimal to hexadecimal
void decToHexa(int num, char* hexVal)
{
    int i = 0;
    char hexValue[100];

    // Check for negative numbers
    if (num < 0)
    {
        num = 0xFFFFFFFF + num + 1;
    }

    // Convert decimal to hexadecimal
    while (num != 0)
    {
        int temp = 0;
        temp = num % 16;

        // Convert temp to Hexadecimal
        if (temp < 10)
        {
            hexValue[i] = temp + 48;
            i++;
        }
        else
        {
            hexValue[i] = temp + 55;
            i++;
        }

        num = num / 16;
    }

    // Check for a zero input
    if (i == 0)
    {
        hexVal[0] = '0';
        hexVal[1] = '\0';
    }

    // Reverse the string
    int j = 0;
    for (j = i - 1; j >= 0; j--)
        hexVal[i - 1 - j] = hexValue[j];

    hexVal[i] = '\0';
}

int main()
{
    int decNum;
    char hexNum[100];

    // Ask for user input
    printf("Enter a Decimal number: ");
    scanf("%d", &decNum);

    // Convert Decimal to Hexadecimal
    decToHexa(decNum, hexNum);

    // Print Result
    printf("Hexadecimal Value: %s", hexNum);

    return 0;
}