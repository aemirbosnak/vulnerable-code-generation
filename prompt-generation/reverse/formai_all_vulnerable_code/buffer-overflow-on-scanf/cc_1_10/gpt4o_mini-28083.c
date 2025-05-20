//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

void sanitize_url(const char *url, char *sanitized_url) {
    const char *reserved_chars = "!*;:'()@&=+$,/?#[]";
    int j = 0;

    for (int i = 0; url[i] != '\0' && j < MAX_URL_LENGTH - 1; i++) {
        char ch = url[i];

        // Check if character is safe or not
        if (isalnum(ch) || strchr(reserved_chars, ch)) {
            sanitized_url[j++] = ch;
        } else {
            // Encode unsafe characters
            snprintf(sanitized_url + j, 4, "%%%02X", (unsigned char)ch);
            j += 3; // Increment by 3 for encoded character
        }
    }
    sanitized_url[j] = '\0'; // Null-terminate the sanitized URL
}

void display_menu() {
    printf("----------------------------------\n");
    printf("          URL Sanitizer          \n");
    printf("----------------------------------\n");
    printf("1. Enter a URL to sanitize        \n");
    printf("2. Exit                           \n");
    printf("----------------------------------\n");
}

int main() {
    char url[MAX_URL_LENGTH];
    char sanitized_url[MAX_URL_LENGTH];
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue; // Restart the loop
        }

        switch (choice) {
            case 1:
                printf("Enter URL to sanitize: ");
                while (getchar() != '\n'); // Clear the buffer before taking string input
                fgets(url, sizeof(url), stdin);
                
                // Remove newline character from fgets input
                url[strcspn(url, "\n")] = '\0'; 

                if (strlen(url) == 0) {
                    printf("No URL provided!\n");
                    break;
                }

                // Sanitize the URL
                sanitize_url(url, sanitized_url);
                printf("Sanitized URL: %s\n", sanitized_url);
                break;

            case 2:
                printf("Exiting...\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please select 1 or 2.\n");
                break;
        }
    }

    return 0;
}