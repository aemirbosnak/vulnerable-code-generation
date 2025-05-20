//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Password strength checker function
int check_password_strength(char* password) {
    int length = strlen(password);
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;
    int has_special_char = 0;

    // Check if password contains uppercase, lowercase, number and special character
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            has_uppercase = 1;
        } else if (password[i] >= 'a' && password[i] <= 'z') {
            has_lowercase = 1;
        } else if (password[i] >= '0' && password[i] <= '9') {
            has_number = 1;
        } else if (password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '&' || password[i] == '*' || password[i] == '!' || password[i] == '?') {
            has_special_char = 1;
        }
    }

    // Calculate password strength based on number of criteria met
    int strength = 0;
    if (length >= 8) {
        strength++;
    }
    if (has_uppercase) {
        strength++;
    }
    if (has_lowercase) {
        strength++;
    }
    if (has_number) {
        strength++;
    }
    if (has_special_char) {
        strength++;
    }

    // Return password strength
    return strength;
}

int main() {
    char password[100];
    printf("Enter your password: ");
    scanf("%s", password);
    int strength = check_password_strength(password);
    printf("Password strength: %d\n", strength);
    return 0;
}