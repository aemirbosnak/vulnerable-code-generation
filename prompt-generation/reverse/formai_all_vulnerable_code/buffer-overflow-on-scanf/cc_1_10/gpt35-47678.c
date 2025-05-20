//FormAI DATASET v1.0 Category: Binary Converter ; Style: rigorous
#include <stdio.h>
#include <math.h>

// function to convert decimal to binary
void decimal_to_binary(int decimal_num)
{
    int binary_array[32];
    int i = 0, j;
    
    // Convert decimal number to binary array
    while (decimal_num > 0)
    {
        binary_array[i] = decimal_num % 2;
        decimal_num = decimal_num / 2;
        i++;
    }
    
    // Print binary array in reverse order
    printf("Binary equivalent: ");
    for (j = i - 1; j >= 0; j--)
        printf("%d", binary_array[j]);
    printf("\n");
}

// function to convert binary to decimal
void binary_to_decimal(int binary_num)
{
    int decimal_num = 0, i = 0, rem;
    while (binary_num != 0)
    {
        rem = binary_num % 10;
        binary_num /= 10;
        decimal_num += rem * pow(2, i);
        ++i;
    }
    printf("Decimal equivalent: %d\n", decimal_num);
}

int main()
{
    int choice, num;
    printf("1. Decimal to Binary\n2. Binary to Decimal\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    
    switch (choice)
    {
        case 1:
            printf("Enter decimal number: ");
            scanf("%d", &num);
            decimal_to_binary(num);
            break;
            
        case 2:
            printf("Enter binary number: ");
            scanf("%d", &num);
            binary_to_decimal(num);
            break;
            
        default:
            printf("Invalid choice!\n");
    }
    return 0;
}