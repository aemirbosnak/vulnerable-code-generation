//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char input[10];
    int i, num, oct, hex, flag = 0;

    printf("Enter a number: ");
    scanf("%s", input);

    for (i = 0; input[i] != '\0'; i++)
    {
        if (input[i] >= 'a' && input[i] <= 'f')
        {
            flag = 1;
            num = input[i] - 'a' + 10;
        }
        else if (input[i] >= 'A' && input[i] <= 'F')
        {
            flag = 1;
            num = input[i] - 'A' + 10;
        }
        else if (input[i] >= '0' && input[i] <= '9')
        {
            num = input[i] - '0';
        }
        else
        {
            flag = 1;
        }

        if (flag)
        {
            printf("Error: Invalid input.\n");
            return 1;
        }

        switch (num)
        {
            case 0:
                oct = 0;
                hex = 0;
                break;
            case 1:
                oct = 1;
                hex = 1;
                break;
            case 2:
                oct = 2;
                hex = 2;
                break;
            case 3:
                oct = 3;
                hex = 3;
                break;
            case 4:
                oct = 4;
                hex = 4;
                break;
            case 5:
                oct = 5;
                hex = 5;
                break;
            case 6:
                oct = 6;
                hex = 6;
                break;
            case 7:
                oct = 7;
                hex = 7;
                break;
            case 8:
                oct = 8;
                hex = 8;
                break;
            case 9:
                oct = 9;
                hex = 9;
                break;
            default:
                oct = 0;
                hex = 0;
                break;
        }

        switch (hex)
        {
            case 0:
                printf("Hexadecimal: 0x%x\n", oct);
                break;
            case 1:
                printf("Hexadecimal: 0x%x\n", oct);
                break;
            case 2:
                printf("Hexadecimal: 0x%x\n", oct);
                break;
            case 3:
                printf("Hexadecimal: 0x%x\n", oct);
                break;
            case 4:
                printf("Hexadecimal: 0x%x\n", oct);
                break;
            case 5:
                printf("Hexadecimal: 0x%x\n", oct);
                break;
            case 6:
                printf("Hexadecimal: 0x%x\n", oct);
                break;
            case 7:
                printf("Hexadecimal: 0x%x\n", oct);
                break;
            case 8:
                printf("Hexadecimal: 0x%x\n", oct);
                break;
            case 9:
                printf("Hexadecimal: 0x%x\n", oct);
                break;
            default:
                printf("Hexadecimal: 0x%x\n", oct);
                break;
        }
    }

    return 0;
}