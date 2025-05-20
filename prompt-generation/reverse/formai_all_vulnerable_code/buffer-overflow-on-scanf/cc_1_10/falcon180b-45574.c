//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN_PASSWORD_LENGTH 8

// Function to check password strength
int check_password_strength(char *password) {
    int length = strlen(password);
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_digit = 0;
    int has_special_char = 0;

    if (length < MIN_PASSWORD_LENGTH) {
        return 0;
    }

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
        } else if (islower(password[i])) {
            has_lowercase = 1;
        } else if (isdigit(password[i])) {
            has_digit = 1;
        } else {
            has_special_char = 1;
        }
    }

    int total_strength = 0;

    if (has_uppercase) {
        total_strength += 1;
    }

    if (has_lowercase) {
        total_strength += 1;
    }

    if (has_digit) {
        total_strength += 1;
    }

    if (has_special_char) {
        total_strength += 1;
    }

    return total_strength;
}

int main() {
    char password[100];
    int strength;

    printf("Enter your password: ");
    scanf("%s", password);

    strength = check_password_strength(password);

    switch (strength) {
        case 0:
            printf("Password is too short.\n");
            break;
        case 1:
            printf("Password is weak.\n");
            break;
        case 2:
            printf("Password is moderate.\n");
            break;
        case 3:
            printf("Password is strong.\n");
            break;
        case 4:
            printf("Password is very strong.\n");
            break;
    }

    return 0;
}