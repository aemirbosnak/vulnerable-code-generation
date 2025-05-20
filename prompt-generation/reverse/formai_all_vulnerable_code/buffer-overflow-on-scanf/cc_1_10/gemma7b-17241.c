//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: careful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 255

void sanitize_url(char *url)
{
    char *p = url;
    char *start = NULL;
    char *end = NULL;

    // Remove leading and trailing spaces
    while (*p && isspace(*p))
    {
        p++;
    }

    // Find the start of the URL
    while (*p && !isalnum(*p))
    {
        p++;
    }

    // Find the end of the URL
    while (*p && isalnum(*p))
    {
        end = p;
        p++;
    }

    // If the URL is valid, copy it to a new string
    if (start)
    {
        int length = end - start + 1;
        char *new_url = malloc(length);
        memcpy(new_url, start, length);
        new_url[length - 1] = '\0';
        printf("Sanitized URL: %s\n", new_url);
        free(new_url);
    }
    else
    {
        printf("Invalid URL.\n");
    }
}

int main()
{
    char url[MAX_URL_LENGTH];

    printf("Enter a URL: ");
    scanf("%s", url);

    sanitize_url(url);

    return 0;
}