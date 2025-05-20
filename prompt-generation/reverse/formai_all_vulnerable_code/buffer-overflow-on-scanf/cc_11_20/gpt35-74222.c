//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char password[50];
    int length, i, uppercase_count = 0, lowercase_count = 0, digit_count = 0, special_count = 0;
    printf("Enter a password: ");
    scanf("%s", password);
    length = strlen(password);

    if (length < 8) {
        printf("Your password isn't surreal enough.\n");
        exit(0);
    }

    for (i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            uppercase_count++;
        }
        else if (password[i] >= 'a' && password[i] <= 'z') {
            lowercase_count++;
        }
        else if (password[i] >= '0' && password[i] <= '9') {
            digit_count++;
        }
        else {
            special_count++;
        }
    }

    if (uppercase_count < 2) {
        printf("Sorry, your password needs more capital letters to be surreal.\n");
        exit(0);
    }

    if (lowercase_count < 2) {
        printf("Sorry, your password needs more lowercase letters to be surreal.\n");
        exit(0);
    }

    if (digit_count < 2) {
        printf("Sorry, your password needs more digits to be surreal.\n");
        exit(0);
    }

    if (special_count < 2) {
        printf("Sorry, your password needs more special characters to be surreal.\n");
        exit(0);
    }

    printf("Congratulations, your password is surreal enough.\n");

    return 0;
}