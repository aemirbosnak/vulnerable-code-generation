//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

char* sanitize_url(char* url);

int main() {
    char url[MAX_URL_LENGTH] = "https://www.example.com/path/to/page?query=string&param=value#fragment";
    char* sanitized_url = sanitize_url(url);
    
    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized_url);
    
    return 0;
}

char* sanitize_url(char* url) {
    char* sanitized_url = malloc(MAX_URL_LENGTH);
    int i = 0;
    int j = 0;
    char* current_char;
    
    while (url[i]!= '\0') {
        current_char = url[i];
        if (isalnum(current_char)) {
            // if the character is alphanumeric, add it to the sanitized URL
            sanitized_url[j] = current_char;
            j++;
        } else if (current_char == '/') {
            // if the character is a forward slash, add it to the sanitized URL
            sanitized_url[j] = current_char;
            j++;
        } else if (current_char == '?') {
            // if the character is a question mark, add it to the sanitized URL
            sanitized_url[j] = current_char;
            j++;
        } else if (current_char == '#') {
            // if the character is a hash symbol, add it to the sanitized URL
            sanitized_url[j] = current_char;
            j++;
        }
        i++;
    }
    sanitized_url[j] = '\0'; // add null terminator to the end of the sanitized URL
    
    return sanitized_url;
}