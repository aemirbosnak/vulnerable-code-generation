//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void main()
{
    char str[1000];
    printf("Enter a message: ");
    gets(str);

    int len = strlen(str);
    int i = 0;
    int spam_score = 0;

    for (i = 0; i < len; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            spam_score++;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            spam_score++;
        }
        else if (str[i] == '!')
        {
            spam_score++;
        }
        else if (str[i] == '$')
        {
            spam_score++;
        }
        else if (str[i] == '%')
        {
            spam_score++;
        }
        else if (str[i] == '&')
        {
            spam_score++;
        }
        else if (str[i] == ')')
        {
            spam_score++;
        }
        else if (str[i] == '(')
        {
            spam_score++;
        }
        else if (str[i] == ' ')
        {
            spam_score++;
        }
    }

    if (spam_score > 5)
    {
        printf("Message is spam.\n");
    }
    else
    {
        printf("Message is not spam.\n");
    }

    return;
}