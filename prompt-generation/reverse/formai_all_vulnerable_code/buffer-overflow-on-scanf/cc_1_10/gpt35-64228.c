//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function to check if the given character is unsafe
int isUnSafe(char c)
{
    if (c >= 'A' && c <= 'Z')
        return 0;
    if (c >= 'a' && c <= 'z')
        return 0;
    if (c >= '0' && c <= '9')
        return 0;
    if (c == '-' || c == '_' || c == '.' || c == '~')
        return 0;
    return 1;
}

//function to perform URL sanitization
char* sanitizeUrl(char* url)
{
    int i = 0, j = 0, len = strlen(url);
    char* sanitizedUrl = (char*)malloc(sizeof(char) * (len + 1));

    while (url[i])
    {
        if (!isUnSafe(url[i]))
        {
            sanitizedUrl[j++] = url[i++];
        }
        else
        {
            sanitizedUrl[j++] = '%';
            sanitizedUrl[j++] = (url[i] >> 4) + '0';
            sanitizedUrl[j++] = (url[i++] & 0x0F) + '0';
        }
    }

    sanitizedUrl[j] = '\0';
    return sanitizedUrl;
}

//main function to test the implementation
int main()
{
    char url[500];

    printf("Enter a URL to sanitize: ");
    scanf("%s", url);

    char* sanitizedUrl = sanitizeUrl(url);
    printf("Sanitized URL: %s\n", sanitizedUrl);

    free(sanitizedUrl);
    return 0;
}