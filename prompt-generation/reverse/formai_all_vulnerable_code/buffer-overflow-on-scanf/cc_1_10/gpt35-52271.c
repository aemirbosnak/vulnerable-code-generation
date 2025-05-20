//FormAI DATASET v1.0 Category: Binary Converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Prototype
void printBinary(int num);

int main()
{
    int decimalNum, binaryNum = 0, remainder, base = 1;
    char choice;

    do
    {
        system("clear"); // Clear screen for new conversion

        printf("==========================================\n");
        printf("\tDECIMAL TO BINARY CONVERTER\n");
        printf("==========================================\n\n");

        printf("Enter a decimal number: ");
        scanf("%d", &decimalNum);

        // Convert to binary
        while (decimalNum > 0)
        {
            remainder = decimalNum % 2;
            binaryNum = binaryNum + remainder * base;
            decimalNum = decimalNum / 2;
            base = base * 10;
        }

        // Print binary equivalent
        printf("\nBinary equivalent: ");
        printBinary(binaryNum);

        base = 1; // Reset variables for next conversion
        binaryNum = 0;

        // Ask if user wants to convert another decimal number
        printf("\n\nDo you want to convert another decimal number? (Y/N): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("\n\n");

    return 0;
}

// Function to print binary number
void printBinary(int num)
{
    int binaryArr[100], index = 0, i;

    while (num > 0)
    {
        binaryArr[index] = num % 10;
        num = num / 10;
        index++;
    }

    // Print binary number in reverse order
    for (i = index - 1; i >= 0; i--)
    {
        printf("%d", binaryArr[i]);
    }
}