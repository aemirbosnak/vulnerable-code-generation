//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 2048
#define ESCAPE_CHARS "!*'();:@&=+$,/?#[]"

#define is_unreserved(c) (isalnum(c) || strchr("-._~", c))
#define is_reserved(c) (strchr(ESCAPE_CHARS, c))
#define is_percent_encoded(s) (strncmp(s, "%", 1) == 0 && strlen(s) == 3)

void sanitize_url(const char *url, char *sanitized_url);
void url_encode(const char *str, char *encoded_str);
void append_encoded_char(char *encoded_str, char c);
void process_segment(char *segment, char *result);

int main() {
    char url[MAX_LEN];
    char sanitized_url[MAX_LEN];

    printf("Enter a URL to sanitize:\n");
    if (fgets(url, MAX_LEN, stdin) == NULL) {
        fprintf(stderr, "Error reading URL.\n");
        return 1;
    }
    
    url[strcspn(url, "\n")] = 0; // Remove newline character
    sanitize_url(url, sanitized_url);
    
    printf("Sanitized URL:\n%s\n", sanitized_url);

    return 0;
}

void sanitize_url(const char *url, char *sanitized_url) {
    char *token;
    char temp_url[MAX_LEN];
    strcpy(temp_url, url);
    
    // Tokenize the URL on the basis of slashes
    token = strtok(temp_url, "/");
    char result[MAX_LEN] = "";
    
    while (token != NULL) {
        process_segment(token, result);
        strcat(result, "/");
        token = strtok(NULL, "/");
    }
    result[strlen(result) - 1] = '\0'; // Remove trailing slash
    strcpy(sanitized_url, result);
}

void process_segment(char *segment, char *result) {
    char encoded_str[MAX_LEN] = "";
    url_encode(segment, encoded_str);
    strcat(result, encoded_str);
}

void url_encode(const char *str, char *encoded_str) {
    while (*str) {
        if (is_unreserved(*str)) {
            strncat(encoded_str, str, 1);
        } else if (is_reserved(*str)) {
            append_encoded_char(encoded_str, *str);
        } else {
            append_encoded_char(encoded_str, *str);
        }
        str++;
    }
}

void append_encoded_char(char *encoded_str, char c) {
    char buffer[4]; // %XX format
    sprintf(buffer, "%%%02X", (unsigned char)c);
    strcat(encoded_str, buffer);
}