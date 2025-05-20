//Falcon2-11B DATASET v1.0 Category: User Input Sanitizer ; Style: ephemeral
#include <stdio.h>
#include <string.h>

// Function to check if the input is a valid email address and sanitizes it
void sanitizeEmail(char* email) {
    // Check if the input is a valid email address
    if (strlen(email) > 0 && strstr(email, "@")!= NULL) {
        // Remove any special characters from the email address
        char sanitizedEmail[strlen(email) + 1];
        strcpy(sanitizedEmail, email);
        int index = 0;
        while (index < strlen(sanitizedEmail)) {
            if (!isalnum(sanitizedEmail[index])) {
                sanitizedEmail[index] = '_';
            }
            index++;
        }
        printf("Sanitized Email: %s\n", sanitizedEmail);
    } else {
        printf("Invalid email address\n");
    }
}

// Function to check if the input is a valid phone number and sanitizes it
void sanitizePhone(char* phone) {
    // Check if the input is a valid phone number
    if (strlen(phone) > 0 && strstr(phone, "-")!= NULL) {
        // Remove any special characters from the phone number
        char sanitizedPhone[strlen(phone) + 1];
        strcpy(sanitizedPhone, phone);
        int index = 0;
        while (index < strlen(sanitizedPhone)) {
            if (!isdigit(sanitizedPhone[index])) {
                sanitizedPhone[index] = '_';
            }
            index++;
        }
        printf("Sanitized Phone: %s\n", sanitizedPhone);
    } else {
        printf("Invalid phone number\n");
    }
}

// Function to check if the input is a valid URL and sanitizes it
void sanitizeURL(char* url) {
    // Check if the input is a valid URL
    if (strlen(url) > 0 && strstr(url, "://")!= NULL) {
        // Remove any special characters from the URL
        char sanitizedURL[strlen(url) + 1];
        strcpy(sanitizedURL, url);
        int index = 0;
        while (index < strlen(sanitizedURL)) {
            if (!isalnum(sanitizedURL[index])) {
                sanitizedURL[index] = '_';
            }
            index++;
        }
        printf("Sanitized URL: %s\n", sanitizedURL);
    } else {
        printf("Invalid URL\n");
    }
}

int main() {
    char input[100];
    printf("Enter your input: ");
    scanf("%s", input);

    // Check if the input is a valid email address and sanitize it
    sanitizeEmail(input);

    // Check if the input is a valid phone number and sanitize it
    sanitizePhone(input);

    // Check if the input is a valid URL and sanitize it
    sanitizeURL(input);

    return 0;
}