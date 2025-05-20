//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: ephemeral
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define PASSWORD_LENGTH 8 // minimum password length

// function to check password strength
int check_password_strength(char *password) {
    int length = strlen(password);
    if (length < PASSWORD_LENGTH) {
        printf("Password is too short.\n");
        return 0;
    }
    int has_uppercase = 0, has_lowercase = 0, has_digit = 0, has_special_char = 0;
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
    if (!has_uppercase) {
        printf("Password must contain at least one uppercase letter.\n");
        return 0;
    }
    if (!has_lowercase) {
        printf("Password must contain at least one lowercase letter.\n");
        return 0;
    }
    if (!has_digit) {
        printf("Password must contain at least one digit.\n");
        return 0;
    }
    if (!has_special_char) {
        printf("Password must contain at least one special character.\n");
        return 0;
    }
    printf("Password is strong.\n");
    return 1;
}

int main() {
    char password[100];
    printf("Enter your password: ");
    scanf("%s", password);
    if (check_password_strength(password)) {
        printf("Your password is strong.\n");
    }
    return 0;
}