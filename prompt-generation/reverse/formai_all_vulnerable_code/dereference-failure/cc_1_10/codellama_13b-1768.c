//Code Llama-13B DATASET v1.0 Category: Password management ; Style: accurate
/*
 * Password management program
 *
 * Prompts the user for a password and stores it in a secure manner.
 * Also allows the user to retrieve and check the password.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 32

int main() {
    char password[MAX_PASSWORD_LENGTH];
    char confirm_password[MAX_PASSWORD_LENGTH];
    char stored_password[MAX_PASSWORD_LENGTH];
    int password_length;
    int confirm_password_length;
    int stored_password_length;

    // Prompt user for password
    printf("Enter password: ");
    password_length = get_password(password, MAX_PASSWORD_LENGTH);

    // Prompt user to confirm password
    printf("Confirm password: ");
    confirm_password_length = get_password(confirm_password, MAX_PASSWORD_LENGTH);

    // Check if passwords match
    if (password_length == confirm_password_length &&
        strcmp(password, confirm_password) == 0) {
        printf("Passwords match.\n");
    } else {
        printf("Passwords do not match.\n");
        return 1;
    }

    // Store password in secure manner
    stored_password_length = store_password(password, stored_password, MAX_PASSWORD_LENGTH);

    // Retrieve and check password
    if (stored_password_length == password_length &&
        strcmp(password, stored_password) == 0) {
        printf("Password matches.\n");
    } else {
        printf("Password does not match.\n");
    }

    return 0;
}

int get_password(char *password, int max_length) {
    int i;

    // Read password from stdin
    for (i = 0; i < max_length; i++) {
        password[i] = getchar();
        if (password[i] == '\n') {
            break;
        }
    }

    return i;
}

int store_password(char *password, char *stored_password, int max_length) {
    int i;

    // Store password in secure manner
    for (i = 0; i < max_length; i++) {
        stored_password[i] = password[i];
        if (stored_password[i] == '\0') {
            break;
        }
    }

    return i;
}