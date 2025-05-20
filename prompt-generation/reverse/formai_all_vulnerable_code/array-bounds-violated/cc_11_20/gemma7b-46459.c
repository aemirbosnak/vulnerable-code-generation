//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LEN 256

int main()
{
    char url[MAX_URL_LEN];
    int i, len, valid = 1;
    printf("Enter a URL: ");
    scanf("%s", url);

    len = strlen(url);

    // Validate the URL format
    for (i = 0; i < len; i++)
    {
        // Check for invalid characters
        if (!isalnum(url[i]) && url[i] != '/' && url[i] != '.' && url[i] != '-')
        {
            valid = 0;
        }
    }

    // Check for valid TLDs
    if (valid && url[len - 1] == '/')
    {
        char tld[3];
        tld[0] = url[len - 2];
        tld[1] = url[len - 1];
        tld[2] = '\0';

        if (strcmp(tld, "com") == 0 || strcmp(tld, "net") == 0 || strcmp(tld, "org") == 0)
        {
            valid = 1;
        }
    }

    // Print the sanitized URL
    if (valid)
    {
        printf("Sanitized URL: %s\n", url);
    }
    else
    {
        printf("Invalid URL.\n");
    }

    return 0;
}