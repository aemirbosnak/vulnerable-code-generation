//Gemma-7B DATASET v1.0 Category: User Input Sanitizer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[1024] = "";
    int i, j, n;

    printf("Enter a mathematical expression: ");
    scanf("%s", str);

    n = strlen(str);

    for (i = 0; i < n; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] - 32;
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            // Leave the number as it is
        }
        else if (str[i] == '+')
        {
            str[i] = ' ';
        }
        else if (str[i] == '-')
        {
            str[i] = ' ';
        }
        else if (str[i] == '*')
        {
            str[i] = ' ';
        }
        else if (str[i] == '/')
        {
            str[i] = ' ';
        }
    }

    printf("Sanitized expression: ");
    printf("%s\n", str);

    return 0;
}