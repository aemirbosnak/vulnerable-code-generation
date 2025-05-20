//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char url[1000], sanitized[1000];
    int i, j, len, flag = 0;

    printf("Enter a URL to sanitize: ");
    fgets(url, 1000, stdin);

    // Remove newline character
    len = strlen(url);
    if (url[len - 1] == '\n')
    {
        url[len - 1] = '\0';
        len--;
    }

    // Check for http/https
    if (strncmp(url, "http://", 7) == 0)
    {
        flag = 1;
        j = 7;
    }
    else if (strncmp(url, "https://", 8) == 0)
    {
        flag = 1;
        j = 8;
    }

    if (flag)
    {
        // Sanitize URL
        for (i = 0; j < len; i++, j++)
        {
            sanitized[i] = toupper(url[j]);
        }
        sanitized[i] = '\0';

        printf("Sanitized URL: %s", sanitized);

        return 0;
    }
    else
    {
        printf("Invalid URL!");

        return 1;
    }
}