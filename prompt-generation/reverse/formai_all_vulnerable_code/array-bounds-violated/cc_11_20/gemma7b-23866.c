//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char c;
    int i = 0;
    char str[100] = "";

    printf("Enter C syntax code: ");
    c = getchar();

    while (c != '\n')
    {
        str[i] = c;
        i++;
        c = getchar();
    }

    str[i] = '\0';

    // Parse the C syntax code
    if (str[0] == '{' && str[1] == '}')
    {
        printf("The code is a block.\n");
    }
    else if (str[0] == '}' && str[1] == '}')
    {
        printf("The code is a block closing.\n");
    }
    else if (str[0] == 'if' && str[1] == '(')
    {
        printf("The code is an if statement.\n");
    }
    else if (str[0] == 'else' && str[1] == 'if')
    {
        printf("The code is an else statement.\n");
    }
    else if (str[0] == 'while' && str[1] == '(')
    {
        printf("The code is a while statement.\n");
    }
    else if (str[0] == 'for' && str[1] == '(')
    {
        printf("The code is a for statement.\n");
    }
    else
    {
        printf("The code is not recognized.\n");
    }

    return 0;
}