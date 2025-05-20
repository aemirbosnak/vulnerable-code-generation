//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the password is strong
int check_password_strength(char *password, int min_length, int max_length, int min_uppercase, int min_lowercase, int min_digits, int min_special_characters) {
    // Check the length of the password
    if (strlen(password) < min_length || strlen(password) > max_length) {
        return 0;
    }

    // Check the number of uppercase characters in the password
    int num_uppercase = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            num_uppercase++;
        }
    }
    if (num_uppercase < min_uppercase) {
        return 0;
    }

    // Check the number of lowercase characters in the password
    int num_lowercase = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            num_lowercase++;
        }
    }
    if (num_lowercase < min_lowercase) {
        return 0;
    }

    // Check the number of digits in the password
    int num_digits = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            num_digits++;
        }
    }
    if (num_digits < min_digits) {
        return 0;
    }

    // Check the number of special characters in the password
    int num_special_characters = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (!((password[i] >= 'A' && password[i] <= 'Z') || (password[i] >= 'a' && password[i] <= 'z') || (password[i] >= '0' && password[i] <= '9'))) {
            num_special_characters++;
        }
    }
    if (num_special_characters < min_special_characters) {
        return 0;
    }

    // If all the checks pass, the password is strong
    return 1;
}

int main() {
    // Get the password from the user
    char password[100];
    printf("Enter your password: ");
    scanf("%s", password);

    // Check the strength of the password
    int strong = check_password_strength(password, 8, 16, 1, 1, 1, 1);

    // Print the result
    if (strong) {
        printf("Your password is strong.\n");
    } else {
        printf("Your password is weak.\n");
    }

    return 0;
}