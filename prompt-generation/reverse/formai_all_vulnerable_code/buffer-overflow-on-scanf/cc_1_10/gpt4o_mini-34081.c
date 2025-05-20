//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

void strip_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int is_valid_character(char c) {
    return (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~' || c == ':' ||
            c == '/' || c == '?' || c == '#' || c == '[' || c == ']' || c == '@' ||
            c == '!' || c == '$' || c == '&' || c == '\'' || c == '(' || c == ')' ||
            c == '*' || c == '+' || c == ',' || c == ';' || c == '=');
}

char *sanitize_url(const char *url) {
    size_t len = strlen(url);
    char *sanitized_url = (char *)malloc(MAX_URL_LENGTH);
    
    if (!sanitized_url) {
        perror("Unable to allocate memory for sanitized URL");
        exit(EXIT_FAILURE);
    }

    size_t sanitized_index = 0;
    for (size_t i = 0; i < len && sanitized_index < MAX_URL_LENGTH - 1; i++) {
        if (is_valid_character(url[i])) {
            sanitized_url[sanitized_index++] = url[i];
        } else {
            snprintf(sanitized_url + sanitized_index, MAX_URL_LENGTH - sanitized_index, "%%%02X", (unsigned char)url[i]);
            sanitized_index += 3; // Each encoded character is 3 characters
        }
    }
    sanitized_url[sanitized_index] = '\0';
    
    return sanitized_url;
}

void display_menu() {
    printf("\nURL Sanitizer\n");
    printf("1. Sanitize a URL\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

int main() {
    char input_url[MAX_URL_LENGTH];
    char *sanitized_url;
    int option;

    while (1) {
        display_menu();
        
        if (scanf("%d", &option) != 1) {
            fprintf(stderr, "Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); // Clear invalid input
            continue;
        }

        switch (option) {
            case 1:
                printf("Enter the URL to sanitize: ");
                getchar(); // Clear newline left in buffer after scanf
                fgets(input_url, MAX_URL_LENGTH, stdin);
                strip_newline(input_url);
                sanitized_url = sanitize_url(input_url);
                printf("Sanitized URL: %s\n", sanitized_url);
                free(sanitized_url);
                break;
            case 2:
                printf("Exiting...\n");
                return 0;
            default:
                fprintf(stderr, "Invalid option. Please choose 1 or 2.\n");
        }
    }
    
    return 0;
}