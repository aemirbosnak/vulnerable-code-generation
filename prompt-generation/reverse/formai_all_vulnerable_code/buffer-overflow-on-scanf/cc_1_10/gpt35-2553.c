//FormAI DATASET v1.0 Category: Binary Converter ; Style: light-weight
#include <stdio.h>

int binary_to_decimal(int binary_num);
int decimal_to_binary(int decimal_num);

int main()
{
    int choice, num;
    
    printf("Select a conversion:\n");
    printf("1. Binary to Decimal\n");
    printf("2. Decimal to Binary\n");
    scanf("%d", &choice);
    
    switch (choice)
    {
        case 1:
            printf("Enter a binary number: ");
            scanf("%d", &num);
            printf("Decimal equivalent: %d", binary_to_decimal(num));
            break;
            
        case 2:
            printf("Enter a decimal number: ");
            scanf("%d", &num);
            printf("Binary equivalent: %d", decimal_to_binary(num));
            break;
            
        default:
            printf("Invalid choice");
    }
    
    return 0;
}

int binary_to_decimal(int binary_num)
{
    int decimal_num = 0, base = 1;
    
    while (binary_num > 0)
    {
        int digit = binary_num % 10;
        binary_num /= 10;
        decimal_num += digit * base;
        base *= 2;
    }
    
    return decimal_num;
}

int decimal_to_binary(int decimal_num)
{
    int binary_num = 0, base = 1;
    
    while (decimal_num > 0)
    {
        int digit = decimal_num % 2;
        decimal_num /= 2;
        binary_num += digit * base;
        base *= 10;
    }
    
    return binary_num;
}