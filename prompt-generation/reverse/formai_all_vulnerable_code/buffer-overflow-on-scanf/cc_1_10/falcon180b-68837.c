//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Function to remove non-alphanumeric characters from a string
void sanitize(char* str) {
    int i = 0;
    int j = 0;
    while (str[i]) {
        if (isalnum(str[i])) {
            str[j] = str[i];
            j++;
        }
        i++;
    }
    str[j] = '\0';
}

int main() {
    char url[1000];
    printf("Enter a URL: ");
    scanf("%s", url);

    // Sanitize the input URL
    sanitize(url);

    // Check if the URL is valid
    if (url[0]!= 'h' || url[1]!= 't' || url[2]!= 't' || url[3]!= 'p' || url[4]!= ':') {
        printf("Invalid URL\n");
        return 1;
    }

    int protocol_length = 5; // Length of "http://" or "https://"
    int host_start = protocol_length;
    while (url[host_start]!= '/') {
        host_start++;
    }
    int host_length = host_start - protocol_length;

    // Check if the host name is valid
    if (host_length == 0 || host_length > 255) {
        printf("Invalid host name\n");
        return 1;
    }

    // Check if the protocol is valid
    if (strncmp(url, "http://", protocol_length)!= 0 && strncmp(url, "https://", protocol_length)!= 0) {
        printf("Invalid protocol\n");
        return 1;
    }

    // Check if the URL is well-formed
    int i = host_start;
    while (url[i]) {
        if (!isalnum(url[i]) && url[i]!= '.' && url[i]!= '-' && url[i]!= '_') {
            printf("Invalid character in URL\n");
            return 1;
        }
        i++;
    }

    printf("Valid URL\n");
    return 0;
}