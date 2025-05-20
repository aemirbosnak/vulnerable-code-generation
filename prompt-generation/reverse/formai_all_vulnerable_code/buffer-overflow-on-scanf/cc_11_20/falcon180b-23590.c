//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {

    char password[100];
    int length, i, j, count_uppercase = 0, count_lowercase = 0, count_numbers = 0, count_special_chars = 0;

    printf("Welcome to the Password Strength Checker!\n");

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    // Check for uppercase letters
    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            count_uppercase++;
        }
    }

    // Check for lowercase letters
    for (i = 0; i < length; i++) {
        if (islower(password[i])) {
            count_lowercase++;
        }
    }

    // Check for numbers
    for (i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            count_numbers++;
        }
    }

    // Check for special characters
    for (i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            count_special_chars++;
        }
    }

    if (length < 8) {
        printf("Password is too short! Please enter a password with at least 8 characters.\n");
        exit(1);
    }

    if ((count_uppercase == 0) && (count_lowercase == 0) && (count_numbers == 0) && (count_special_chars == 0)) {
        printf("Password is too weak! Please include a combination of uppercase letters, lowercase letters, numbers, and special characters.\n");
        exit(1);
    }

    printf("Password is strong enough. Well done!\n");

    return 0;

}