//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: complete
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to calculate the strength of a password
int password_strength(char* password) {
    int length = strlen(password);
    int score = 0;

    // Check if the password contains at least one uppercase letter
    for (int i=0; i<length; i++) {
        if (isupper(password[i])) {
            score += 2;
            break;
        }
    }

    // Check if the password contains at least one lowercase letter
    for (int i=0; i<length; i++) {
        if (islower(password[i])) {
            score += 2;
            break;
        }
    }

    // Check if the password contains at least one number
    for (int i=0; i<length; i++) {
        if (isdigit(password[i])) {
            score += 2;
            break;
        }
    }

    // Check if the password contains at least one special character
    int special_chars_count = 0;
    char special_chars[] = "!@#$%^&*()_+-={}[]|\\:;\"'<>,.?/";

    for (int i=0; i<length; i++) {
        for (int j=0; j<strlen(special_chars); j++) {
            if (password[i] == special_chars[j]) {
                special_chars_count++;
                break;
            }
        }
    }

    if (special_chars_count > 0) {
        score += 2;
    }

    // Check the length of the password
    if (length <= 6) {
        score -= 2;
    } else if (length > 6 && length <= 8) {
        score += 2;
    } else if (length > 8) {
        score += 3;
    }

    return score;
}

// Main function
int main() {
    char password[50];
    
    printf("Enter your password: ");
    scanf("%s", password);
    
    int strength = password_strength(password);

    // Output the password strength
    if (strength < 5) {
        printf("The strength of the password is weak.\n");
    } else if (strength >= 5 && strength < 8) {
        printf("The strength of the password is medium.\n");
    } else {
        printf("The strength of the password is strong.\n");
    }

    return 0;
}