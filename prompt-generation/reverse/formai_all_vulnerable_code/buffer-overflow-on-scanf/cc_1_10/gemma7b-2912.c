//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    // Inspect the string for beauty
    if (strlen(str) < 10)
    {
        printf("The string is too short, dear Watson.\n");
    }
    else
    {
        // Trim the string
        char *p = str;
        while (*p)
        {
            if (*p == ' ')
            {
                *p = '\0';
            }
            p++;
        }

        // Adjust the sentence structure
        char *q = str;
        int i = 0;
        while (*q)
        {
            if (*q == '.')
            {
                q++;
                char *r = str;
                while (*r)
                {
                    if (*r != ' ')
                    {
                        printf("%c ", *r);
                    }
                    r++;
                }
                printf(". ");
            }
            else
            {
                printf("%c ", *q);
            }
            q++;
        }

        // Add a flourish
        printf("Ah, well, here you have it, Watson. The beautified string is:\n");
        printf("%s\n", str);
    }

    return 0;
}