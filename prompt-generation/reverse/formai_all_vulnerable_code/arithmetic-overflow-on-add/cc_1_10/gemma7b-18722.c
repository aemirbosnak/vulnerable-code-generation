//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, i, choice, decimal = 0, binary[10] = {0};

    printf("Welcome to the Binary Converter, my dear!\n");
    printf("Would you like to convert from decimal to binary (1) or from binary to decimal (2)?\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Please enter the decimal number you want to convert:");
            scanf("%d", &num);

            for (i = 0; num > 0; i++)
            {
                binary[i] = num % 2;
                num /= 2;
            }

            printf("Your binary number is:");
            for (i = 0; binary[i] != 0; i++)
            {
                printf("%d ", binary[i]);
            }
            break;

        case 2:
            printf("Please enter the binary number you want to convert:");
            scanf("%d", &num);

            while (num)
            {
                binary[i] = num % 2;
                num /= 2;
                i++;
            }

            printf("Your decimal number is:");
            for (i = i - 1; binary[i] != 0; i--)
            {
                printf("%d ", binary[i]);
            }
            break;

        default:
            printf("Invalid choice. Please try again.");
            break;
    }

    return 0;
}