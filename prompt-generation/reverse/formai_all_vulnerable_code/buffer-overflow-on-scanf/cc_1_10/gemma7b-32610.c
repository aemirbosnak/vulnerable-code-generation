//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LEN 255

void sanitize_url(char *url)
{
    char *p = url;
    char *q = url;

    // Strip leading and trailing spaces
    while (*p == ' ')
    {
        p++;
    }
    while (*q && *q != ' ')
    {
        q++;
    }

    // Remove invalid characters
    while (*p)
    {
        if ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z') || (*p >= '0' && *p <= '9') || (*p == '-') || (*p == '_') || (*p == '.'))
        {
            p++;
        }
        else
        {
            *q = *p;
            q++;
        }
    }

    // Null-terminate the sanitized URL
    *q = NULL;

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", url);
}

int main()
{
    char url[MAX_URL_LEN];

    printf("Enter an URL: ");
    scanf("%s", url);

    sanitize_url(url);

    return 0;
}