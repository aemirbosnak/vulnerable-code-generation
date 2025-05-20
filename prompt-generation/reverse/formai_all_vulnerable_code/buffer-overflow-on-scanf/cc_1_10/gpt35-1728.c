//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a decimal number to hexadecimal
char* decToHex(int decimalNumber)
{
    char hex[100];
    int i = 0;

    // Convert decimal to hexadecimal
    while (decimalNumber != 0)
    {
        int temp = 0;
        temp = decimalNumber % 16;
        // Check if temp < 10
        if (temp < 10)
        {
            hex[i] = temp + 48;
            i++;
        }
        // If temp >= 10
        else
        {
            hex[i] = temp + 55;
            i++;
        }

        decimalNumber /= 16;
    }

    // Reverse the order of digits in hex[]
    char* result = malloc(sizeof(char) * (i + 1));
    int j;
    for (j = 0; j < i; j++)
    {
        result[j] = hex[i - 1 - j];
    }
    result[i] = '\0';

    return result;
}

int main()
{
    int decimalNumber;

    // Get decimal number from user
    printf("Enter decimal number: ");
    scanf("%d", &decimalNumber);

    // Convert decimal number to hexadecimal
    char* hex = decToHex(decimalNumber);

    // Print result
    printf("Hexadecimal equivalent: %s", hex);

    // Free allocated memory
    free(hex);
    hex = NULL;

    return 0;
}