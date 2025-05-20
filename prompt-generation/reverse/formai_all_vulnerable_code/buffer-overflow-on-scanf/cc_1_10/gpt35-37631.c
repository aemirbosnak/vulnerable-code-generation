//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to replace all instances of substring in a given string
char* replaceAll(char* str, const char* substr, const char* replacement) {
    char* newStr = (char*) malloc(sizeof(char) * 1024);
    char* ptr;
    int i, j = 0;
    for (i = 0; str[i]; i++) {
        if (strstr(&str[i], substr) == &str[i]) {
            strcpy(&newStr[j], replacement);
            j += strlen(replacement);
            i += strlen(substr) - 1;
        } else {
            newStr[j++] = str[i];
        }
    }
    newStr[j] = '\0';
    return newStr;
}

// Function to check if a given URL is valid
int isValidUrl(char* url) {
    int i, len = strlen(url);
    char* ptr;
    if (len <= 0 || !strstr(url, "://")) return 0;

    ptr = strchr(url, ':');
    if (ptr && strstr(ptr, "://")) return 1;

    for (i = 0; i < len; i++) {
        if (!isalnum(url[i]) && url[i] != '.' && url[i] != '-' && url[i] != '_') {
            if (url[i] == ':') {
                break;
            } else {
                return 0;
            }
        }
    }
    return 1;
}

// Function to sanitize a given URL
char* sanitizeUrl(char* url) {
    char* newUrl = (char*) malloc(sizeof(char) * 1024);
    char* ptr, *ret;

    // Remove whitespace from the beginning and end of URL
    strcpy(newUrl, url);
    ptr = newUrl;
    while (isspace(*ptr)) ptr++;
    if (ptr != newUrl) strcpy(newUrl, ptr);
    ptr = newUrl + strlen(newUrl) - 1;
    while (isspace(*ptr)) ptr--;
    *(ptr + 1) = '\0';

    // Convert scheme and host to lowercase
    ptr = strstr(newUrl, "://");
    if (ptr) {
        *ptr = '\0';
        ptr += 3;
        ret = ptr;
        while (*ptr != '\0' && *ptr != '/') {
            if (*ptr >= 'A' && *ptr <= 'Z') *ptr += 32;
            ptr++;
        }
        *ptr = '\0';
        strcat(newUrl, "://");
        strcat(newUrl, ret);
    }

    // Remove default ports (e.g. :80 for HTTP, :443 for HTTPS)
    ptr = strstr(newUrl, "://");
    if (ptr) {
        ptr += 3;
        if (strstr(ptr, ":80/")) {
            *strstr(ptr, ":80/") = '\0';
        } else if (strstr(ptr, ":443/")) {
            *strstr(ptr, ":443/") = '\0';
        }
    }

    // Remove any duplicate slashes (e.g. http://example.com//path)
    ptr = strstr(newUrl, "://");
    if (ptr) {
        ptr += 3;
        while (*ptr != '\0') {
            if (*ptr == '/' && *(ptr + 1) == '/') {
                memmove(ptr, ptr + 1, strlen(ptr));
            }
            ptr++;
        }
    }

    // Remove any trailing slash
    ptr = newUrl + strlen(newUrl) - 1;
    if (*ptr == '/') *ptr = '\0';

    // Remove any query string (? followed by key-value pairs)
    strstr(newUrl, "?")[0] = '\0';

    // Remove any fragments (# followed by anchor name)
    strstr(newUrl, "#")[0] = '\0';

    // Remove any leading double slashes (e.g. //example.com/path)
    if (strstr(newUrl, "//") == newUrl) {
        memmove(newUrl, newUrl + 2, strlen(newUrl) - 1);
    }

    // Remove any trailing dots (e.g. http://example.com/path.)
    if (newUrl[strlen(newUrl) - 1] == '.') {
        newUrl[strlen(newUrl) - 1] = '\0';
    }

    // Replace any %20 with space
    ret = replaceAll(newUrl, "%20", " ");

    // Return the sanitized URL
    free(newUrl);
    return ret;
}

int main() {
    char url[1024];
    printf("Enter the URL to sanitize: ");
    scanf("%[^\n]", url);
    printf("Original URL: %s\n", url);
    if (isValidUrl(url)) {
        char* sanitizedUrl = sanitizeUrl(url);
        printf("Sanitized URL: %s\n", sanitizedUrl);
        free(sanitizedUrl);
    } else {
        printf("This is not a valid URL.\n");
    }
    return 0;
}