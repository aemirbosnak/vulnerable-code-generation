//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to hexadecimal
char *decimalToHexadecimal(unsigned int decimal)
{
    char *hexadecimal = (char *)malloc(sizeof(char) * 7);
    // Convert decimal to hexadecimal
    sprintf(hexadecimal, "%X", decimal);
    return hexadecimal;
}

// Function to convert hexadecimal to decimal
unsigned int hexadecimalToDecimal(char *hexadecimal)
{
    unsigned int decimal = 0;
    int length = strlen(hexadecimal);
    for (int i = 0; i < length; i++)
    {
        decimal = decimal << 4;
        if (hexadecimal[i] >= '0' && hexadecimal[i] <= '9')
            decimal += hexadecimal[i] - '0';
        else if (hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F')
            decimal += hexadecimal[i] - 'A' + 10;
        else if (hexadecimal[i] >= 'a' && hexadecimal[i] <= 'f')
            decimal += hexadecimal[i] - 'a' + 10;
    }
    return decimal;
}

int main()
{
    int choice;
    do
    {
        // Ask user for choice
        printf("\n---Hexadecimal Converter---\n");
        printf("1. Decimal to Hexadecimal\n");
        printf("2. Hexadecimal to Decimal\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            {
                unsigned int decimal;
                printf("Enter decimal number: ");
                scanf("%u", &decimal);
                char *hexadecimal = decimalToHexadecimal(decimal);
                printf("Hexadecimal equivalent: %s\n", hexadecimal);
                free(hexadecimal);
                break;
            }
            case 2:
            {
                char hexadecimal[7];
                printf("Enter hexadecimal number (maximum 6 digits): ");
                scanf("%6s", hexadecimal);
                unsigned int decimal = hexadecimalToDecimal(hexadecimal);
                printf("Decimal equivalent: %u\n", decimal);
                break;
            }
            case 3:
            {
                printf("\nExiting program...\n");
                break;
            }
            default:
            {
                printf("\nInvalid choice. Please choose again.\n");
                break;
            }
        }
    } while (choice != 3);
    return 0;
}