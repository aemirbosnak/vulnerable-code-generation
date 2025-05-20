//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: Alan Turing
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LENGTH 100

// Function to count the number of uppercase letters in a string
int count_uppercase(const char* str) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (isupper(str[i])) {
            count++;
        }
    }
    return count;
}

// Function to count the number of lowercase letters in a string
int count_lowercase(const char* str) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (islower(str[i])) {
            count++;
        }
    }
    return count;
}

// Function to count the number of digits in a string
int count_digits(const char* str) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (isdigit(str[i])) {
            count++;
        }
    }
    return count;
}

// Function to count the number of special characters in a string
int count_special_chars(const char* str) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (!isalnum(str[i])) {
            count++;
        }
    }
    return count;
}

// Function to check if a string contains only letters and numbers
bool is_valid_input(const char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isalnum(str[i])) {
            return false;
        }
    }
    return true;
}

// Function to check the strength of a password
int check_password_strength(const char* password) {
    int length = strlen(password);
    if (length < 8) {
        return 1; // Weak password
    }
    int uppercase_count = count_uppercase(password);
    int lowercase_count = count_lowercase(password);
    int digit_count = count_digits(password);
    int special_char_count = count_special_chars(password);
    if (length >= 12 && uppercase_count >= 1 && lowercase_count >= 1 && digit_count >= 1 && special_char_count >= 1) {
        return 5; // Strong password
    } else if (length >= 10 && uppercase_count >= 1 && lowercase_count >= 1 && digit_count >= 1) {
        return 4; // Good password
    } else if (length >= 8 && uppercase_count >= 1 && lowercase_count >= 1) {
        return 3; // Moderate password
    } else {
        return 2; // Weak password
    }
}

int main() {
    char password[MAX_LENGTH];
    printf("Enter a password: ");
    scanf("%s", password);
    if (!is_valid_input(password)) {
        printf("Invalid input. Password must contain only letters and numbers.\n");
        return 1;
    }
    int strength = check_password_strength(password);
    switch (strength) {
        case 1:
            printf("Weak password.\n");
            break;
        case 2:
            printf("Weak password.\n");
            break;
        case 3:
            printf("Moderate password.\n");
            break;
        case 4:
            printf("Good password.\n");
            break;
        case 5:
            printf("Strong password.\n");
            break;
        default:
            printf("Invalid strength level.\n");
            break;
    }
    return 0;
}