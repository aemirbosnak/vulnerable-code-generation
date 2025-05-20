//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void draw_castle(int h, int w);

int main()
{
    char pass[256];
    int strength = 0;
    int i;

    printf("Enter your password: ");
    scanf("%s", pass);

    for (i = 0; pass[i] != '\0'; i++)
    {
        if (pass[i] >= 'a' && pass[i] <= 'z')
            strength++;
        else if (pass[i] >= 'A' && pass[i] <= 'Z')
            strength++;
        else if (pass[i] >= '0' && pass[i] <= '9')
            strength++;
    }

    switch (strength)
    {
        case 0:
            draw_castle(1, 1);
            printf("Password strength: Weak\n");
            break;
        case 1:
            draw_castle(2, 1);
            printf("Password strength: Moderate\n");
            break;
        case 2:
            draw_castle(3, 1);
            printf("Password strength: Strong\n");
            break;
        case 3:
            draw_castle(4, 1);
            printf("Password strength: Very Strong\n");
            break;
    }

    return 0;
}

void draw_castle(int h, int w)
{
    int i, j;

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            if (i == 0 || i == h - 1)
            {
                printf("%c", '-');
            }
            else if (j == 0 || j == w - 1)
            {
                printf("%c", '|');
            }
            else
            {
                printf("%c", '.');
            }
        }

        printf("\n");
    }
}