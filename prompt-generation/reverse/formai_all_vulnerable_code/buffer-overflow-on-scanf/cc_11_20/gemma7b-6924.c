//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: single-threaded
#include <stdio.h>
#include <string.h>

int main()
{
    char str[1000];

    printf("Enter a string: ");
    scanf("%s", str);

    if (strlen(str) >= 50)
    {
        printf("The string is too long.\n");
    }
    else
    {
        int spam_score = 0;

        // Check for common spam words
        char* spam_words[] = {"free", "lottery", "miracle", "prize", "miracle"};
        for (int i = 0; i < 5; i++)
        {
            if (strstr(str, spam_words[i]) != NULL)
            {
                spam_score++;
            }
        }

        // Check for suspicious punctuation
        if (str[0] == '$' || str[0] == '%')
        {
            spam_score++;
        }

        // Check for unusual character combinations
        if (str[0] == 'a' && str[1] == 'b' && str[2] == 'c' && str[3] == 'd')
        {
            spam_score++;
        }

        // Check for excessive capitalization
        if (str[0] == str[0] && str[1] == str[1] && str[2] == str[2])
        {
            spam_score++;
        }

        // Check for keyword density
        if (spam_score >= 3)
        {
            printf("The string is likely to be spam.\n");
        }
        else
        {
            printf("The string is not likely to be spam.\n");
        }
    }

    return 0;
}