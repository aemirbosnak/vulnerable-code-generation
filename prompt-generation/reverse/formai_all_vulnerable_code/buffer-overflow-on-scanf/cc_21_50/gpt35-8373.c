//FormAI DATASET v1.0 Category: Color Code Converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c1, c2;
    int color;

    printf("Enter the first character of the color (R, G or B): ");
    scanf("%c", &c1);

    printf("Enter the second character of the color (R, G or B): ");
    scanf(" %c", &c2);

    if (c1 == 'R' || c1 == 'r')
    {
        if (c2 == 'R' || c2 == 'r')
        {
            color = 0xFF0000;
        }
        else if (c2 == 'G' || c2 == 'g')
        {
            color = 0xFF7F00;
        }
        else if (c2 == 'B' || c2 == 'b')
        {
            color = 0xFF00FF;
        }
        else
        {
            printf("Invalid second character\n");
            return 1;
        }
    }
    else if (c1 == 'G' || c1 == 'g')
    {
        if (c2 == 'R' || c2 == 'r')
        {
            color = 0x00FF00;
        }
        else if (c2 == 'G' || c2 == 'g')
        {
            color = 0x00FFFF;
        }
        else if (c2 == 'B' || c2 == 'b')
        {
            color = 0x7F00FF;
        }
        else
        {
            printf("Invalid second character\n");
            return 1;
        }
    }
    else if (c1 == 'B' || c1 == 'b')
    {
        if (c2 == 'R' || c2 == 'r')
        {
            color = 0x0000FF;
        }
        else if (c2 == 'G' || c2 == 'g')
        {
            color = 0x7FFF00;
        }
        else if (c2 == 'B' || c2 == 'b')
        {
            color = 0xFF00FF;
        }
        else
        {
            printf("Invalid second character\n");
            return 1;
        }
    }
    else
    {
        printf("Invalid first character\n");
        return 1;
    }

    printf("The color code is: %#x\n", color);

    return 0;
}