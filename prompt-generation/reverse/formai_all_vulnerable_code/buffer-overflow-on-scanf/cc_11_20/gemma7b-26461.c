//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 0, y = 0, z = 0, a = 0, b = 0, c = 0, d = 0, e = 0;
    char ch;

    printf("Enter a command: ");
    scanf("%c", &ch);

    switch (ch)
    {
        case 'a':
            printf("You entered a.\n");
            a = 1;
            break;
        case 'b':
            printf("You entered b.\n");
            b = 1;
            break;
        case 'c':
            printf("You entered c.\n");
            c = 1;
            break;
        case 'd':
            printf("You entered d.\n");
            d = 1;
            break;
        case 'e':
            printf("You entered e.\n");
            e = 1;
            break;
        default:
            printf("Invalid command.\n");
    }

    if (a)
    {
        x = 5;
        y = 10;
        z = 15;
        printf("A: x = %d, y = %d, z = %d\n", x, y, z);
    }
    else if (b)
    {
        x = 10;
        y = 20,
        z = 30;
        printf("B: x = %d, y = %d, z = %d\n", x, y, z);
    }
    else if (c)
    {
        x = 15;
        y = 25,
        z = 35;
        printf("C: x = %d, y = %d, z = %d\n", x, y, z);
    }
    else if (d)
    {
        x = 20;
        y = 30,
        z = 40;
        printf("D: x = %d, y = %d, z = %d\n", x, y, z);
    }
    else if (e)
    {
        x = 25;
        y = 35,
        z = 45;
        printf("E: x = %d, y = %d, z = %d\n", x, y, z);
    }

    return 0;
}