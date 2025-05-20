//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LEN 255

void sanitize_url(char *url)
{
    char *p = url;
    char *q = NULL;
    char *r = NULL;

    // Strip leading and trailing spaces
    while (*p == ' ')
    {
        p++;
    }
    while (*p && *p != ' ')
    {
        p++;
    }

    // Remove invalid characters
    q = strpbrk(p, "<>\"\\|?*()[]\n");
    if (q)
    {
        *q = '\0';
    }

    // Normalize relative URLs
    if (url[0] == '/')
    {
        r = strchr(p, '/');
        if (r)
        {
            *r = '\0';
        }
    }

    // Return sanitized URL
    printf("%s\n", url);
}

int main()
{
    char url[MAX_URL_LEN];

    printf("Enter a URL: ");
    scanf("%s", url);

    sanitize_url(url);

    return 0;
}