//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>

void main()
{
    system("cls");
    char text[20];
    printf("Enter text: ");
    scanf("%s", text);

    int len = strlen(text);
    int i = 0;

    for (i = 0; i < len; i++)
    {
        switch (text[i])
        {
            case 'a':
            case 'A':
                printf("  /\n"
                       " | \"\n"
                       " \__) \n");
                break;
            case 'e':
            case 'E':
                printf("           /\n"
                       "          |||\n"
                       "           \__)\n");
                break;
            case 'i':
            case 'I':
                printf("           /\n"
                       "          |||\n"
                       "           \__)\n");
                break;
            case 'o':
            case 'O':
                printf("           /\n"
                       "          |||\n"
                       "           \__)\n");
                break;
            case 'u':
            case 'U':
                printf("  /\n"
                       " | \"\n"
                       " \__) \n");
                break;
            default:
                printf(" ");
        }
    }

    printf("\n");
    system("pause");
}