//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

int is_valid_url(char *url);

int main(int argc, char *argv[])
{
    char url[MAX_URL_LENGTH];
    printf("Enter the URL to sanitize: ");
    scanf("%s", url);

    if (is_valid_url(url))
    {
        printf("The URL is valid and sanitized.\n");
    }
    else
    {
        printf("The URL is not valid and cannot be sanitized.\n");
    }

    return 0;
}

int is_valid_url(char *url)
{
    int length = strlen(url);
    if (length >= MAX_URL_LENGTH)
    {
        return 0;
    }

    char *valid_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-._~:/?#[]@!$&'()*+,;=%";
    char *invalid_chars = "\"'<>\\";

    for (int i = 0; i < length; i++)
    {
        if (strchr(valid_chars, url[i]) == NULL)
        {
            if (strchr(invalid_chars, url[i])!= NULL)
            {
                return 0;
            }
        }
    }

    return 1;
}