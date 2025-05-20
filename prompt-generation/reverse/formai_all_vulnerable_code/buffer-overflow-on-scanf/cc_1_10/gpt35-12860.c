//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: cheerful
// Intrusion Detection System in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_ATTEMPTS 3
#define MAX_USERNAME 15
#define MAX_PASSWORD 15

// Functions
void clear_input_buffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int is_attempt_successful(char* username, char* password) {
    // Compare username and password
    if (strcmp(username, "admin") == 0 && strcmp(password, "pass123") == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int login_attempts = 0;
    char username[MAX_USERNAME], password[MAX_PASSWORD];

    while (login_attempts < MAX_ATTEMPTS) {
        // Get username and password
        printf("Enter your username: ");
        scanf("%s", username);
        clear_input_buffer();
        printf("Enter your password: ");
        scanf("%s", password);
        clear_input_buffer();

        // Check if the attempt was successful
        if (is_attempt_successful(username, password)) {
            printf("Login successful!\n");
            return 0;
        } else {
            printf("Incorrect username or password. Please try again.\n");
            login_attempts++;
        }
    }

    // Too many failed attempts
    printf("Too many failed attempts. Exiting...\n");
    return 1;
}