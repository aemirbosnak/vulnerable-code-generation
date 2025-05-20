//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 64

// Password strength calculation function
int calculate_password_strength(char *password) {
    int strength = 0;

    // Check for minimum length
    if (strlen(password) < MIN_LENGTH) {
        strength -= 10;
    } else if (strlen(password) > MAX_LENGTH) {
        strength -= 5;
    }

    // Check for upper and lower case characters
    int has_upper = 0;
    int has_lower = 0;
    for (int i = 0; i < strlen(password); i++) {
        char c = password[i];
        if (c >= 'A' && c <= 'Z') {
            has_upper = 1;
        } else if (c >= 'a' && c <= 'z') {
            has_lower = 1;
        }
    }
    if (has_upper && has_lower) {
        strength += 10;
    }

    // Check for digits
    int has_digit = 0;
    for (int i = 0; i < strlen(password); i++) {
        char c = password[i];
        if (c >= '0' && c <= '9') {
            has_digit = 1;
        }
    }
    if (has_digit) {
        strength += 10;
    }

    // Check for special characters
    int has_special = 0;
    char special[] = "!@#$%^&*()_-+={}[]|\\:;<>,.?";
    for (int i = 0; i < strlen(password); i++) {
        char c = password[i];
        for (int j = 0; j < strlen(special); j++) {
            if (c == special[j]) {
                has_special = 1;
            }
        }
    }
    if (has_special) {
        strength += 10;
    }

    // Check for repeated characters
    int has_repeated = 0;
    for (int i = 0; i < strlen(password); i++) {
        char c = password[i];
        for (int j = i + 1; j < strlen(password); j++) {
            if (c == password[j]) {
                has_repeated = 1;
            }
        }
    }
    if (has_repeated) {
        strength -= 5;
    }

    // Return the strength score
    return strength;
}

// Password strength rating function
char *calculate_password_strength_rating(int strength) {
    if (strength < 0) {
        return "Very Weak";
    } else if (strength < 10) {
        return "Weak";
    } else if (strength < 20) {
        return "Fair";
    } else if (strength < 30) {
        return "Good";
    } else if (strength < 40) {
        return "Strong";
    } else {
        return "Very Strong";
    }
}

// Main function
int main() {
    // Get the password from the user
    char password[MAX_LENGTH + 1];
    printf("Enter your password: ");
    scanf("%s", password);

    // Calculate the password strength
    int strength = calculate_password_strength(password);

    // Calculate the password strength rating
    char *rating = calculate_password_strength_rating(strength);

    // Print the password strength rating
    printf("Your password strength rating is: %s\n", rating);

    return 0;
}