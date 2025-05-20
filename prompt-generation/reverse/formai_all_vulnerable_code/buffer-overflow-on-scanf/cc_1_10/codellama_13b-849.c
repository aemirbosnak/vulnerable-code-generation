//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: Sherlock Holmes
/*
 * C Program to check the password strength
 * in a Sherlock Holmes style
 */
#include <stdio.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 100

// Function to check the password strength
int check_password_strength(char *password) {
    int length = strlen(password);
    if (length < 8) {
        return 0;
    }

    int num_upper = 0, num_lower = 0, num_digit = 0, num_special = 0;
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            num_upper++;
        } else if (islower(password[i])) {
            num_lower++;
        } else if (isdigit(password[i])) {
            num_digit++;
        } else {
            num_special++;
        }
    }

    int score = 0;
    if (num_upper >= 2) {
        score++;
    }
    if (num_lower >= 2) {
        score++;
    }
    if (num_digit >= 2) {
        score++;
    }
    if (num_special >= 2) {
        score++;
    }

    return score;
}

// Driver code
int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter the password to check: ");
    scanf("%s", password);

    int score = check_password_strength(password);
    if (score >= 4) {
        printf("The password is strong!\n");
    } else {
        printf("The password is weak!\n");
    }

    return 0;
}