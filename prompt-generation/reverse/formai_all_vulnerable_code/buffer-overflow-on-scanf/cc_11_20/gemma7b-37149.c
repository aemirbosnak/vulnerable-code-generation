//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: Claude Shannon
// Claude Shannon Style Text to ASCII Art Generator

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char text[80];
    int i, j, k;

    printf("Enter text: ");
    scanf("%s", text);

    for (i = 0; text[i] != '\0'; i++)
    {
        switch (text[i])
        {
            case 'a':
            case 'A':
                for (j = 0; j < 4; j++)
                {
                    for (k = 0; k < 5; k++)
                    {
                        printf("%c ", 248);
                    }
                    printf("\n");
                }
                break;

            case 'b':
            case 'B':
                for (j = 0; j < 3; j++)
                {
                    for (k = 0; k < 5; k++)
                    {
                        printf("%c ", 248);
                    }
                    printf("\n");
                }
                break;

            case 'c':
            case 'C':
                for (j = 0; j < 2; j++)
                {
                    for (k = 0; k < 5; k++)
                    {
                        printf("%c ", 248);
                    }
                    printf("\n");
                }
                break;

            default:
                printf("%c ", 248);
        }
    }

    return 0;
}