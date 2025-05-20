//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

/* Function to remove leading and trailing white spaces from a string */
void trim(char* str) {
    int len = strlen(str);
    while(isspace(str[0])) {
        str++;
        len--;
    }
    while(isspace(str[len - 1])) {
        str[--len] = '\0';
    }
}

/* Function to check if a character is valid in a URL */
int is_valid_url_char(char c) {
    if(isalnum(c) || (c == '.' || c == '-' || c == '_' || c == '~')) {
        return 1;
    }
    return 0;
}

/* Function to sanitize a URL */
void sanitize_url(char* url) {
    int i, j;
    char valid_url[MAX_URL_LENGTH];
    valid_url[0] = '\0';

    /* Remove leading and trailing white spaces */
    trim(url);

    /* Convert all characters to lowercase */
    for(i = 0; url[i]!= '\0'; i++) {
        valid_url[i] = tolower(url[i]);
    }

    /* Remove invalid characters */
    for(i = 0, j = 0; url[i]!= '\0'; i++) {
        if(is_valid_url_char(url[i])) {
            valid_url[j++] = url[i];
        }
    }
    valid_url[j] = '\0';

    /* Replace multiple dots or slashes with a single one */
    j = 0;
    for(i = 0; valid_url[i]!= '\0'; i++) {
        if(valid_url[i] == '.' || valid_url[i] == '/') {
            if(j > 0 && (valid_url[i - 1] == '.' || valid_url[i - 1] == '/')) {
                continue;
            }
            j++;
        }
        valid_url[i] = valid_url[j++];
    }
    valid_url[j] = '\0';

    /* Copy the sanitized URL back to the original string */
    strcpy(url, valid_url);
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL to sanitize: ");
    scanf("%s", url);
    sanitize_url(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}