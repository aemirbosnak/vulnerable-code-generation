//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the URL
#define MAX_URL_SIZE 1024

// Declare the function to sanitize the URL
char *sanitize_url(char *url);

// Define the main function
int main()
{
    // Declare the input URL
    char input_url[MAX_URL_SIZE];

    // Prompt the user to enter the URL
    printf("Enter the URL to be sanitized: ");
    scanf("%s", input_url);

    // Sanitize the URL
    char *sanitized_url = sanitize_url(input_url);

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);

    // Free the memory allocated for the sanitized URL
    free(sanitized_url);

    return 0;
}

// Define the function to sanitize the URL
char *sanitize_url(char *url)
{
    // Allocate memory for the sanitized URL
    char *sanitized_url = (char *)malloc(MAX_URL_SIZE);

    // Copy the original URL to the sanitized URL
    strcpy(sanitized_url, url);

    // Replace all spaces with underscores
    for (int i = 0; i < strlen(sanitized_url); i++)
    {
        if (sanitized_url[i] == ' ')
        {
            sanitized_url[i] = '_';
        }
    }

    // Remove all special characters
    for (int i = 0; i < strlen(sanitized_url); i++)
    {
        if (!isalnum(sanitized_url[i]) && sanitized_url[i] != '_' && sanitized_url[i] != '.')
        {
            sanitized_url[i] = '\0';
        }
    }

    // Return the sanitized URL
    return sanitized_url;
}