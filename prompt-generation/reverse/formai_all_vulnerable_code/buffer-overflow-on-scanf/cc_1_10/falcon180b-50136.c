//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Function to check if password contains at least one digit
bool has_digit(char *password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            return true;
        }
    }
    return false;
}

// Function to check if password contains both uppercase and lowercase letters
bool has_both_case(char *password) {
    int i;
    bool has_upper = false;
    bool has_lower = false;
    for (i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            has_upper = true;
        } else if (islower(password[i])) {
            has_lower = true;
        }
    }
    return (has_upper && has_lower);
}

// Function to check if password contains at least one special character
bool has_special_char(char *password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (!isalnum(password[i])) {
            return true;
        }
    }
    return false;
}

// Function to check password strength
void check_password_strength(char *password) {
    int length = strlen(password);
    if (length < 8) {
        printf("Password is too short.\n");
    } else if (!has_digit(password)) {
        printf("Password must contain at least one digit.\n");
    } else if (!has_both_case(password)) {
        printf("Password must contain both uppercase and lowercase letters.\n");
    } else if (!has_special_char(password)) {
        printf("Password must contain at least one special character.\n");
    } else {
        printf("Password is strong.\n");
    }
}

int main() {
    char password[50];
    printf("Enter password: ");
    scanf("%s", password);
    check_password_strength(password);
    return 0;
}