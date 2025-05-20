//FormAI DATASET v1.0 Category: HTML beautifier ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    printf("--- C HTML Beautifier ---\n\n");

    char input[5000];
    printf("Enter HTML code:\n");
    scanf("%[^\n]", input);

    int indent_level = 0;
    int input_length = strlen(input);
    bool in_tag = false;

    printf("\n--- Beautified code ---\n");

    for(int i = 0; i < input_length; i++)
    {
        if(input[i] == '<')
        {
            in_tag = true;
            printf("\n");

            for(int j = 0; j < indent_level; j++)
            {
                printf("\t");
            }

            printf("<");
            indent_level++;
        }
        else if(input[i] == '>')
        {
            in_tag = false;
            printf(">");
        }
        else if(input[i] == '/')
        {
            indent_level--;
            printf("\n");

            for(int j = 0; j < indent_level; j++)
            {
                printf("\t");
            }

            printf("</");
            in_tag = true;
        }
        else if(input[i] == ' ')
        {
            if(in_tag)
            {
                printf(" ");
            }
            else
            {
                continue;
            }
        }
        else
        {
            printf("%c", input[i]);
        }
    }

    printf("\n\nDone!");
    return 0;
}