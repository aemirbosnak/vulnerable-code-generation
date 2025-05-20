//Falcon2-11B DATASET v1.0 Category: Password Strength Checker ; Style: peaceful
#include <stdio.h>
#include <string.h>

int main() {
    // Create a password string
    char password[100];
    strcpy(password, "MyPassword123");

    // Get user input
    char* user_input;
    printf("Enter your password: ");
    fgets(user_input, sizeof(user_input), stdin);

    // Check password strength
    int is_strong = 0;
    int length = strlen(password);
    int lower_case = 0;
    int upper_case = 0;
    int digit = 0;
    int special_char = 0;

    for (int i = 0; i < length; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            lower_case++;
        } else if (password[i] >= 'A' && password[i] <= 'Z') {
            upper_case++;
        } else if (password[i] >= '0' && password[i] <= '9') {
            digit++;
        } else if (password[i] == '!', password[i] == '@', password[i] == '#', password[i] == '$', password[i] == '%', password[i] == '^', password[i] == '&', password[i] == '*', password[i] == '_', password[i] == '+', password[i] == '=', password[i] == '?', password[i] == '`', password[i] == '~') {
            special_char++;
        }
    }

    // Check password length
    if (length >= 8) {
        is_strong = 1;
    }

    // Check password complexity
    if (lower_case > 0 && upper_case > 0 && digit > 0 && special_char > 0) {
        is_strong = 1;
    }

    // Print the result
    if (is_strong) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }

    return 0;
}