//FormAI DATASET v1.0 Category: Password management ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 25

int main()
{
    printf("Welcome to the Password Management System!\n");
    printf("Let's start by creating a new user account.\n");

    char username[50];
    char password[MAX_PASSWORD_LENGTH];
    char confirm_password[MAX_PASSWORD_LENGTH];

    printf("Enter your desired username:\n");
    scanf("%s", username);

    printf("Enter your desired password (up to %d characters):\n", MAX_PASSWORD_LENGTH);
    scanf("%s", password);

    printf("Confirm your password:\n");
    scanf("%s", confirm_password);

    int password_matches = strcmp(password, confirm_password) == 0;

    if (!password_matches) {
        printf("Passwords do not match. Please try again.\n");
        return 1; // Error exit code
    }

    printf("User account created successfully!\n");

    // Clear the passwords from memory
    memset(password, 0, MAX_PASSWORD_LENGTH);
    memset(confirm_password, 0, MAX_PASSWORD_LENGTH);

    printf("Please enter your login details:\n");

    char login_username[50];
    char login_password[MAX_PASSWORD_LENGTH];

    printf("Username:\n");
    scanf("%s", login_username);

    printf("Password:\n");
    scanf("%s", login_password);

    int login_matches = strcmp(login_username, username) == 0 && strcmp(login_password, password) == 0;

    if (!login_matches) {
        printf("Login failed. Please try again.\n");
        return 1; // Error exit code
    }

    printf("Login successful! Welcome back, %s.\n", username);

    return 0; // Normal exit code
}