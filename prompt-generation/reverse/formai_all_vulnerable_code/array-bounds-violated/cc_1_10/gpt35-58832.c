//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void sanitize_url(char* url);

int main()
{
    char url[256];
    
    printf("Enter a URL: ");
    fgets(url, 256, stdin);
    
    sanitize_url(url);
    
    printf("Sanitized URL: %s\n", url);

    return 0;
}

void sanitize_url(char* url)
{
    char temp[256];
    int i, j;
    
    // Remove all whitespace characters from the URL
    for (i = 0, j = 0; i < strlen(url); i++)
    {
        if (!isspace(url[i]))
        {
            temp[j] = url[i];
            j++;
        }
    }
    
    temp[j] = '\0'; // null-terminate the temporary string
    
    // Remove any trailing slash at the end of the URL
    if (temp[strlen(temp) - 1] == '/')
    {
        temp[strlen(temp) - 1] = '\0';
    }
    
    // Convert the URL to lowercase
    for (i = 0; i < strlen(temp); i++)
    {
        temp[i] = tolower(temp[i]);
    }
    
    // Copy the sanitized URL back to the original buffer
    strcpy(url, temp);
}