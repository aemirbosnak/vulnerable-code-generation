//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ATTEMPTS 3 // maximum login attempts allowed

// function to check if the login credentials are valid
int is_valid_login(char *username, char *password) {
    // This is just a sample program, so we're hardcoding a valid set of credentials.
    // In a real program, you would retrieve valid credentials from a database or other source.
    char *valid_username = "happybot";
    char *valid_password = "happypass";

    if (strcmp(username, valid_username) == 0 && strcmp(password, valid_password) == 0) {
        return 1; // credentials are valid
    } else {
        return 0; // invalid credentials
    }
}

// function to log login attempts
void log_attempt(char *username, char *ip_address, int success) {
    // This is just a sample program, so we're not actually logging anything.
    // In a real program, you would log login attempts to a file or database for future analysis.
    if (success) {
        printf("Login success: %s from IP %s\n", username, ip_address);
    } else {
        printf("Login failed: %s from IP %s\n", username, ip_address);
    }
}

int main() {
    char username[50];
    char password[50];
    char ip_address[20];

    int attempts = 0;
    int logged_in = 0;

    while (!logged_in && attempts < MAX_ATTEMPTS) {
        printf("Please enter your username: ");
        scanf("%s", username);

        printf("Please enter your password: ");
        scanf("%s", password);

        printf("Please enter your IP address: ");
        scanf("%s", ip_address);

        if (is_valid_login(username, password)) {
            logged_in = 1;
            printf("\nWelcome %s!\n", username);
        } else {
            attempts++;
            printf("\nInvalid login credentials. Please try again.\n");

            if (attempts == MAX_ATTEMPTS) {
                printf("\nToo many invalid login attempts. Your account has been locked.\n");
            }
        }

        log_attempt(username, ip_address, logged_in);
    }

    return 0;
}