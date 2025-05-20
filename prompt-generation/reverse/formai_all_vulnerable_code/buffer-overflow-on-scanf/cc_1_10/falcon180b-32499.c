//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_PASS_LEN 64

// Function to count the number of digits in a string
int count_digits(char *str) {
    int count = 0;
    while (*str) {
        if (isdigit(*str)) {
            count++;
        }
        str++;
    }
    return count;
}

// Function to count the number of uppercase letters in a string
int count_uppercase(char *str) {
    int count = 0;
    while (*str) {
        if (isupper(*str)) {
            count++;
        }
        str++;
    }
    return count;
}

// Function to count the number of lowercase letters in a string
int count_lowercase(char *str) {
    int count = 0;
    while (*str) {
        if (islower(*str)) {
            count++;
        }
        str++;
    }
    return count;
}

// Function to count the number of special characters in a string
int count_special(char *str) {
    int count = 0;
    while (*str) {
        if (!isalnum(*str)) {
            count++;
        }
        str++;
    }
    return count;
}

// Function to check the strength of a password
int check_password_strength(char *password) {
    int length = strlen(password);
    int digits = count_digits(password);
    int uppercase = count_uppercase(password);
    int lowercase = count_lowercase(password);
    int special = count_special(password);

    int score = 0;
    if (length >= 8) {
        score += 1;
    }
    if (digits >= 1) {
        score += 1;
    }
    if (uppercase >= 1) {
        score += 1;
    }
    if (lowercase >= 1) {
        score += 1;
    }
    if (special >= 1) {
        score += 1;
    }

    return score;
}

int main() {
    char password[MAX_PASS_LEN];
    printf("Enter your password: ");
    scanf("%s", password);

    int strength = check_password_strength(password);

    if (strength <= 1) {
        printf("Weak password\n");
    } else if (strength <= 3) {
        printf("Moderate password\n");
    } else {
        printf("Strong password\n");
    }

    return 0;
}