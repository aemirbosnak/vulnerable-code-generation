//FormAI DATASET v1.0 Category: Binary Converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
int decimal_to_binary(int decimal_num)
{
    if(decimal_num == 0)
    {
        return 0;
    }
    else
    {
        return (decimal_num%2 + 10 * decimal_to_binary(decimal_num/2));
    }
}

// Function to convert binary to decimal
int binary_to_decimal(int binary_num)
{
    int decimal_num = 0, base = 1;
    while(binary_num > 0)
    {
        int rem = binary_num % 10;
        binary_num = binary_num / 10;
        decimal_num += rem * base;
        base *= 2;
    }
    return decimal_num;
}

int main()
{
    int choice;
    int decimal_num, binary_num;
    printf("Welcome to the Binary Converter!\n");
    do
    {
        printf("Please select an option:\n");
        printf("1. Convert Decimal to Binary\n");
        printf("2. Convert Binary to Decimal\n");
        printf("0. Exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimal_num);
                binary_num = decimal_to_binary(decimal_num);
                printf("Binary: %d\n", binary_num);
                break;
            case 2:
                printf("Enter a binary number: ");
                scanf("%d", &binary_num);
                decimal_num = binary_to_decimal(binary_num);
                printf("Decimal: %d\n", decimal_num);
                break;
            case 0:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 0);
    return 0;
}