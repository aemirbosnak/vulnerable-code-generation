//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: curious
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 100
#define MIN_PASSWORD_LENGTH 8

/* Function to check if the password contains at least one uppercase letter */
int contains_uppercase(char *password) {
    int i = 0;
    while (i < strlen(password)) {
        if (isupper(password[i])) {
            return 1;
        }
        i++;
    }
    return 0;
}

/* Function to check if the password contains at least one lowercase letter */
int contains_lowercase(char *password) {
    int i = 0;
    while (i < strlen(password)) {
        if (islower(password[i])) {
            return 1;
        }
        i++;
    }
    return 0;
}

/* Function to check if the password contains at least one digit */
int contains_digit(char *password) {
    int i = 0;
    while (i < strlen(password)) {
        if (isdigit(password[i])) {
            return 1;
        }
        i++;
    }
    return 0;
}

/* Function to check if the password contains at least one special character */
int contains_specialchar(char *password) {
    int i = 0;
    while (i < strlen(password)) {
        if (!isalnum(password[i])) {
            return 1;
        }
        i++;
    }
    return 0;
}

/* Function to check the strength of the password */
int check_password_strength(char *password) {
    int length = strlen(password);
    int uppercase = contains_uppercase(password);
    int lowercase = contains_lowercase(password);
    int digit = contains_digit(password);
    int specialchar = contains_specialchar(password);

    int strength = 0;

    if (length >= MIN_PASSWORD_LENGTH) {
        strength++;
    }

    if (uppercase) {
        strength++;
    }

    if (lowercase) {
        strength++;
    }

    if (digit) {
        strength++;
    }

    if (specialchar) {
        strength++;
    }

    return strength;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter your password: ");
    scanf("%s", password);

    int strength = check_password_strength(password);

    if (strength == 0) {
        printf("Weak password\n");
    } else if (strength == 1) {
        printf("Moderate password\n");
    } else if (strength == 2) {
        printf("Strong password\n");
    } else if (strength == 3) {
        printf("Very strong password\n");
    } else {
        printf("Invalid password\n");
    }

    return 0;
}