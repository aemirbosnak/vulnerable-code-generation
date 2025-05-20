//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ATTEMPTS 3

int login_attempts;

// Function to validate user credentials
int validate_login() {
    char username[20], password[20];
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    // Check if the credentials are correct
    if (strcmp(username, "admin") == 0 && strcmp(password, "password") == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Function to log failed login attempts
void log_attempt() {
    login_attempts++;
    printf("Invalid username or password! (%d/%d)\n", login_attempts, MAX_ATTEMPTS);
}

// Function to detect intrusion attempts
void detect_intrusion() {
    if (login_attempts >= MAX_ATTEMPTS) {
        printf("INTRUSION DETECTED! ABORTING...\n");
        exit(1);
    }
}

int main() {
    // Initialize login attempts
    login_attempts = 0;
    printf("Welcome to the secure system!\n");

    // Loop until user successfully logs in or intrudes
    while (1) {
        if (validate_login()) {
            printf("Login successful!\n");
            break;
        } else {
            log_attempt();
            detect_intrusion();
        }
    }

    // Do some secure stuff here...

    return 0;
}