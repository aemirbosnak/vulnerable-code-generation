//Falcon2-11B DATASET v1.0 Category: Password Strength Checker ; Style: introspective
#include <stdio.h>
#include <stdbool.h>

int main() {
    // Prompt the user to enter a password
    printf("Enter a password: ");
    char password[100];
    scanf("%s", password);

    // Check if the password meets the minimum length requirement
    if (strlen(password) < 8) {
        printf("Weak password!\n");
        return 1;
    }

    // Check if the password contains at least one uppercase letter
    char uppercase = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            uppercase = true;
            break;
        }
    }
    if (!uppercase) {
        printf("Weak password!\n");
        return 1;
    }

    // Check if the password contains at least one lowercase letter
    char lowercase = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            lowercase = true;
            break;
        }
    }
    if (!lowercase) {
        printf("Weak password!\n");
        return 1;
    }

    // Check if the password contains at least one digit
    char digit = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            digit = true;
            break;
        }
    }
    if (!digit) {
        printf("Weak password!\n");
        return 1;
    }

    // Check if the password contains at least one special character
    char special = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] == '!' || password[i] == '@' || password[i] == '#' ||
            password[i] == '$' || password[i] == '%' ||
            password[i] == '^' || password[i] == '&' || password[i] == '*') {
            special = true;
            break;
        }
    }
    if (!special) {
        printf("Weak password!\n");
        return 1;
    }

    // If the password meets all the requirements, it is strong
    printf("Strong password!\n");
    return 0;
}