//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: satisfied
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check the length of the password
bool check_length(char* password) {
    int len = strlen(password);
    return len >= 8;
}

// Function to check for uppercase characters
bool check_uppercase(char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            return true;
        }
    }
    return false;
}

// Function to check for lowercase characters
bool check_lowercase(char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            return true;
        }
    }
    return false;
}

// Function to check for digits
bool check_digits(char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            return true;
        }
    }
    return false;
}

// Function to check for special characters
bool check_special_characters(char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%') {
            return true;
        }
    }
    return false;
}

// Function to check if the password meets the strength criteria
bool check_password_strength(char* password) {
    return check_length(password) && check_uppercase(password) && check_lowercase(password) && check_digits(password) && check_special_characters(password);
}

// Function to get the password strength rating
int get_password_strength_rating(char* password) {
    int rating = 0;
    if (check_length(password)) {
        rating++;
    }
    if (check_uppercase(password)) {
        rating++;
    }
    if (check_lowercase(password)) {
        rating++;
    }
    if (check_digits(password)) {
        rating++;
    }
    if (check_special_characters(password)) {
        rating++;
    }
    return rating;
}

// Function to print the password strength rating
void print_password_strength_rating(char* password) {
    int rating = get_password_strength_rating(password);
    printf("Password Strength Rating: %d/5\n", rating);
    switch (rating) {
        case 1:
            printf("Weak password. Please strengthen your password.\n");
            break;
        case 2:
            printf("Fair password. Consider strengthening your password.\n");
            break;
        case 3:
            printf("Good password. Your password is fairly strong.\n");
            break;
        case 4:
            printf("Strong password. Your password is strong and secure.\n");
            break;
        case 5:
            printf("Excellent password. Your password is very strong and secure.\n");
            break;
    }
}

int main() {
    char password[100];
    printf("Enter password: ");
    scanf("%s", password);

    bool is_strong = check_password_strength(password);
    if (is_strong) {
        printf("Your password is strong and secure.\n");
    } else {
        printf("Your password is weak. Please strengthen your password.\n");
    }

    print_password_strength_rating(password);

    return 0;
}