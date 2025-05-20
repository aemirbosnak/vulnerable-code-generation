//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check for password strength
int check_password_strength(char password[]) {
    int length, digits, uppercase, lowercase, special, strength;

    length = strlen(password);
    digits = uppercase = lowercase = special = strength = 0;

    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            digits++;
        } else if (isupper(password[i])) {
            uppercase++;
        } else if (islower(password[i])) {
            lowercase++;
        } else {
            special++;
        }
    }

    if (length < 8) {
        return 0;
    } else if (digits < 2) {
        return 1; // Weak password
    } else if (uppercase < 1 || lowercase < 1) {
        return 2; // Medium password
    } else if (special < 1) {
        return 3; // Strong password
    } else {
        return 4; // Very strong password
    }
}

int main() {
    char password[50];
    int strength;

    printf("Enter your password: ");
    scanf("%s", &password);

    strength = check_password_strength(password);

    switch (strength) {
        case 0:
            printf("Your password is too short. It needs to be at least 8 characters long.\n");
            break;
        case 1:
            printf("Your password is weak. It needs to have at least 2 digits.\n");
            break;
        case 2:
            printf("Your password is medium. It needs to have at least 1 uppercase and 1 lowercase letter.\n");
            break;
        case 3:
            printf("Your password is strong. It needs to have at least 1 special character.\n");
            break;
        case 4:
            printf("Your password is very strong. Congratulations!\n");
            break;
        default:
            printf("Invalid password.\n");
            break;
    }

    return 0;
}