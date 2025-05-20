//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: unmistakable
#include <stdio.h>
#include <string.h>

#define MAX_ATTEMPTS 3
#define MAX_PASSWORD_ATTEMPTS 10

void check_login_attempts(char *username)
{
    int attempts = 0;
    char password[20];

    while (attempts < MAX_ATTEMPTS) {
        printf("Enter your password: ");
        scanf("%s", password);

        if (strcmp(password, "password123") == 0) {
            printf("Login successful!\n");
            break;
        } else {
            printf("Incorrect password. Please try again.\n");
            attempts++;
        }
    }

    if (attempts == MAX_ATTEMPTS) {
        printf("Maximum login attempts reached! Your account has been locked.\n");
    }
}

void main()
{
    int password_attempts = 0;

    while (1) {
        char username[20];
        printf("Enter your username: ");
        scanf("%s", username);

        if (strcmp(username, "admin") == 0) {
            printf("Welcome, admin!\n");
            check_login_attempts(username);
            break;
        } else {
            printf("Invalid username. Please try again.\n");
        }

        password_attempts++;

        if (password_attempts == MAX_PASSWORD_ATTEMPTS) {
            printf("Exceeded maximum password attempts. Account locked.\n");
            break;
        }
    }
}