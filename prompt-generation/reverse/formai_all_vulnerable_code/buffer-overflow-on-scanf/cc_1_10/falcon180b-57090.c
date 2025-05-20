//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_URL_LENGTH 2048

int is_valid_url_char(char c)
{
    if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '/' || c == '?' || c == '&' || c == '=' || c == '+' || c == '%' || c == '$')
    {
        return 1;
    }
    return 0;
}

int is_valid_url(char *url)
{
    int i;
    for (i = 0; i < strlen(url); i++)
    {
        if (!is_valid_url_char(url[i]))
        {
            return 0;
        }
    }
    return 1;
}

void sanitize_url(char *url)
{
    int i, j;
    char sanitized_url[MAX_URL_LENGTH];
    sanitized_url[0] = '\0';

    for (i = 0, j = 0; i < strlen(url); i++)
    {
        if (is_valid_url_char(url[i]))
        {
            sanitized_url[j++] = url[i];
        }
    }
    sanitized_url[j] = '\0';
    strcpy(url, sanitized_url);
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