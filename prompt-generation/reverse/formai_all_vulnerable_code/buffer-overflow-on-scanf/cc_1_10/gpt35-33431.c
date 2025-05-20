//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: thoughtful
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool contains_digit(char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            return true;
        }
    }
    return false;
}

bool contains_uppercase(char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            return true;
        }
    }
    return false;
}

bool contains_lowercase(char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            return true;
        }
    }
    return false;
}

bool contains_special(char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (!isalnum(password[i])) {
            return true;
        }
    }
    return false;
}

bool is_long_enough(char* password) {
    return strlen(password) >= 8;
}

int get_password_strength(char* password) {
    int strength = 0;
    if (contains_digit(password)) {
        strength++;
    }
    if (contains_uppercase(password)) {
        strength++;
    }
    if (contains_lowercase(password)) {
        strength++;
    }
    if (contains_special(password)) {
        strength++;
    }
    if (is_long_enough(password)) {
        strength++;
    }
    return strength;
}

int main() {
    char password[100];
    printf("Enter a password: ");
    scanf("%s", password);
    int strength = get_password_strength(password);
    switch (strength) {
        case 0:
        case 1:
            printf("Weak\n");
            break;
        case 2:
            printf("Moderate\n");
            break;
        case 3:
        case 4:
            printf("Strong\n");
            break;
        case 5:
            printf("Very strong\n");
            break;
    }
    return 0;
}