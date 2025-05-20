//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, choice, rem, i = 0;
    char hex[100];

    printf("Enter the decimal number: ");
    scanf("%d", &num);

    printf("Select an option:\n1. Convert to hexadecimal (lowercase)\n2. Convert to hexadecimal (uppercase)\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            while (num != 0)
            {
                rem = num % 16;
                if (rem < 10)
                {
                    hex[i] = rem + 48;
                }
                else
                {
                    hex[i] = rem + 87;
                }
                num /= 16;
                i++;
            }
            printf("Hexadecimal equivalent: ");
            for (int j = i - 1; j >= 0; j--)
            {
                printf("%c", hex[j]);
            }
            break;
        case 2:
            while (num != 0)
            {
                rem = num % 16;
                if (rem < 10)
                {
                    hex[i] = rem + 48;
                }
                else
                {
                    hex[i] = rem + 55;
                }
                num /= 16;
                i++;
            }
            printf("Hexadecimal equivalent: ");
            for (int j = i - 1; j >= 0; j--)
            {
                printf("%c", hex[j]);
            }
            break;
        default:
            printf("Invalid option selected.");
    }

    printf("\n");

    return 0;
}