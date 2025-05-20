//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: medieval
#include <stdio.h>

int main()
{
    int num, choice, decimal = 0, i = 0;
    char binary[10] = "";

    printf("Welcome to the Dragon's Den of Binary Conversion!\n");
    printf("Please choose an option:\n");
    printf("1. Convert decimal to binary\n");
    printf("2. Convert binary to decimal\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter a decimal number: ");
            scanf("%d", &num);

            while (num)
            {
                int digit = num % 2;
                binary[i++] = digit + '0';
                num /= 2;
            }

            printf("Your binary number is: ");
            for (i = 0; binary[i] != '\0'; i++)
            {
                printf("%c ", binary[i]);
            }

            break;

        case 2:
            printf("Enter a binary number: ");
            scanf("%s", binary);

            for (i = 0; binary[i] != '\0'; i++)
            {
                decimal += (binary[i] - '0') * pow(2, i);
            }

            printf("Your decimal number is: ");
            printf("%d", decimal);

            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}