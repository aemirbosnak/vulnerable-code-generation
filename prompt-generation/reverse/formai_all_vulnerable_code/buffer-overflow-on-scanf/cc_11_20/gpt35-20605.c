//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define password strength levels
enum strength { WEAK, MEDIUM, STRONG };

// Function to check password strength
enum strength check_password_strength(char* password) {
    int length = strlen(password);
    int has_digits = 0, has_uppercase = 0, has_lowercase = 0, has_special = 0;

    // Check if password has at least one digit, uppercase letter, lowercase letter, and special character
    for(int i = 0; i < length; i++) {
        if(isdigit(password[i])) {
            has_digits = 1;
        } else if(isupper(password[i])) {
            has_uppercase = 1;
        } else if(islower(password[i])) {
            has_lowercase = 1;
        } else if(!isdigit(password[i]) && !isalpha(password[i])) {
            has_special = 1;
        }
    }

    // Check password strength based on criteria
    if(length < 8 || !has_digits || !has_uppercase || !has_lowercase || !has_special) {
        return WEAK;
    } else if(length >= 8 && length <= 12 && has_digits && has_uppercase && has_lowercase && has_special) {
        return MEDIUM;
    } else if(length > 12 && has_digits && has_uppercase && has_lowercase && has_special) {
        return STRONG;
    }

    return WEAK;
}

int main() {
    char password[30];
    enum strength password_strength;

    printf("Enter a password: ");
    scanf("%s", password);

    password_strength = check_password_strength(password);

    // Display password strength result
    switch(password_strength) {
        case WEAK:
            printf("Password strength: WEAK\n");
            break;
        case MEDIUM:
            printf("Password strength: MEDIUM\n");
            break;
        case STRONG:
            printf("Password strength: STRONG\n");
            break;
    }

    return 0;
}