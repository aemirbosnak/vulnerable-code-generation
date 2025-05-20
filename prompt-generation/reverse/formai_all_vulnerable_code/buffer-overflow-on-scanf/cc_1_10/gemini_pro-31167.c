//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: realistic
#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom sanitizer function to remove specific characters from a URL
int custom_sanitizer(char *url, char *allowed_chars)
{
    // Initialize the sanitized URL
    char *sanitized_url = malloc(strlen(url) + 1);
    strcpy(sanitized_url, "");

    // Iterate over the original URL
    for (int i = 0; i < strlen(url); i++)
    {
        // Check if the current character is allowed
        if (strchr(allowed_chars, url[i]) != NULL)
        {
            // Append the character to the sanitized URL
            strcat(sanitized_url, &url[i]);
        }
    }

    // Replace the original URL with the sanitized version
    strcpy(url, sanitized_url);

    // Free the allocated memory
    free(sanitized_url);

    return 0;
}

int main(int argc, char *argv[])
{
    // Initialize the CURL handle
    CURL *curl = curl_easy_init();
    if (!curl)
    {
        fprintf(stderr, "Error initializing CURL\n");
        return EXIT_FAILURE;
    }

    // Set allowed characters for the URL
    char *allowed_chars = "abcdefghijklmnopqrstuvwxyz"
                            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                            "0123456789"
                            "-._~:/?#[]@!$&'()*+,;=";

    // Get the URL from the user
    char *url = malloc(1024);
    printf("Enter the URL to be sanitized: ");
    scanf("%s", url);

    // Sanitize the URL using the custom function
    custom_sanitizer(url, allowed_chars);

    // Set the URL to be fetched
    curl_easy_setopt(curl, CURLOPT_URL, url);

    // Set the write callback to print the response
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fwrite);

    // Perform the request and get the response
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK)
    {
        fprintf(stderr, "Error performing the request: %s\n", curl_easy_strerror(res));
        return EXIT_FAILURE;
    }

    // Clean up the CURL handle
    curl_easy_cleanup(curl);

    // Free the allocated memory
    free(url);

    return EXIT_SUCCESS;
}