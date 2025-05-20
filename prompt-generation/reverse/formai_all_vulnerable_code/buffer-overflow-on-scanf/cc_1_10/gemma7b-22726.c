//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, i, choice;
    char hex[10], hex_upper[10], bin[100];
    printf("Welcome to the Immersive Hexadecimal Converter!\n");
    printf("Please select an option:\n");
    printf("1. Convert decimal to hexadecimal\n");
    printf("2. Convert hexadecimal to decimal\n");
    printf("3. Convert hexadecimal to binary\n");
    printf("Enter your choice:");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter a decimal number:");
            scanf("%d", &num);
            i = 0;
            while (num)
            {
                hex[i++] = num % 16 + 0x30;
                num /= 16;
            }
            hex[i] = '\0';
            printf("The hexadecimal equivalent is: %s\n", hex);
            break;
        case 2:
            printf("Enter a hexadecimal number:");
            scanf("%s", hex);
            num = 0;
            for (i = 0; hex[i] != '\0'; i++)
            {
                num = num * 16 + hex[i] - 0x30;
            }
            printf("The decimal equivalent is: %d\n", num);
            break;
        case 3:
            printf("Enter a hexadecimal number:");
            scanf("%s", hex);
            i = 0;
            while (hex[i] != '\0')
            {
                bin[i++] = (hex[i] - 0x30) & 0b1111;
            }
            bin[i] = '\0';
            printf("The binary equivalent is: %s\n", bin);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}