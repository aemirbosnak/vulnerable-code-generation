//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: automated
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LEN 255

int main()
{
    char url[MAX_URL_LEN] = "INVALID_URL";
    char sanitized_url[MAX_URL_LEN] = "";

    printf("Enter a URL: ");
    scanf("%s", url);

    // Check if the input is valid
    if (strlen(url) > MAX_URL_LEN - 1)
    {
        printf("Error: URL too long.\n");
        return 1;
    }

    // Remove invalid characters
    for (int i = 0; url[i] != '\0'; i++)
    {
        // Normalize whitespace
        if (isspace(url[i]))
        {
            url[i] = '_';
        }

        // Remove special characters
        if (!isalnum(url[i]) && url[i] != '-' && url[i] != '_')
        {
            url[i] = '\0';
        }
    }

    // Strip trailing slashes
    while (url[strlen(url) - 1] == '/')
    {
        url[strlen(url) - 1] = '\0';
    }

    // Copy the sanitized URL
    strcpy(sanitized_url, url);

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);

    return 0;
}