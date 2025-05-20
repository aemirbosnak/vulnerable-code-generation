//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random password
void generate_password(char *password, int length) {
    const char alphanum[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int i;

    for (i = 0; i < length; i++) {
        password[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    password[length] = '\0';
}

// Function to check if a password is strong
int is_strong_password(char *password) {
    int length = strlen(password);
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_digit = 0;

    if (length < 8) {
        return 0;
    }

    while (*password) {
        if (*password >= 'A' && *password <= 'Z') {
            has_uppercase = 1;
        } else if (*password >= 'a' && *password <= 'z') {
            has_lowercase = 1;
        } else if (*password >= '0' && *password <= '9') {
            has_digit = 1;
        }

        password++;
    }

    if (has_uppercase && has_lowercase && has_digit) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char password[32];
    int length;
    int strength;

    srand(time(NULL));

    // Get password length from user
    printf("Enter password length (8-32): ");
    scanf("%d", &length);

    // Check if password length is valid
    if (length < 8 || length > 32) {
        printf("Invalid password length.\n");
        return 1;
    }

    // Generate password
    generate_password(password, length);

    // Check password strength
    strength = is_strong_password(password);

    if (strength) {
        printf("Generated password: %s\n", password);
    } else {
        printf("Password is not strong enough.\n");
    }

    return 0;
}