//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: random
// A not-so-strict URL sanitizer to demonstrate the concept, in a somewhat messy style.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Constants for status codes
#define OK 0
#define INVALID_URL 1
#define MALLOC_ERROR 2

// Function prototypes
char *sanitize_url(char *url);
bool is_valid_protocol(char *protocol);
bool is_valid_domain(char *domain);
bool is_valid_port(char *port);
bool is_valid_path(char *path);

int main() {
    // Get the URL from the user
    char url[256];
    printf("Enter a URL: ");
    scanf("%s", url);

    // Sanitize the URL
    char *sanitized_url = sanitize_url(url);

    // Check if the URL is valid
    if (sanitized_url == NULL) {
        printf("Invalid URL\n");
        return INVALID_URL;
    }

    // Print the sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);

    // Free the memory allocated for the sanitized URL
    free(sanitized_url);

    return OK;
}

// Function to sanitize a URL
char *sanitize_url(char *url) {
    // Check if the URL is valid
    if (!is_valid_protocol(url)) {
        return NULL;
    }

    // Get the protocol, domain, port, and path from the URL
    char *protocol = strtok(url, "://");
    char *domain = strtok(NULL, ":");
    char *port = strtok(NULL, "/");
    char *path = strtok(NULL, "");

    // Check if the protocol, domain, port, and path are valid
    if (!is_valid_domain(domain) || !is_valid_port(port) || !is_valid_path(path)) {
        return NULL;
    }

    // Allocate memory for the sanitized URL
    char *sanitized_url = malloc(strlen(protocol) + strlen(domain) + strlen(port) + strlen(path) + 1);
    if (sanitized_url == NULL) {
        return NULL;
    }

    // Copy the protocol, domain, port, and path into the sanitized URL
    strcpy(sanitized_url, protocol);
    strcat(sanitized_url, "://");
    strcat(sanitized_url, domain);
    strcat(sanitized_url, ":");
    strcat(sanitized_url, port);
    strcat(sanitized_url, "/");
    strcat(sanitized_url, path);

    // Return the sanitized URL
    return sanitized_url;
}

// Function to check if a protocol is valid
bool is_valid_protocol(char *protocol) {
    // Check if the protocol is "http" or "https"
    return strcmp(protocol, "http") == 0 || strcmp(protocol, "https") == 0;
}

// Function to check if a domain is valid
bool is_valid_domain(char *domain) {
    // Check if the domain is not empty
    if (strcmp(domain, "") == 0) {
        return false;
    }

    // Check if the domain contains only alphanumeric characters and dots
    for (int i = 0; i < strlen(domain); i++) {
        if (!isalnum(domain[i]) && domain[i] != '.') {
            return false;
        }
    }

    // Return true if the domain is valid
    return true;
}

// Function to check if a port is valid
bool is_valid_port(char *port) {
    // Check if the port is not empty
    if (strcmp(port, "") == 0) {
        return false;
    }

    // Check if the port is a valid number
    for (int i = 0; i < strlen(port); i++) {
        if (!isdigit(port[i])) {
            return false;
        }
    }

    // Return true if the port is valid
    return true;
}

// Function to check if a path is valid
bool is_valid_path(char *path) {
    // Check if the path is not empty
    if (strcmp(path, "") == 0) {
        return false;
    }

    // Check if the path contains only alphanumeric characters, dots, slashes, and underscores
    for (int i = 0; i < strlen(path); i++) {
        if (!isalnum(path[i]) && path[i] != '.' && path[i] != '/' && path[i] != '_') {
            return false;
        }
    }

    // Return true if the path is valid
    return true;
}