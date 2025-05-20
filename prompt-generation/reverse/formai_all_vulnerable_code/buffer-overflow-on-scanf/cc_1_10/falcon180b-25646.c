//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

// Function to sanitize a URL
void sanitize_url(char *url) {
    int i, j;
    char clean_url[MAX_URL_LENGTH];
    clean_url[0] = '\0';

    // Copy the original URL to the clean URL
    strcpy(clean_url, url);

    // Convert all characters to lowercase
    for (i = 0; clean_url[i]!= '\0'; i++) {
        clean_url[i] = tolower(clean_url[i]);
    }

    // Remove any leading or trailing whitespace
    while (isspace(clean_url[0])) {
        memmove(clean_url, clean_url + 1, strlen(clean_url));
        clean_url[strlen(clean_url) - 1] = '\0';
    }

    // Remove any invalid characters
    for (i = 0, j = 0; clean_url[i]!= '\0'; i++) {
        if (isalnum(clean_url[i]) || clean_url[i] == '-') {
            clean_url[j++] = clean_url[i];
        }
    }
    clean_url[j] = '\0';

    // Replace any consecutive dots or slashes with a single dot or slash
    j = 0;
    for (i = 0; clean_url[i]!= '\0'; i++) {
        if (clean_url[i] == '.' || clean_url[i] == '/') {
            if (i > 0 && clean_url[i - 1] == clean_url[i]) {
                continue;
            }
            clean_url[j++] = clean_url[i];
        }
    }
    clean_url[j] = '\0';

    // Add a trailing slash if necessary
    if (strlen(clean_url) > 0 && clean_url[strlen(clean_url) - 1]!= '/') {
        strcat(clean_url, "/");
    }

    // Copy the sanitized URL back to the original URL
    strcpy(url, clean_url);
}

int main() {
    char url[MAX_URL_LENGTH];

    printf("Enter a URL to sanitize: ");
    scanf("%s", url);

    sanitize_url(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}