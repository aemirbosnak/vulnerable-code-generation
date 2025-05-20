//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char numStr[100];
    int num, i, j, hexValue, count = 0;
    printf("Enter a hexadecimal number: ");
    scanf("%s", numStr);

    num = atoi(numStr);

    for (i = 0; num / 16 > 0; i++)
    {
        hexValue = num % 16;
        num /= 16;
        count++;
        switch (hexValue)
        {
            case 0:
                printf("0");
                break;
            case 1:
                printf("1");
                break;
            case 2:
                printf("2");
                break;
            case 3:
                printf("3");
                break;
            case 4:
                printf("4");
                break;
            case 5:
                printf("5");
                break;
            case 6:
                printf("6");
                break;
            case 7:
                printf("7");
                break;
            case 8:
                printf("8");
                break;
            case 9:
                printf("9");
                break;
            case 10:
                printf("A");
                break;
            case 11:
                printf("B");
                break;
            case 12:
                printf("C");
                break;
            case 13:
                printf("D");
                break;
            case 14:
                printf("E");
                break;
            case 15:
                printf("F");
                break;
        }
        if (count > 0)
        {
            printf(",");
        }
    }

    printf("\n");
    return 0;
}