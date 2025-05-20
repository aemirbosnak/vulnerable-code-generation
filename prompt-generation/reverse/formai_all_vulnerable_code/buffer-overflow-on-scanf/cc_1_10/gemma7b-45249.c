//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, i, choice, binary[10], count = 0;

    printf("Enter 1 for binary to decimal or 2 for decimal to binary: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter the binary number: ");
            scanf("%d", &num);

            while (num)
            {
                binary[count++] = num % 2;
                num /= 2;
            }

            printf("The decimal equivalent is: ");
            for (i = count - 1; i >= 0; i--)
            {
                printf("%d ", binary[i]);
            }

            break;

        case 2:
            printf("Enter the decimal number: ");
            scanf("%d", &num);

            count = 0;
            while (num)
            {
                binary[count++] = num % 2;
                num /= 2;
            }

            printf("The binary equivalent is: ");
            for (i = count - 1; i >= 0; i--)
            {
                printf("%d ", binary[i]);
            }

            break;
    }

    return 0;
}