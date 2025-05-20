//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 32 // Maximum password length

// Function to generate a random password
char* generate_password(int length) {
    char* password = malloc(length + 1); // Allocate memory for password + 1 for null terminator
    if (password == NULL) {
        printf("Error: Failed to allocate memory.\n");
        exit(EXIT_FAILURE);
    }

    // Generate random password
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        password[i] = rand() % 62 + 'a'; // 62 characters (a-z, A-Z, 0-9)
    }
    password[length] = '\0'; // Add null terminator

    return password;
}

// Function to check if password is strong
int is_strong_password(char* password) {
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

    if (has_uppercase && has_lowercase && has_number && has_special) {
        return 1; // Password is strong
    } else {
        return 0; // Password is weak
    }
}

int main() {
    int length;
    char* password;

    // Get password length from user
    printf("Enter password length (1-32): ");
    scanf("%d", &length);

    // Generate random password
    password = generate_password(length);
    printf("Generated password: %s\n", password);

    // Check if password is strong
    if (is_strong_password(password)) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }

    // Free memory allocated for password
    free(password);

    return 0;
}