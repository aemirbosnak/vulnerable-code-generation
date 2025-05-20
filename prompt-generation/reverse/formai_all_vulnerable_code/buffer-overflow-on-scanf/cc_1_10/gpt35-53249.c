//FormAI DATASET v1.0 Category: Browser Plugin ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

// Function prototypes
char* to_lowercase(char *str);
int is_valid_url(char *url);

// Main function
int main() {
    char url[MAX_LENGTH];
    char *formatted_url;

    printf("Enter URL: ");
    scanf("%s", url);

    if (is_valid_url(url)) {
        formatted_url = to_lowercase(url);
        printf("Formatted URL: %s\n", formatted_url);
        // Call browser plugin API to open the URL in C Browser
    } else {
        printf("Error: Invalid URL\n");
    }

    return 0;
}

// Function to convert string to lowercase
char* to_lowercase(char *str) {
    char *result = malloc(strlen(str) + 1);
    int i;

    for (i = 0; str[i]; i++) {
        result[i] = tolower(str[i]);
    }

    result[i] = '\0';

    return result;
}

// Function to validate URL
int is_valid_url(char *url) {
    if (strlen(url) < 8) {
        return 0;
    }

    if (strncmp(url, "https://", 8) != 0 && strncmp(url, "http://", 7) != 0) {
        return 0;
    }

    return 1;
}