//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: lively
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Function to check if a character is an alpha-numeric character or not
bool isAlnum(char ch) {
    return isalnum((unsigned char)ch);
}

// Function to check if a character is a valid URL character or not
bool isUrlChar(char ch) {
    return (isAlnum(ch) || ch == '-' || ch == '_' || ch == '.' || ch == '~');
}

// Function to remove any trailing slashes from the URL
void removeTrailingSlashes(char* url) {
    int len = strlen(url);
    while (len > 0 && url[len-1] == '/') {
        url[len-1] = '\0';
        len--;
    }
}

// Function to remove any extra consecutive slashes in the URL
void removeConsecutiveSlashes(char* url) {
    int len = strlen(url);
    bool lastWasSlash = false;
    for(int i=0; i<len; i++) {
        if(url[i] == '/') {
            if(lastWasSlash) {
                // Remove this consecutive slash
                for(int j=i+1; j<len; j++) {
                    url[j-1] = url[j];
                }
                url[len-1] = '\0';
                len--;
                i--;
            }
            lastWasSlash = true;
        }
        else {
            lastWasSlash = false;
        }
    }
}

// Function to sanitize the URL
void sanitizeUrl(char* url) {
    removeTrailingSlashes(url);
    removeConsecutiveSlashes(url);
    int len = strlen(url);
    for(int i=0; i<len; i++) {
        if(!isUrlChar(url[i])) {
            // Replace this character with its URL-encoded equivalent
            char buf[5];
            sprintf(buf, "%%%02X", url[i]);
            url[i] = buf[0];
            url[i+1] = buf[1];
            url[i+2] = buf[2];
            i += 2;
            len += 2;
        }
    }
} 

int main() {
    char url[1024];
    printf("Enter a URL to sanitize: ");
    fgets(url, 1024, stdin);
    // Check if the URL is too long
    if(strlen(url) == 1023 && url[1022] != '\n') {
        printf("URL is too long\n");
        return 0;
    }
    // Remove any newline characters from the input
    int len = strlen(url);
    if(url[len-1] == '\n') {
        url[len-1] = '\0';
    }
    // Sanitize the URL
    sanitizeUrl(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}