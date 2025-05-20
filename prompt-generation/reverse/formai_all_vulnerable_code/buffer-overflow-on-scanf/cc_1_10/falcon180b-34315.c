//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 64
#define MIN_NUMBER_OF_DIGITS 1
#define MIN_NUMBER_OF_UPPERCASE_LETTERS 1
#define MIN_NUMBER_OF_LOWERCASE_LETTERS 1
#define MIN_NUMBER_OF_SPECIAL_CHARACTERS 1

int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

int is_uppercase(char c) {
    return (c >= 'A' && c <= 'Z');
}

int is_lowercase(char c) {
    return (c >= 'a' && c <= 'z');
}

int is_special_character(char c) {
    return (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*' || c == '(' || c == ')' || c == '-' || c == '_' || c == '+' || c == '=' || c == '{' || c == '}' || c == '[' || c == ']' || c == '|' || c == ';' || c == ':' || c == '"' || c == '\'' || c == '<' || c == '>' || c == ',' || c == '.' || c == '/' || c == '?' || c == '~');
}

int is_valid_password(char* password) {
    int length = strlen(password);
    if (length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH) {
        return 0;
    }
    int number_of_digits = 0;
    int number_of_uppercase_letters = 0;
    int number_of_lowercase_letters = 0;
    int number_of_special_characters = 0;
    for (int i = 0; i < length; i++) {
        char c = password[i];
        if (is_digit(c)) {
            number_of_digits++;
        } else if (is_uppercase(c)) {
            number_of_uppercase_letters++;
        } else if (is_lowercase(c)) {
            number_of_lowercase_letters++;
        } else if (is_special_character(c)) {
            number_of_special_characters++;
        }
    }
    if (number_of_digits < MIN_NUMBER_OF_DIGITS || number_of_uppercase_letters < MIN_NUMBER_OF_UPPERCASE_LETTERS || number_of_lowercase_letters < MIN_NUMBER_OF_LOWERCASE_LETTERS || number_of_special_characters < MIN_NUMBER_OF_SPECIAL_CHARACTERS) {
        return 0;
    }
    return 1;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter your password: ");
    scanf("%s", password);
    if (is_valid_password(password)) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }
    return 0;
}