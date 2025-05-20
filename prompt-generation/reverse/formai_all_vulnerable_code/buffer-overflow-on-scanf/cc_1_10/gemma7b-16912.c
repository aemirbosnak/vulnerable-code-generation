//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, i, choice, binary[10], count = 0;

    printf("Enter 0 for binary to decimal or 1 for decimal to binary: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 0:
            printf("Enter a decimal number: ");
            scanf("%d", &num);

            while (num)
            {
                int digit = num % 2;
                num /= 2;
                binary[count++] = digit;
            }

            printf("Your binary number is: ");
            for (i = count - 1; i >= 0; i--)
            {
                printf("%d ", binary[i]);
            }
            break;

        case 1:
            printf("Enter a binary number: ");
            scanf("%d", &num);

            count = 0;
            while (num)
            {
                int digit = num % 2;
                num /= 2;
                binary[count++] = digit;
            }

            printf("Your decimal number is: ");
            for (i = count - 1; i >= 0; i--)
            {
                printf("%d ", binary[i]);
            }
            break;

        default:
            printf("Invalid input.");
            break;
    }

    return 0;
}