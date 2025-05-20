//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: careful
#include <stdio.h>
#include <string.h>

int main()
{
    char password[50];
    int length, hasLower = 0, hasUpper = 0, hasDigit = 0, hasSpecial = 0;

    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);  // get password from user

    // remove newline character from fgets
    if (password[strlen(password) - 1] == '\n') {
        password[strlen(password) - 1] = '\0';
    }

    length = strlen(password);  // get password length

    // check each character of the password
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            hasLower = 1;
        } else if (password[i] >= 'A' && password[i] <= 'Z') {
            hasUpper = 1;
        } else if (password[i] >= '0' && password[i] <= '9') {
            hasDigit = 1;
        } else {
            hasSpecial = 1;
        }
    }

    // calculate password strength score
    int strength = length * 10;
    if (hasLower && hasUpper) {
        strength += 20;
    }
    if (hasDigit && hasSpecial) {
        strength += 30;
    }

    // print password strength score and strength rating
    printf("\nPassword strength score: %d\n", strength);
    if (strength < 50) {
        printf("Password strength rating: Weak\n");
    } else if (strength >= 50 && strength < 80) {
        printf("Password strength rating: Medium\n");
    } else {
        printf("Password strength rating: Strong\n");
    }

    return 0;
}