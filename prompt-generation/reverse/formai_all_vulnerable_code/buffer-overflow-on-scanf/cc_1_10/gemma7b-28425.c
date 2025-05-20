//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, choice, i, binary[10] = {0};

    printf("Enter 1 for binary conversion or 2 for decimal conversion: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter a decimal number: ");
            scanf("%d", &num);

            for (i = 0; num / 2 >= i; i++)
            {
                binary[i] = num % 2;
                num /= 2;
            }

            printf("Binary equivalent: ");
            for (i = 0; binary[i] != 0; i++)
            {
                printf("%d ", binary[i]);
            }
            break;

        case 2:
            printf("Enter a binary number: ");
            scanf("%d", &num);

            for (i = 0; num / 2 >= i; i++)
            {
                binary[i] = num % 2;
                num /= 2;
            }

            printf("Decimal equivalent: ");
            int sum = 0, power = 0;
            for (i = 0; binary[i] != 0; i++)
            {
                sum += binary[i] * pow(2, power);
                power++;
            }

            printf("%d", sum);
            break;

        default:
            printf("Invalid choice");
    }

    return 0;
}