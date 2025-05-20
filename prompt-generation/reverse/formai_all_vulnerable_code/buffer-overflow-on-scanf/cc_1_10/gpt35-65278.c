//FormAI DATASET v1.0 Category: Binary Converter ; Style: scalable
#include <stdio.h>
#include <math.h>
#include <string.h>

void decimal_to_binary(int decimal_num)
{
    int binary_num[100], i = 0, j;
    while(decimal_num > 0)
    {
        binary_num[i] = decimal_num % 2;
        decimal_num = decimal_num / 2;
        i++;
    }
    printf("\nBinary Equivalent: ");
    for(j = i - 1; j >= 0; j--)
        printf("%d", binary_num[j]);
    printf("\n");
}

void binary_to_decimal(char binary_num[])
{
    int len = strlen(binary_num), i, decimal_num = 0;
    for(i = 0; i < len; i++)
    {
        if(binary_num[i] == '1')
            decimal_num += pow(2, len - 1 - i);
    }
    printf("\nDecimal Equivalent: %d\n", decimal_num);
}

int main()
{
    int choice, decimal_num;
    char binary_num[100];
    printf("\n*** Binary Converter ***\n\n");
    do
    {
        printf("Enter your choice:\n");
        printf("1. Convert Decimal to Binary\n");
        printf("2. Convert Binary to Decimal\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter Decimal Number: ");
                scanf("%d", &decimal_num);
                decimal_to_binary(decimal_num);
                break;
            case 2:
                printf("\nEnter Binary Number: ");
                scanf("%s", binary_num);
                binary_to_decimal(binary_num);
                break;
            case 3:
                printf("\nExiting Binary Converter...\n");
                break;
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }while(choice != 3);
    return 0;
}