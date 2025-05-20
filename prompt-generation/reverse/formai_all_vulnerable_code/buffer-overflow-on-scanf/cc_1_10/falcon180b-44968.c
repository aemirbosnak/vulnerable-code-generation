//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 16

// Function to generate a random password of specified length
char *generate_password(int length) {
    char *password = malloc(length + 1);
    if (password == NULL) {
        printf("Error: Unable to allocate memory for password.\n");
        exit(1);
    }

    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>?";
    const int charset_length = strlen(charset);

    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % charset_length];
    }

    password[length] = '\0';

    return password;
}

// Function to check if password is strong enough
int is_strong_password(const char *password) {
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;
    int has_special = 0;

    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
        } else if (islower(password[i])) {
            has_lowercase = 1;
        } else if (isdigit(password[i])) {
            has_number = 1;
        } else {
            has_special = 1;
        }
    }

    return (has_uppercase && has_lowercase && has_number && has_special);
}

// Function to prompt user for desired password length
int prompt_password_length() {
    int length = 0;
    while (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Enter desired password length (between %d and %d): ", MIN_LENGTH, MAX_LENGTH);
        scanf("%d", &length);
    }

    return length;
}

int main() {
    srand(time(NULL));

    // Prompt user for desired password length
    int length = prompt_password_length();

    // Generate password
    char *password = generate_password(length);

    // Check if password is strong enough
    int is_strong = is_strong_password(password);

    printf("Generated password: %s\n", password);
    if (is_strong) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }

    free(password);

    return 0;
}