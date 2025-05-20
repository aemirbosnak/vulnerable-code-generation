//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: curious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 1024

char* sanitize_url(char* url) {
    char* sanitized_url = malloc(MAX_LENGTH * sizeof(char));
    int i = 0;
    int j = 0;

    // Remove leading/trailing spaces
    while (isspace(url[i])) {
        i++;
    }
    while (isspace(url[j])) {
        j--;
    }

    // Copy URL to sanitized URL
    for (int k = i; k <= j; k++) {
        if (url[k] == '%') {
            // Handle encoded characters
            if (isxdigit(url[k+1]) && isxdigit(url[k+2])) {
                char hex_value = (url[k+1] - '0') * 16 + (url[k+2] - '0');
                sanitized_url[k] = hex_value;
                k += 2;
            } else {
                sanitized_url[k] = '%';
            }
        } else if (isalnum(url[k])) {
            // Copy alphanumeric characters
            sanitized_url[k] = url[k];
        } else {
            // Replace non-alphanumeric characters with '_'
            sanitized_url[k] = '_';
        }
    }

    sanitized_url[j+1] = '\0'; // Add null terminator

    return sanitized_url;
}

int main() {
    char* url = " ht tp://example.com/path/to/page?query=string&param=value#fragment";
    char* sanitized_url = sanitize_url(url);

    printf("Unsanitized URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);
    return 0;
}