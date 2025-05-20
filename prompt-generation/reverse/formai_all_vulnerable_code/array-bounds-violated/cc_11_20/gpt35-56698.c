//FormAI DATASET v1.0 Category: Syntax parsing ; Style: retro
#include<stdio.h>

int main()
{
    printf("*****************************************\n");
    printf("*         C SYNTAX PARSING PROGRAM       *\n");
    printf("*                                       *\n");
    printf("*      Enter a line of C code below:    *\n");
    printf("*****************************************\n");

    char input[50];
    fgets(input, 50, stdin);

    // Parsing procedure
    int flag = 0;
    for (int i = 0; input[i] != '\n'; i++)
    {
        if (input[i] == '=')
        {
            printf("Assignment operator found\n");
            flag = 1;
        }
        else if (input[i] == '(' || input[i] == ')')
        {
            printf("Parenthesis found\n");
            flag = 1;
        }
        else if (input[i] == ';')
        {
            printf("End of statement found\n");
            flag = 1;
        }
        else if (input[i] == '{' || input[i] == '}')
        {
            printf("Start/end of block found\n");
            flag = 1;
        }
        else if (input[i] == ',')
        {
            printf("Comma found\n");
            flag = 1;
        }
        else if (input[i] == '#')
        {
            printf("Preprocessor directive found\n");
            flag = 1;
        }
        else if (input[i] == '/')
        {
            if (input[i+1] == '/')
            {
                printf("Single line comment found\n");
                flag = 1;
            }
            else if (input[i+1] == '*')
            {
                printf("Multi-line comment found\n");
                flag = 1;
            }
        }
    }

    // If no syntax found
    if (!flag)
    {
        printf("No syntax found.\n");
    }

    return 0;
}