//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define BUFFER_SIZE 1000

// function to check if a character is an alphanumeric or not
bool is_alphanumeric(char c) {
    return isalnum(c);
}

// function to check if a character is a special character or not
bool is_special_character(char c) {
    return !is_alphanumeric(c) && !isspace(c);
}

// function to sanitize the url by removing special characters and converting it to lowercase
char* sanitize_url(char* url) {
    char* sanitized_url = (char*)malloc(sizeof(char) * BUFFER_SIZE);
    
    if (sanitized_url == NULL) {
        printf("Error allocating memory\n");
        exit(EXIT_FAILURE);
    }
    
    int i = 0, j = 0;
    
    while (url[i] != '\0') {
        if (is_special_character(url[i])) {
            i++;
            continue;
        }
        sanitized_url[j++] = tolower(url[i++]);
    }
    
    // add null character to the end of the sanitized string
    sanitized_url[j] = '\0';
    
    return sanitized_url;
}

int main() {
    char url[BUFFER_SIZE];
    printf("Enter a URL: ");
    fgets(url, BUFFER_SIZE, stdin);
    
    // remove trailing newline character from input
    if (url[strlen(url) - 1] == '\n')
        url[strlen(url) - 1] = '\0';
    
    char* sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s\n", sanitized_url);
    
    // free dynamically allocated memory
    free(sanitized_url);
    
    return 0;
}