//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, i, choice, octal, binary[100];
    char str[100];

    printf("Enter 1 for binary, 2 for octal, 3 for decimal:\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter the binary number:");
            scanf("%s", str);

            num = atoi(str);
            i = 0;

            while (num)
            {
                binary[i++] = num % 2;
                num /= 2;
            }

            printf("The binary number is:");
            for (i = i - 1; i >= 0; i--)
            {
                printf("%d ", binary[i]);
            }

            break;

        case 2:
            printf("Enter the octal number:");
            scanf("%s", str);

            num = atoi(str);
            i = 0;

            while (num)
            {
                binary[i++] = num % 8;
                num /= 8;
            }

            printf("The octal number is:");
            for (i = i - 1; i >= 0; i--)
            {
                printf("%d ", binary[i]);
            }

            break;

        case 3:
            printf("Enter the decimal number:");
            scanf("%d", &num);
            i = 0;

            while (num)
            {
                binary[i++] = num % 2;
                num /= 2;
            }

            printf("The decimal number is:");
            for (i = i - 1; i >= 0; i--)
            {
                printf("%d ", binary[i]);
            }

            break;

        default:
            printf("Invalid choice");
    }

    return 0;
}