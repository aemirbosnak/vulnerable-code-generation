//Falcon2-11B DATASET v1.0 Category: Password Strength Checker ; Style: satisfied
#include <stdio.h>
#include <string.h>

// Function to check password strength
int check_password_strength(char* password) {
    int length = strlen(password);
    int uppercase_count = 0;
    int lowercase_count = 0;
    int digit_count = 0;
    int special_count = 0;

    // Checking for uppercase characters
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            uppercase_count++;
        }
    }

    // Checking for lowercase characters
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            lowercase_count++;
        }
    }

    // Checking for digits
    for (int i = 0; i < length; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            digit_count++;
        }
    }

    // Checking for special characters
    for (int i = 0; i < length; i++) {
        if (password[i] == '!', password[i] == '@', password[i] == '#', password[i] == '$', password[i] == '%', password[i] == '^', password[i] == '&', password[i] == '*', password[i] == '-', password[i] == '_') {
            special_count++;
        }
    }

    if (uppercase_count >= 1 && lowercase_count >= 1 && digit_count >= 1 && special_count >= 1) {
        return 1; // Strong password
    } else if (uppercase_count >= 1 && lowercase_count >= 1 && digit_count >= 1) {
        return 2; // Weak password
    } else if (uppercase_count >= 1 && lowercase_count >= 1 && special_count >= 1) {
        return 3; // Medium password
    } else if (uppercase_count >= 1 && digit_count >= 1 && special_count >= 1) {
        return 4; // Weak password
    } else if (lowercase_count >= 1 && digit_count >= 1 && special_count >= 1) {
        return 5; // Medium password
    } else if (uppercase_count >= 1 && special_count >= 1) {
        return 6; // Weak password
    } else if (lowercase_count >= 1 && special_count >= 1) {
        return 7; // Medium password
    } else if (digit_count >= 1 && special_count >= 1) {
        return 8; // Weak password
    } else if (uppercase_count >= 1) {
        return 9; // Weak password
    } else if (lowercase_count >= 1) {
        return 10; // Weak password
    } else if (digit_count >= 1) {
        return 11; // Weak password
    } else if (special_count >= 1) {
        return 12; // Weak password
    } else {
        return 13; // Very weak password
    }
}

int main() {
    char password[50];
    printf("Enter password: ");
    scanf("%s", password);

    int strength = check_password_strength(password);

    if (strength == 1) {
        printf("Password is strong\n");
    } else if (strength == 2) {
        printf("Password is weak\n");
    } else if (strength == 3) {
        printf("Password is medium\n");
    } else if (strength == 4) {
        printf("Password is weak\n");
    } else if (strength == 5) {
        printf("Password is medium\n");
    } else if (strength == 6) {
        printf("Password is weak\n");
    } else if (strength == 7) {
        printf("Password is medium\n");
    } else if (strength == 8) {
        printf("Password is weak\n");
    } else if (strength == 9) {
        printf("Password is weak\n");
    } else if (strength == 10) {
        printf("Password is weak\n");
    } else if (strength == 11) {
        printf("Password is weak\n");
    } else if (strength == 12) {
        printf("Password is weak\n");
    } else if (strength == 13) {
        printf("Password is very weak\n");
    } else {
        printf("Error: Invalid password\n");
    }

    return 0;
}