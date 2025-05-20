//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_URL_LEN 2048

int is_valid_url_char(char c)
{
    if (isalnum(c) || c == '-' || c == '.' || c == '_' || c == '~' || c == '!' || c == '$' || c == '&' || c == '\'' || c == '(' || c == ')' || c == '*' || c == '+' || c == ',')
        return 1;
    return 0;
}

int is_valid_url(char *url)
{
    int i, len = strlen(url);
    if (len > MAX_URL_LEN)
        return 0;
    for (i = 0; i < len; i++) {
        if (!is_valid_url_char(url[i]))
            return 0;
    }
    return 1;
}

void sanitize_url(char *url)
{
    int i, len = strlen(url);
    char *new_url = malloc(MAX_URL_LEN);
    int new_len = 0;
    for (i = 0; i < len; i++) {
        if (is_valid_url_char(url[i])) {
            new_url[new_len++] = url[i];
        } else {
            new_url[new_len++] = '%';
            new_url[new_len++] = (url[i] >> 4) + 'A';
            new_url[new_len++] = (url[i] & 0x0F) + 'A';
        }
    }
    new_url[new_len] = '\0';
    strcpy(url, new_url);
    free(new_url);
}

int main()
{
    char url[MAX_URL_LEN] = "http://example.com/?query=string#fragment";
    printf("Original URL: %s\n", url);
    sanitize_url(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}