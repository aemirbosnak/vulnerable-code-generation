//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 256

int main()
{
    char URL[MAX_URL_LENGTH];
    char sanitized_URL[MAX_URL_LENGTH];
    
    printf("Gimme the URL, punk: ");
    scanf("%s", URL);
    
    int has_http = 0;
    int has_https = 0;
    
    // Checking if URL starts with http://
    if(strncmp(URL, "http://", 7) == 0)
    {
        has_http = 1;
    }
    
    // Checking if URL starts with https://
    if(strncmp(URL, "https://", 8) == 0)
    {
        has_https = 1;
    }
    
    // Sanitizing URL
    if(has_http || has_https)
    {
        int i = 0;
        sanitized_URL[0] = '\0';
        while(i < strlen(URL))
        {
            if((URL[i] >= 'A' && URL[i] <= 'Z') || (URL[i] >= 'a' && URL[i] <= 'z') || (URL[i] >= '0' && URL[i] <= '9') || URL[i] == '.' || URL[i] == '/' || URL[i] == ':' || URL[i] == '-')
            {
                strncat(sanitized_URL, &URL[i], 1);
            }
            i++;
        }
        
        if(has_http)
        {
            printf("HTTP detected. Sanitized URL: %s%s\n", "http://", sanitized_URL);
        }
        
        if(has_https)
        {
            printf("HTTPS detected. Sanitized URL: %s%s\n", "https://", sanitized_URL);
        }
    }
    else
    {
        printf("Invalid URL, punk!\n");
    }
    
    return 0;
}