//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    printf("Welcome to the Text to ASCII Art Generator!\n");
    printf("Please provide a text: ");

    char text[100];
    scanf("%s", text);

    int length = strlen(text);
    int i = 0;

    for (i = 0; i < length; i++)
    {
        switch (text[i])
        {
            case 'a':
            case 'A':
                printf("  /\n"
                       " | \__)\n"
                       " \__) |\n");
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
                       "           \__)\n"
                       "           /\n");
                break;

            case 'o':
            case 'O':
                printf("           /\n"
                       "          |||\n"
                       "           \__)\n"
                       "           /\n");
                break;

            case 'u':
            case 'U':
                printf("           /\n"
                       "          |||\n"
                       "           \__)\n"
                       "           /\n");
                break;

            default:
                printf(" ");
                break;
        }
    }

    printf("\n");
    printf("Thank you for using the Text to ASCII Art Generator!\n");

    return 0;
}