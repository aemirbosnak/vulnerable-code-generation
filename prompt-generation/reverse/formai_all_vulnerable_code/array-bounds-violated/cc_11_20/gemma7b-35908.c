//Gemma-7B DATASET v1.0 Category: User Input Sanitizer ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[1024];
    int i = 0, flag = 0;

    printf("Enter a string: ");
    fgets(str, 1024, stdin);

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
            flag = 1;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 32;
            flag = 1;
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            if (str[i - 1] != '-')
            {
                str[i] = str[i] - 48;
                flag = 1;
            }
        }
        else if (str[i] == ' ')
        {
            str[i] = '\0';
            flag = 1;
        }
    }

    if (flag)
    {
        printf("Sanitized string: %s\n", str);
    }
    else
    {
        printf("No changes were made.\n");
    }

    return 0;
}