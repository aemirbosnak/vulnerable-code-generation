//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100

/* Function to check if password contains at least one uppercase letter */
int has_uppercase(char *password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            return 1;
        }
    }
    return 0;
}

/* Function to check if password contains at least one lowercase letter */
int has_lowercase(char *password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            return 1;
        }
    }
    return 0;
}

/* Function to check if password contains at least one digit */
int has_digit(char *password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            return 1;
        }
    }
    return 0;
}

/* Function to check if password contains at least one special character */
int has_special_char(char *password) {
    char special_chars[] = "!@#$%^&*()_+";
    int i, j;
    for (i = 0; i < strlen(password); i++) {
        for (j = 0; j < strlen(special_chars); j++) {
            if (password[i] == special_chars[j]) {
                return 1;
            }
        }
    }
    return 0;
}

/* Function to check password strength */
int check_password_strength(char *password) {
    int strength = 0;
    if (has_uppercase(password)) {
        strength++;
    }
    if (has_lowercase(password)) {
        strength++;
    }
    if (has_digit(password)) {
        strength++;
    }
    if (has_special_char(password)) {
        strength++;
    }
    return strength;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int strength;

    printf("Enter password: ");
    scanf("%s", password);

    strength = check_password_strength(password);

    if (strength == 0) {
        printf("Password is very weak\n");
    } else if (strength == 1) {
        printf("Password is weak\n");
    } else if (strength == 2) {
        printf("Password is moderate\n");
    } else if (strength == 3) {
        printf("Password is strong\n");
    } else if (strength == 4) {
        printf("Password is very strong\n");
    }

    return 0;
}