//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a decimal number to its binary representation
char* decToBin(int num)
{
    int i = 0;
    char* binary = (char*)malloc(33 * sizeof(char));

    while (num > 0)
    {
        binary[i++] = (num % 2) + '0';
        num /= 2;
    }

    binary[i] = '\0';
    
    // Reverse the binary string
    char temp;
    int len = strlen(binary);
    for (int j = 0; j < len / 2; j++)
    {
        temp = binary[j];
        binary[j] = binary[len - j - 1];
        binary[len - j - 1] = temp;
    }

    return binary;
}

// Function to convert a binary number to its decimal representation
int binToDec(char* binary)
{
    int num = 0;
    int len = strlen(binary);

    for (int i = 0; i < len; i++)
    {
        if (binary[i] == '1')
        {
            num += 1 << (len - i - 1);
        }
    }

    return num;
}

// Main function
int main()
{
    int choice;
    int number;
    char* binary;

    // Display menu options
    printf("Binary Converter:\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter a decimal number: ");
            scanf("%d", &number);
            binary = decToBin(number);
            printf("Binary representation: %s\n", binary);
            free(binary);
            break;

        case 2:
            printf("Enter a binary number: ");
            scanf("%s", binary);
            number = binToDec(binary);
            printf("Decimal representation: %d\n", number);
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}