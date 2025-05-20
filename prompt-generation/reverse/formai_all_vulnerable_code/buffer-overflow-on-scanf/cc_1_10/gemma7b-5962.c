//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 255

void sanitize_url(char *url)
{
    char *p = url;
    char *start = NULL;
    char *end = NULL;

    // Remove all non-alphanumeric characters
    while (p)
    {
        if (!isalnum(*p) && *p != '-' && *p != '_')
        {
            p = strcspn(p, "abcdefghijklmnopqrstqaz ABCDEFGHIJKLMNOPQRSTUVWXYZ0123_");
            continue;
        }

        if (start == NULL)
        {
            start = p;
        }

        if (end == NULL)
        {
            end = p;
        }

        p++;
    }

    // Replace consecutive special characters with underscore
    if (start && end)
    {
        char *q = start;
        while (q < end)
        {
            if (isalnum(*q) && isalnum(*(q + 1)) && *q == *(q + 1) && *q != '-')
            {
                *(q + 1) = '_';
            }
            q++;
        }
    }

    // Return the sanitized URL
    printf("Sanitized URL: %s\n", start);
}

int main()
{
    char url[MAX_URL_LENGTH];

    // Get the URL from the user
    printf("Enter a URL: ");
    scanf("%s", url);

    // Sanitize the URL
    sanitize_url(url);

    return 0;
}