//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 4096

int is_valid_url_char(char c)
{
    if (isalnum(c) || c == '-' || c == '.' || c == '_' || c == '~' || c == '!' || c == '*' || c == '\'' || c == '(' || c == ')' || c == ';' || c == ':' || c == '@' || c == '&' || c == '=' || c == '+' || c == '$' || c == ',')
        return 1;
    return 0;
}

int is_valid_url(char *url)
{
    int i;
    for (i = 0; i < strlen(url); i++)
    {
        if (!is_valid_url_char(url[i]))
            return 0;
    }
    return 1;
}

char *sanitize_url(char *url)
{
    int i, j;
    char *sanitized_url;

    sanitized_url = malloc(MAX_URL_LENGTH);
    if (sanitized_url == NULL)
    {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }

    i = j = 0;
    while (url[i]!= '\0')
    {
        if (is_valid_url_char(url[i]))
        {
            sanitized_url[j++] = url[i];
        }
        i++;
    }
    sanitized_url[j] = '\0';

    return sanitized_url;
}

int main()
{
    char url[MAX_URL_LENGTH];
    char *sanitized_url;

    printf("Enter a URL: ");
    scanf("%s", url);

    sanitized_url = sanitize_url(url);

    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);

    return 0;
}