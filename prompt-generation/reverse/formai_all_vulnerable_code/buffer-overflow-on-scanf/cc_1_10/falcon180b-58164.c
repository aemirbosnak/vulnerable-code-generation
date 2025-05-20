//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20
#define MIN_PASSWORD_LENGTH 8
#define MIN_LOWER_CASE 1
#define MIN_UPPER_CASE 1
#define MIN_NUMBERS 1
#define MIN_SPECIAL_CHARACTERS 1

int is_lower_case(char c);
int is_upper_case(char c);
int is_number(char c);
int is_special_character(char c);

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int password_length;
    int has_lower_case = 0;
    int has_upper_case = 0;
    int has_number = 0;
    int has_special_character = 0;

    printf("Welcome to the Happy Password Strength Checker!\n");
    printf("Please enter a password:\n");
    scanf("%s", password);
    password_length = strlen(password);

    if (password_length < MIN_PASSWORD_LENGTH) {
        printf("Sorry, your password is too short. It should be at least %d characters long.\n", MIN_PASSWORD_LENGTH);
        return 1;
    }

    if (!has_lower_case) {
        printf("Sorry, your password should contain at least %d lower case letter(s).\n", MIN_LOWER_CASE);
        return 1;
    }

    if (!has_upper_case) {
        printf("Sorry, your password should contain at least %d upper case letter(s).\n", MIN_UPPER_CASE);
        return 1;
    }

    if (!has_number) {
        printf("Sorry, your password should contain at least %d number(s).\n", MIN_NUMBERS);
        return 1;
    }

    if (!has_special_character) {
        printf("Sorry, your password should contain at least %d special character(s).\n", MIN_SPECIAL_CHARACTERS);
        return 1;
    }

    printf("Congratulations! Your password is strong enough.\n");
    return 0;
}

int is_lower_case(char c) {
    return (c >= 'a' && c <= 'z');
}

int is_upper_case(char c) {
    return (c >= 'A' && c <= 'Z');
}

int is_number(char c) {
    return (c >= '0' && c <= '9');
}

int is_special_character(char c) {
    return (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '&' || c == '*' || c == '?' || c == '/' || c == '\\' || c == '|' || c == '~');
}