//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to remove unwanted characters from URL
void sanitizeURL(char url[], char sanitized_url[]) {
    // Initialize the sanitized URL as empty string
    strcpy(sanitized_url, "");

    int length = strlen(url);
    int dot_count = 0;
    char last_char = '\0';

    // Loop through each character in the original URL
    for(int i = 0; i < length; i++) {
        char current_char = url[i];

        // Convert uppercase characters to lowercase
        if(isupper(current_char)) {
            current_char = tolower(current_char);
        }

        // Remove any whitespace characters
        if(isspace(current_char)) {
            continue;
        }

        // Remove any characters that are not a letter, a number, a hyphen or a dot
        if(!isalnum(current_char) && current_char != '-' && current_char != '.') {
            continue;
        }

        // Remove any dots that are not part of a valid domain name
        if(current_char == '.') {
            dot_count++;
            if((i == 0) || (i == length - 1) || last_char == '.' || dot_count > 1) {
                continue;
            }
        }

        // Append the sanitized character to the sanitized URL
        int sanit_len = strlen(sanitized_url);
        sanitized_url[sanit_len] = current_char;
        sanitized_url[sanit_len + 1] = '\0';

        last_char = current_char;
    }
}

int main() {
    char url[100], sanitized_url[100];

    printf("Enter the URL to sanitize: ");
    scanf("%s", url);

    sanitizeURL(url, sanitized_url);

    printf("Sanitized URL: %s\n", sanitized_url);

    return 0;
}