//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 256

int main()
{
    char url[MAX_URL_LENGTH];
    int i, length, valid = 1;

    printf("Enter a URL: ");
    scanf("%s", url);

    length = strlen(url);

    // Check for valid characters
    for (i = 0; i < length && valid; i++)
    {
        if (!((url[i] >= 'a' && url[i] <= 'z') || (url[i] >= 'A' && url[i] <= 'Z') || (url[i] >= '0' && url[i] <= '9') || url[i] == '.' || url[i] == '/' || url[i] == '-'))
        {
            valid = 0;
        }
    }

    // Check for valid domain name
    if (valid && length > 2)
    {
        char domain[MAX_URL_LENGTH];
        int domain_length = 0;

        // Extract the domain name
        for (i = length - 1; i >= 0 && valid; i--)
        {
            if (url[i] == '.')
            {
                domain_length = i - length + 1;
                break;
            }
        }

        // Check if the domain name is valid
        if (domain_length > 0)
        {
            domain[domain_length] = '\0';
            if (strcmp(domain, "com") != 0 && strcmp(domain, "net") != 0 && strcmp(domain, "org") != 0)
            {
                valid = 0;
            }
        }
    }

    // Print the result
    if (valid)
    {
        printf("Your URL is valid.\n");
    }
    else
    {
        printf("Your URL is not valid.\n");
    }

    return 0;
}