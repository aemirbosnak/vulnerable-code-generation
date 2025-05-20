//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, base, i, choice, result = 0;
    char ch;

    printf("Welcome to the Binary Converter!\n");
    printf("Please select an option:\n");
    printf("1. Convert decimal to binary\n");
    printf("2. Convert binary to decimal\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter a decimal number: ");
            scanf("%d", &num);

            base = 2;
            while (num / base)
            {
                int digit = num % base;
                num /= base;
                result = result * base + digit;
            }

            printf("The binary equivalent is: ");
            for (i = 0; result; i++)
            {
                ch = result % 2 + 48;
                printf("%c ", ch);
                result /= 2;
            }
            printf("\n");
            break;

        case 2:
            printf("Enter a binary number: ");
            scanf("%d", &num);

            base = 2;
            while (num / base)
            {
                int digit = num % base;
                num /= base;
                result = result * base + digit;
            }

            printf("The decimal equivalent is: ");
            printf("%d", result);
            printf("\n");
            break;

        default:
            printf("Invalid option.\n");
    }

    return 0;
}