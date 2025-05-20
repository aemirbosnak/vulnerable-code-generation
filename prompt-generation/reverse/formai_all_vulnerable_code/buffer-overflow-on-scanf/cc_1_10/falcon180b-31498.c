//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: irregular
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 100

// Function to check password strength
int check_password_strength(char *password) {
    int upper_case_count = 0;
    int lower_case_count = 0;
    int number_count = 0;
    int special_char_count = 0;
    int length = strlen(password);

    // Check for upper case letters
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            upper_case_count++;
        }
    }

    // Check for lower case letters
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            lower_case_count++;
        }
    }

    // Check for numbers
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            number_count++;
        }
    }

    // Check for special characters
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            special_char_count++;
        }
    }

    // Calculate password strength
    int strength = 0;
    if (upper_case_count > 0) {
        strength++;
    }
    if (lower_case_count > 0) {
        strength++;
    }
    if (number_count > 0) {
        strength++;
    }
    if (special_char_count > 0) {
        strength++;
    }
    if (length >= 8) {
        strength++;
    }

    return strength;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];

    // Get password from user
    printf("Enter password: ");
    scanf("%s", password);

    // Check password strength
    int strength = check_password_strength(password);

    // Print password strength
    if (strength <= 0) {
        printf("Weak password\n");
    } else if (strength <= 2) {
        printf("Medium password\n");
    } else {
        printf("Strong password\n");
    }

    return 0;
}