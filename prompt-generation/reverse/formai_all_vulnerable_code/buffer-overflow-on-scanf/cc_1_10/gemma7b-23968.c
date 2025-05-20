//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: grateful
#include <stdio.h>
#include <string.h>

#define MAX_URL_LENGTH 256

void sanitize_url(char *url)
{
    char *p = url;
    char *q = url;

    // Remove leading and trailing spaces
    while (*p == ' ')
    {
        p++;
    }
    while (*q && *q != ' ')
    {
        q++;
    }

    // Replace all occurrences of "//" with "/"
    char *r = strstr(p, "//");
    while (r)
    {
        strcpy(r, "/");
        r = strstr(r, "//");
    }

    // Remove all special characters
    char invalid_chars[] = {"!()[]{}\"*'<>|\\^`~"};
    for (int i = 0; invalid_chars[i] != '\0'; i++)
    {
        while (*p && *p == invalid_chars[i])
        {
            p++;
        }
    }

    // Trim the url
    if (q - p)
    {
        memcpy(url, p, q - p);
    }
    else
    {
        url[0] = '\0';
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