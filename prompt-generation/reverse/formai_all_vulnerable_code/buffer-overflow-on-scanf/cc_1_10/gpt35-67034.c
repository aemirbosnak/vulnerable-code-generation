//FormAI DATASET v1.0 Category: Binary Converter ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// function to convert decimal to binary
void decimalToBinary(int decimal_num, int binary_num[])
{
    int index = 0;
    while (decimal_num > 0)
    {
        binary_num[index++] = decimal_num % 2;
        decimal_num /= 2;
    }
}

// function to convert binary to decimal
int binaryToDecimal(int binary_num[], int size)
{
    int decimal_num = 0;
    int base_value = 1;
    for (int i = size - 1; i >= 0; i--)
    {
        decimal_num += binary_num[i] * base_value;
        base_value *= 2;
    }
    return decimal_num;
}

// function to print binary number
void printBinary(int binary_num[], int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        printf("%d", binary_num[i]);
    }
    printf("\n");
}

int main()
{
    int choice;
    do
    {
        printf("1. Decimal to Binary\n");
        printf("2. Binary to Decimal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter decimal number to convert to binary: ");
            int decimal_num;
            scanf("%d", &decimal_num);
            int binary_num[100];
            decimalToBinary(decimal_num, binary_num);
            printf("Binary Equivalent of %d is: ", decimal_num);
            printBinary(binary_num, sizeof(binary_num)/ sizeof(binary_num[0]));
            break;

        case 2:
            printf("Enter binary number to convert to decimal: ");
            char binary_str[100];
            scanf("%s", binary_str);
            int size = strlen(binary_str);
            int binary_num2[100];
            for (int i = 0; i < size; i++)
            {
                if (binary_str[i] == '0')
                {
                    binary_num2[i] = 0;
                }
                else if (binary_str[i] == '1')
                {
                    binary_num2[i] = 1;
                }
                else
                {
                    printf("Invalid binary number\n");
                    break;
                }
            }
            int decimal_num2 = binaryToDecimal(binary_num2, size);
            printf("Decimal Equivalent of %s is: %d\n", binary_str, decimal_num2);
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (1);

    return 0;
}