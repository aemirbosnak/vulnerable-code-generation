//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: peaceful
#include <stdio.h>
#include <string.h>

int main()
{
    char str[1000];

    printf("Enter a message: ");
    scanf("%s", str);

    int len = strlen(str);

    if (len > 50)
    {
        printf("Message too long. Please try again.\n");
        return 0;
    }

    char words[200][20];

    int i = 0;
    for (i = 0; i < len; i++)
    {
        if (str[i] == ' ')
        {
            words[i][0] = str[i];
            words[i][1] = '\0';
        }
    }

    int spam_score = 0;

    for (i = 0; i < 200; i++)
    {
        if (strcmp(words[i], "free") == 0)
        {
            spam_score++;
        }
        if (strcmp(words[i], "lottery") == 0)
        {
            spam_score++;
        }
        if (strcmp(words[i], "prize") == 0)
        {
            spam_score++;
        }
        if (strcmp(words[i], "miracle") == 0)
        {
            spam_score++;
        }
    }

    if (spam_score > 3)
    {
        printf("Message flagged as spam.\n");
    }
    else
    {
        printf("Message is not spam.\n");
    }

    return 0;
}