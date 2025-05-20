//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: synchronous
#include <stdio.h>
#include <string.h>

#define MAX_URL_LENGTH 256

int main()
{
    char url[MAX_URL_LENGTH];

    printf("Enter a URL: ");
    scanf("%s", url);

    // Sanitize the URL
    url_sanitizer(url);

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", url);

    return 0;
}

int url_sanitizer(char *url)
{
    // Remove invalid characters
    char *p = url;
    while (*p)
    {
        if (!isalnum(*p) && *p != '-' && *p != '_')
        {
            *p = '\0';
        }
        p++;
    }

    // Normalize case
    char *u = url;
    while (*u)
    {
        *u = tolower(*u);
        u++;
    }

    // Remove trailing slashes
    char *t = url;
    while (*t && *t != '/')
    {
        t++;
    }
    if (*t)
    {
        *t = '\0';
    }

    return 0;
}