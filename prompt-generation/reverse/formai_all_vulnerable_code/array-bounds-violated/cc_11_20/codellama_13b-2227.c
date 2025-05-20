//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 16

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter your password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);
    password[strlen(password) - 1] = '\0';

    int password_strength = 0;
    if (strlen(password) < 8) {
        printf("Password too short\n");
    } else if (strlen(password) > 16) {
        printf("Password too long\n");
    } else {
        int upper_case = 0, lower_case = 0, digit = 0, special_char = 0;
        for (int i = 0; i < strlen(password); i++) {
            if (isupper(password[i])) {
                upper_case++;
            } else if (islower(password[i])) {
                lower_case++;
            } else if (isdigit(password[i])) {
                digit++;
            } else {
                special_char++;
            }
        }
        if (upper_case > 0) {
            password_strength++;
        }
        if (lower_case > 0) {
            password_strength++;
        }
        if (digit > 0) {
            password_strength++;
        }
        if (special_char > 0) {
            password_strength++;
        }
        if (password_strength > 2) {
            printf("Strong password\n");
        } else if (password_strength > 1) {
            printf("Medium password\n");
        } else {
            printf("Weak password\n");
        }
    }

    return 0;
}