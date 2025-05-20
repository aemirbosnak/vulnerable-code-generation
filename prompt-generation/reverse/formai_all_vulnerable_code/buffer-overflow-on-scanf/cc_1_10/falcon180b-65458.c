//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Function to sanitize a URL */
char* sanitize_url(char* url) {
    char* sanitized_url = (char*)malloc(strlen(url) + 1);
    int i = 0, j = 0;

    /* Sanitize the URL */
    while(url[i]) {
        if(isalnum(url[i])) {
            sanitized_url[j++] = tolower(url[i]);
        }
        i++;
    }
    sanitized_url[j] = '\0';

    return sanitized_url;
}

/* Function to check if a URL is valid */
int is_valid_url(char* url) {
    char* protocol;
    int i = 0, j = 0;

    /* Check if the URL starts with a protocol */
    while(url[i]!= ':') {
        i++;
    }
    i++;
    protocol = (char*)malloc(i - j + 1);
    strncpy(protocol, url, i - j);
    protocol[i - j] = '\0';

    /* Check if the protocol is valid */
    if(strcmp(protocol, "http")!= 0 && strcmp(protocol, "https")!= 0) {
        free(protocol);
        return 0;
    }
    free(protocol);

    /* Check if the URL contains a domain name */
    while(url[i]!= '/') {
        i++;
    }
    i++;
    while(url[i]!= '/') {
        i++;
    }
    j = i;
    while(url[i]!= '\0') {
        if(!isalnum(url[i])) {
            free(protocol);
            return 0;
        }
        i++;
    }

    /* Check if the URL contains a valid top-level domain */
    while(url[i]!= '\0') {
        if(!isalnum(url[i])) {
            free(protocol);
            return 0;
        }
        i++;
    }

    return 1;
}

int main() {
    char input_url[100];
    char* sanitized_url;
    int is_valid;

    printf("Enter a URL: ");
    scanf("%s", input_url);

    sanitized_url = sanitize_url(input_url);
    is_valid = is_valid_url(sanitized_url);

    if(is_valid) {
        printf("The URL is valid: %s\n", sanitized_url);
    } else {
        printf("The URL is not valid.\n");
    }

    free(sanitized_url);
    return 0;
}