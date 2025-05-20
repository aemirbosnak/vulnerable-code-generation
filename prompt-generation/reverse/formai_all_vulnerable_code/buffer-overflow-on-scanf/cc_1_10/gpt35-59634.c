//FormAI DATASET v1.0 Category: Binary Converter ; Style: automated
#include <stdio.h>
#include <math.h>
#include <string.h>

/* Function to convert binary to decimal */
int binaryToDecimal(char *binary)
{
    int decimal = 0, base = 1, length = strlen(binary), i;

    for(i = length - 1; i >= 0; i--)
    {
        if(binary[i] == '1')
            decimal += base;

        base *= 2;
    }

    return decimal;
}

/* Function to convert decimal to binary */
void decimalToBinary(int decimal)
{
    int binary[100], i = 0;
    while(decimal > 0)
    {
        binary[i] = decimal % 2;
        decimal /= 2;
        i++;
    }

    printf("\nThe Binary Equivalent is: ");
    for(int j = i - 1; j >= 0; j--)
        printf("%d", binary[j]);
}

int main()
{
    int choice, decimal;
    char binary[100];

    printf("Welcome to Binary Converter!\n\n");
    printf("1. Convert Binary to Decimal\n2. Convert Decimal to Binary\n3. Exit\n");

    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter the binary number: ");
                scanf("%s", binary);

                printf("\nThe Decimal Equivalent is: %d\n", binaryToDecimal(binary));
                break;

            case 2:
                printf("\nEnter the decimal number: ");
                scanf("%d", &decimal);

                decimalToBinary(decimal);
                break;

            case 3:
                printf("\nExiting Binary Converter...");
                break;

            default:
                printf("\nInvalid choice! Try again.");
        }

    } while(choice != 3);

    return 0;
}