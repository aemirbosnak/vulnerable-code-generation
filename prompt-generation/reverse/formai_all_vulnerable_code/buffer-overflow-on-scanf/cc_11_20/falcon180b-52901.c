//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: distributed
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 100

int main() {
    char password[MAX_LENGTH];
    int length, i;
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_-+={}[];:,.<>?/|~";
    int charset_length = strlen(charset);
    int complexity = 0;
    int has_uppercase = 0, has_lowercase = 0, has_number = 0, has_special = 0;

    // Initialize random seed
    srand(time(NULL));

    // Get password length from user
    printf("Enter password length (max %d): ", MAX_LENGTH);
    scanf("%d", &length);

    // Generate password
    for (i = 0; i < length; i++) {
        password[i] = charset[rand() % charset_length];
    }

    // Check password complexity
    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
        }
        else if (islower(password[i])) {
            has_lowercase = 1;
        }
        else if (isdigit(password[i])) {
            has_number = 1;
        }
        else {
            has_special = 1;
        }
    }

    // Determine password strength
    if (length < 8) {
        printf("Weak\n");
    }
    else if (length >= 8 && length < 12) {
        printf("Moderate\n");
    }
    else if (length >= 12 && (has_uppercase && has_lowercase && has_number)) {
        printf("Strong\n");
    }
    else if (length >= 12 && (has_uppercase && has_lowercase && has_number && has_special)) {
        printf("Very Strong\n");
    }
    else {
        printf("Very Weak\n");
    }

    return 0;
}