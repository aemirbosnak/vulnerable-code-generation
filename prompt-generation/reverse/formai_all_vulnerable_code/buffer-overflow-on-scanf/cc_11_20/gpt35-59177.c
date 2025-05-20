//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char url[1000];
    printf("Enter a URL to sanitize: \n");
    scanf("%s", url);

    // Convert entire URL to lowercase
    for (int i = 0; i < strlen(url); i++) {
        url[i] = tolower(url[i]);
    }

    // Remove any spaces
    int j = 0;
    for (int i = 0; i < strlen(url); i++) {
        if (url[i] != ' ') {
            url[j] = url[i];
            j++;
        }
    }
    url[j] = '\0';

    // Check if the URL starts with "http://" or "https://"
    if (strncmp(url, "http://", 7) != 0 && strncmp(url, "https://", 8) != 0) {
        printf("The URL you entered does not start with 'http://' or 'https://'.\n");
        return 0;
    }

    int k = 0;
    char sanitized_url[1000];

    // Copy the protocol into the sanitized URL
    if (strncmp(url, "http://", 7) == 0) {
        strcpy(sanitized_url, "http://");
        k += 7;
    } else if (strncmp(url, "https://", 8) == 0) {
        strcpy(sanitized_url, "https://");
        k += 8;
    }

    // Remove any duplicate slashes
    while (url[k] != '\0') {
        if (url[k] == '/') {
            if (sanitized_url[strlen(sanitized_url)-1] != '/') {
                strcat(sanitized_url, "/");
            }
        } else {
            strncat(sanitized_url, &url[k], 1);
        }
        k++;
    }

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);
    return 0;
}