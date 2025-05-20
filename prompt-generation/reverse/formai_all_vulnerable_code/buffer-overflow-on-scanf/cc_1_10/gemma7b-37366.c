//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LEN 255

void sanitize_url(char *url)
{
    char *p = url;
    char *q = url;

    // Remove leading and trailing spaces
    while (isspace(*p))
    {
        p++;
    }

    // Convert to lowercase and remove special characters
    while (*p)
    {
        *q = tolower(*p);
        if (!isalnum(*q) && *q != '-')
        {
            p++;
        }
        else
        {
            q++;
        }
    }

    // Null-terminate the sanitized URL
    *q = '\0';

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", url);
}

int main()
{
    char url[MAX_URL_LEN];

    // Get the URL from the user
    printf("Enter a URL: ");
    scanf("%s", url);

    // Sanitize the URL
    sanitize_url(url);

    return 0;
}