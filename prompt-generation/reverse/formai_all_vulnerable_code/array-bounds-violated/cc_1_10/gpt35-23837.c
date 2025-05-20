//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Claude Shannon
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
bool is_valid_char(char c);
bool is_hex_char(char c);
bool is_valid_url_char(char c);
void url_sanitize(char *url);

// Main function
int main() {
    char url[256]; // buffer for URL
    
    // Read in URL
    printf("Enter a URL to sanitize: ");
    fgets(url, 256, stdin);
    
    // Remove trailing newline character
    if (url[strlen(url) - 1] == '\n') {
        url[strlen(url) - 1] = '\0';
    }
    
    // Sanitize URL
    url_sanitize(url);
    
    // Display sanitized URL
    printf("Sanitized URL: %s\n", url);
    
    return 0;
}

// Function to determine if a character is valid
bool is_valid_char(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
        return true;
    }
    if (c == '-' || c == '_' || c == '.' || c == '~') {
        return true;
    }
    return false;
}

// Function to determine if a character is a valid hexadecimal character
bool is_hex_char(char c) {
    if ((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F') || (c >= '0' && c <= '9')) {
        return true;
    }
    return false;
}

// Function to determine if a character is a valid URL character
bool is_valid_url_char(char c) {
    if (is_valid_char(c) || c == '%' || c == '/') {
        return true;
    }
    return false;
}

// Function to sanitize a URL based on common security vulnerabilities
void url_sanitize(char *url) {
    int len = strlen(url);
    char *clean_url = (char*) malloc(len + 1); // allocate memory for clean URL
    int i = 0; // index of clean URL
    int j; // index of original URL
    
    // Copy over valid characters from original URL to clean URL
    for (j = 0; j < len; j++) {
        if (is_valid_url_char(url[j])) {
            clean_url[i] = url[j];
            i++;
        }
        // Replace any characters that are not valid with "%XX" format
        else {
            char temp[4];
            sprintf(temp, "%%%02X", url[j]);
            strcat(clean_url, temp);
            i += 3;
        }
    }
    clean_url[i] = '\0'; // terminate clean URL string
    
    memcpy(url, clean_url, strlen(clean_url) + 1); // copy clean URL over original URL
    
    free(clean_url); // free memory
}