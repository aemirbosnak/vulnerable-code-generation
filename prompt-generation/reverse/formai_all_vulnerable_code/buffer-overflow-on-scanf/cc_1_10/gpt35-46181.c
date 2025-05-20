//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Prototypes
 */
int isAlphaNumeric(char c);
void sanitizeUrl(char *url);

/*
 * Main function
 */
int main(int argc, char const *argv[])
{
    char url[100];

    // Take user input
    printf("Enter a URL (Max. 100 characters): ");
    scanf("%s", url);

    // Sanitize URL
    sanitizeUrl(url);

    // Display sanitized URL
    printf("\nSanitized URL: %s\n", url);

    return 0;
}

/*
 * Function to check if a character is alphanumeric
 */
int isAlphaNumeric(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
        return 1;
    }
    return 0;
}

/*
 * Function to sanitize a URL
 */
void sanitizeUrl(char *url)
{
    char temp[100]; // Temporary buffer
    int i, j = 0;

    // Loop through URL
    for (i = 0; url[i] != '\0'; i++) {

        // If character is alphanumeric or a slash or a dot
        if (isAlphaNumeric(url[i]) || url[i] == '/' || url[i] == '.') {
            temp[j] = url[i];
            j++;
        }
    }

    // Null terminate temporary buffer
    temp[j] = '\0';

    // Copy temporary buffer to original URL
    strcpy(url, temp);
}