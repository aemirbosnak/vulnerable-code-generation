//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[1000];
    int i, j, flag = 0;

    printf("Enter a message: ");
    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++)
    {
        // Check for uppercase letters
        if (isupper(str[i]))
        {
            flag = 1;
        }

        // Check for exclamation marks
        if (str[i] == '!')
        {
            flag = 1;
        }

        // Check for dollar signs
        if (str[i] == '$')
        {
            flag = 1;
        }

        // Check for multiple consecutive special characters
        if (str[i] == str[i-1] && str[i] == str[i-2] && str[i] == str[i-3] && flag == 0)
        {
            flag = 1;
        }
    }

    if (flag == 1)
    {
        printf("Spam detected!\n");
    }
    else
    {
        printf("No spam detected.\n");
    }

    return 0;
}