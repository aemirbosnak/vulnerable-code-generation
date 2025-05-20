//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[1000];
    int i, j, len;

    printf("Enter the text you want to convert to ASCII art: ");
    scanf("%[^\n]", input);

    len = strlen(input);

    printf("\n");

    for (i = 0; i < len; i++)
    {
        if (input[i] == ' ')
        {
            printf("\n\n\n");
        }
        else if (input[i] == 'a' || input[i] == 'A')
        {
            printf("        ___       \n");
            printf("      ,'___`.     \n");
            printf("  ___/_,.._`\\_\\___\n");
            printf(">'---.``___``|<`.\n");
            printf("     `/    \\ `-' \n");
            printf("     (   d  b     \n");
            printf("      `.___,,'    \n");
        }
        else if (input[i] == 'b' || input[i] == 'B')
        {
            printf(" ,-.        _,---._ __  / \n");
            printf("/  )   _,-' ,-. .  |('o )\n");
            printf("\\`\"``-~` _,-' `-'`. ;:/ \n");
            printf(" `._,-' {     ^  `\"` \\ \n");
            printf("        `\"\"\"\"\"\"\"\"\"\"\"`   \n");
        }
        else if (input[i] == 'c' || input[i] == 'C')
        {
            printf("      .--.\n");
            printf("     /    \\\n");
            printf("    ## a  a\n");
            printf("    (   '._)\n");
            printf("     |'-- |\\\n");
            printf("   _{    } ^\n");
            printf("  / \\   / \\\n");
            printf(" /   \\ /   \\\n");
            printf("\n");
        }
        // Repeat for all letters of the alphabet and any additional symbols you want to include

        printf("\n");
    }

    return 0;
}