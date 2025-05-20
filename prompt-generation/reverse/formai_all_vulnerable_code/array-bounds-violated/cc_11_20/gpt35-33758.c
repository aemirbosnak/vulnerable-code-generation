//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_URL_LENGTH 1024
#define MAX_PATH_DEPTH 10

int main()
{
    char input_url[MAX_URL_LENGTH];
    bool valid_url = true;
    
    printf("Please enter the URL to be sanitized: ");
    scanf("%s", input_url);
    
    // Remove any trailing slashes
    if (input_url[strlen(input_url) - 1] == '/')
    {
        input_url[strlen(input_url) - 1] = '\0';
    }
    
    // Split the URL into parts
    char *delimiter = "/";
    char *path[MAX_PATH_DEPTH];
    char *pch;
    int i = 0;
    
    pch = strtok(input_url, delimiter);
    
    while (pch != NULL && i < MAX_PATH_DEPTH)
    {
        path[i] = pch;
        i++;
        pch = strtok(NULL, delimiter);
    }
    
    int path_depth = i;
    
    // Check the protocol
    if (strncmp(input_url, "http://", 7) != 0 && strncmp(input_url, "https://", 8) != 0)
    {
        printf("Invalid protocol.\n");
        valid_url = false;
    }
    
    // Check the domain
    if (path_depth < 2)
    {
        printf("Invalid domain.\n");
        valid_url = false;
    }
    
    // Check the TLD
    char *tld = path[path_depth - 1];
    
    if (strcmp(tld, "com") != 0 && strcmp(tld, "org") != 0 && strcmp(tld, "net") != 0)
    {
        printf("Invalid TLD.\n");
        valid_url = false;
    }
    
    // Reconstruct the URL
    if (valid_url)
    {
        char sanitized_url[MAX_URL_LENGTH];
        memset(sanitized_url, 0, sizeof(sanitized_url));
        strcat(sanitized_url, "https://");
        
        for (i = 1; i < path_depth - 2; i++)
        {
            strcat(sanitized_url, path[i]);
            strcat(sanitized_url, ".");
        }
        
        strcat(sanitized_url, path[path_depth - 2]);
        strcat(sanitized_url, ".");
        strcat(sanitized_url, tld);
        
        printf("Sanitized URL: %s\n", sanitized_url);
    }
    
    return 0;
}