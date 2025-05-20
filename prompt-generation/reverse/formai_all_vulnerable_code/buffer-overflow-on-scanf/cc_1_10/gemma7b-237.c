//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, i, choice, binary[100];
    char str[100];

    printf("Welcome to the Binary Converter!\n");
    printf("Please enter your choice:\n");
    printf("1. Convert decimal to binary\n");
    printf("2. Convert binary to decimal\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter the decimal number: ");
            scanf("%d", &num);

            i = 0;
            while (num)
            {
                binary[i] = num % 2;
                num /= 2;
                i++;
            }

            printf("The binary equivalent is: ");
            for (i = i - 1; i >= 0; i--)
            {
                printf("%d ", binary[i]);
            }
            printf("\n");
            break;

        case 2:
            printf("Enter the binary number: ");
            scanf("%s", str);

            num = 0;
            for (i = 0; str[i] != '\0'; i++)
            {
                num = num * 2 + str[i] - '0';
            }

            printf("The decimal equivalent is: ");
            printf("%d\n", num);
            break;

        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}