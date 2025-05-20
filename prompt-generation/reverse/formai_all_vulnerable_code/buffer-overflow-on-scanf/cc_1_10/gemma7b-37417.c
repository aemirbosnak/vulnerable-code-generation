//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: portable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LEN 255

char sanitize_url(char *url)
{
    char *p = url;
    char *q = url;

    // Remove leading and trailing spaces
    while (isspace(*p))
    {
        p++;
    }
    while (isspace(*q))
    {
        q--;
    }

    // Convert special characters to ASCII
    for (; *p && !isspace(*p); p++)
    {
        switch (*p)
        {
            case ';':
            case ':':
            case '?':
            case '/':
            case '*':
            case '+':
            case '#':
            case '$':
            case '(':
            case ')':
            case '[':
            case ']':
                *p = '_';
                break;
            default:
                break;
        }
    }

    // Normalize case
    char *u = url;
    while (*u)
    {
        *u = tolower(*u);
        u++;
    }

    // Return sanitized URL
    return q - url + 1;
}

int main()
{
    char url[MAX_URL_LEN];

    printf("Enter an URL: ");
    scanf("%s", url);

    int len = sanitize_url(url);

    printf("Sanitized URL: ");
    printf("%s", url);

    printf("\nLength of sanitized URL: %d", len);

    return 0;
}