//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 256

void sanitize_url(char *url)
{
    char *p = url;
    char *q = url;

    // Remove leading and trailing spaces
    while (*p && isspace(*p))
    {
        p++;
    }
    while (*q && isspace(*q))
    {
        q--;
    }

    // Convert special characters to ASCII
    p = q + 1;
    while (*p)
    {
        if (!isalnum(*p))
        {
            *p = '_';
        }
        p++;
    }

    // Normalize case
    p = url;
    while (*p)
    {
        *p = tolower(*p);
        p++;
    }

    // Remove unnecessary characters
    p = url;
    q = strchr(p, '?');
    if (q)
    {
        *q = '\0';
    }
    p = strchr(url, '#');
    if (p)
    {
        *p = '\0';
    }
}

int main()
{
    char url[MAX_URL_LENGTH];

    printf("Enter a URL: ");
    scanf("%s", url);

    sanitize_url(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}