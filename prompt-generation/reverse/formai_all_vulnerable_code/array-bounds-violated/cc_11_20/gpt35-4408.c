//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: statistical
#include <stdio.h>
#include <string.h>

#define MIN_LENGTH 8 // Minimum password length
#define MAX_LENGTH 20 // Maximum password length
#define MIN_LOWER 2 // Minimum number of lowercase letters
#define MIN_UPPER 2 // Minimum number of uppercase letters
#define MIN_DIGIT 2 // Minimum number of digits
#define MIN_SPECIAL 1 // Minimum number of special characters
#define SPECIAL_CHARS "!@#$%^&*()-=_+[]{}|;':\",./<>?" // Allowed special characters

int main() {
    char password[MAX_LENGTH + 1]; // Password string
    int length, lower, upper, digit, special; // Password statistics

    // Get password input from user
    printf("Enter your password: ");
    fgets(password, MAX_LENGTH + 1, stdin);

    // Remove newline character from input
    length = strlen(password);
    if (password[length - 1] == '\n') {
        password[length - 1] = '\0';
        length--;
    }

    // Initialize password statistics to zero
    lower = upper = digit = special = 0;

    // Loop through password string and count statistics
    for (int i = 0; i < length; i++) {
        char c = password[i];
        if (c >= 'a' && c <= 'z') {
            lower++;
        } else if (c >= 'A' && c <= 'Z') {
            upper++;
        } else if (c >= '0' && c <= '9') {
            digit++;
        } else if (strchr(SPECIAL_CHARS, c) != NULL) {
            special++;
        }
    }

    // Check password strength and print results
    if (length < MIN_LENGTH) {
        printf("Your password is too short. Please enter a password that is at least %d characters long.\n", MIN_LENGTH);
    } else if (length > MAX_LENGTH) {
        printf("Your password is too long. Please enter a password that is no more than %d characters long.\n", MAX_LENGTH);
    } else if (lower < MIN_LOWER) {
        printf("Your password does not contain enough lowercase letters. Please include at least %d lowercase letters.\n", MIN_LOWER);
    } else if (upper < MIN_UPPER) {
        printf("Your password does not contain enough uppercase letters. Please include at least %d uppercase letters.\n", MIN_UPPER);
    } else if (digit < MIN_DIGIT) {
        printf("Your password does not contain enough digits. Please include at least %d digits.\n", MIN_DIGIT);
    } else if (special < MIN_SPECIAL) {
        printf("Your password does not contain enough special characters. Please include at least %d special characters from this list: %s.\n", MIN_SPECIAL, SPECIAL_CHARS);
    } else {
        printf("Your password is strong and meets all requirements!\n");
    }

    return 0;
}