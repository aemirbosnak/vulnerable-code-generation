//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: medieval
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 100
#define MIN_PASSWORD_LENGTH 8
#define MIN_LOWER_CASE_COUNT 1
#define MIN_UPPER_CASE_COUNT 1
#define MIN_NUMBER_COUNT 1
#define MIN_SPECIAL_CHAR_COUNT 1

#define LOWER_CASE_CHARS "abcdefghijklmnopqrstuvwxyz"
#define UPPER_CASE_CHARS "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUMBER_CHARS "0123456789"
#define SPECIAL_CHARS "!@#$%^&*()_+-=[]{}|;:,.<>?"

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int password_length;
    bool is_strong_password = false;

    printf("Enter a password: ");
    scanf("%s", password);
    password_length = strlen(password);

    if (password_length < MIN_PASSWORD_LENGTH) {
        printf("Password must be at least %d characters long.\n", MIN_PASSWORD_LENGTH);
        return 1;
    }

    int lower_case_count = 0;
    int upper_case_count = 0;
    int number_count = 0;
    int special_char_count = 0;

    for (int i = 0; i < password_length; i++) {
        if (islower(password[i])) {
            lower_case_count++;
        } else if (isupper(password[i])) {
            upper_case_count++;
        } else if (isdigit(password[i])) {
            number_count++;
        } else if (strchr(SPECIAL_CHARS, password[i])!= NULL) {
            special_char_count++;
        }
    }

    if (lower_case_count < MIN_LOWER_CASE_COUNT ||
        upper_case_count < MIN_UPPER_CASE_COUNT ||
        number_count < MIN_NUMBER_COUNT ||
        special_char_count < MIN_SPECIAL_CHAR_COUNT) {
        printf("Password must contain at least %d lowercase letters, %d uppercase letters, %d numbers, and %d special characters.\n", MIN_LOWER_CASE_COUNT, MIN_UPPER_CASE_COUNT, MIN_NUMBER_COUNT, MIN_SPECIAL_CHAR_COUNT);
        return 1;
    }

    is_strong_password = true;

    printf("Password strength: ");
    if (is_strong_password) {
        printf("Strong\n");
    } else {
        printf("Weak\n");
    }

    return 0;
}