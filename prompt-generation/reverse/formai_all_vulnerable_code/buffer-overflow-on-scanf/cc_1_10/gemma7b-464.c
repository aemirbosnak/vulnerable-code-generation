//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, i, binary[100], count = 0;
    char choice;

    printf("Welcome to the Dungeon of Binary Conversion!");
    printf("\nPlease choose an option:");
    printf("\n1. Convert decimal to binary");
    printf("\n2. Convert binary to decimal");

    scanf("%c", &choice);

    switch (choice)
    {
        case '1':
            printf("Enter a decimal number:");
            scanf("%d", &num);

            while (num)
            {
                int digit = num % 2;
                binary[count++] = digit;
                num /= 2;
            }

            printf("Your binary number is:");
            for (i = count - 1; i >= 0; i--)
            {
                printf("%d ", binary[i]);
            }

            break;

        case '2':
            printf("Enter a binary number:");
            scanf("%d", &num);

            count = 0;

            while (num)
            {
                int digit = num % 2;
                binary[count++] = digit;
                num /= 2;
            }

            printf("Your decimal number is:");
            for (i = count - 1; i >= 0; i--)
            {
                printf("%d ", binary[i]);
            }

            break;

        default:
            printf("Invalid choice.");
    }

    return 0;
}