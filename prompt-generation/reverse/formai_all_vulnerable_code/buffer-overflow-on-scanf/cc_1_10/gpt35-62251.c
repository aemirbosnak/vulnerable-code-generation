//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_URL_LENGTH 10000

void sanitize_url(char *url);

int main()
{
    char url[MAX_URL_LENGTH];
    printf("Welcome to the URL Sanitizer!\n");
    printf("Please enter the URL to be sanitized (must start with http:// or https://): ");
    scanf("%s", url);
    sanitize_url(url);
    printf("\nYour sanitized URL is: %s\n", url);
    printf("\nThank you for using the URL Sanitizer! Have a great day!\n");
    return 0;
}

void sanitize_url(char *url)
{
    int url_length = strlen(url);

    // Check if URL starts with http:// or https://
    if ((strncmp(url, "http://", 7) != 0) && (strncmp(url, "https://", 8) != 0))
    {
        printf("\nOops! The URL does not start with http:// or https://. Please try again.\n");
        exit(0);
    }

    // Remove any trailing slashes
    while (url[url_length - 1] == '/')
    {
        url_length--;
        url[url_length] = '\0';
    }

    // Remove any query parameters
    char *question_mark_position = strchr(url, '?');
    if (question_mark_position != NULL)
    {
        *question_mark_position = '\0';
        url_length = strlen(url);
    }

    // Remove any fragment identifiers
    char *hash_mark_position = strchr(url, '#');
    if (hash_mark_position != NULL)
    {
        *hash_mark_position = '\0';
        url_length = strlen(url);
    }

    // Remove any double slashes after http:// or https://
    char *start_position = strstr(url, "//");
    if (start_position != NULL)
    {
        start_position += 2;

        char *end_position = strstr(start_position, "/");
        if (end_position != NULL)
        {
            int copy_length = strlen(end_position) + 1;
            char temp_buffer[MAX_URL_LENGTH];
            strcpy(temp_buffer, end_position);
            memcpy(start_position, temp_buffer, copy_length);
            url_length -= (int)(end_position - start_position);
        }
    }

    // Remove any single dots and double dots in the path
    char *current_position = url;
    int path_length = 0;
    while (*current_position != '\0')
    {
        if (strncmp(current_position, "/./", 3) == 0)
        {
            current_position += 2;
        }
        else if (strncmp(current_position, "/../", 4) == 0)
        {
            if (path_length > 1)
            {
                path_length--;
                while ((path_length > 1) && (url[path_length] != '/'))
                {
                    path_length--;
                }
                current_position += 3;
            }
            else
            {
                current_position += 3;
            }
        }
        else
        {
            url[path_length] = *current_position;
            current_position++;
            path_length++;
        }
    }
    url[path_length] = '\0';
}