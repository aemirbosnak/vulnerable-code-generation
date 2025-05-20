//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 32
#define MIN_NUM_DIGITS 1
#define MIN_NUM_LETTERS 1
#define MIN_NUM_SYMBOLS 1
#define MAX_CONSECUTIVE_SAME_CHARACTERS 3

int main() {
    char password[MAX_LENGTH + 1];
    int password_strength;

    printf("Enter your password: ");
    scanf("%s", password);

    password_strength = check_password_strength(password);

    printf("Your password strength is: %d\n", password_strength);

    return 0;
}

int check_password_strength(char *password) {
    int password_strength;
    int password_length;
    int num_digits;
    int num_letters;
    int num_symbols;
    int consecutive_same_characters;
    int i;

    password_length = strlen(password);
    num_digits = 0;
    num_letters = 0;
    num_symbols = 0;
    consecutive_same_characters = 0;

    for (i = 0; i < password_length; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            num_digits++;
        } else if (password[i] >= 'a' && password[i] <= 'z') {
            num_letters++;
        } else if (password[i] >= 'A' && password[i] <= 'Z') {
            num_letters++;
        } else {
            num_symbols++;
        }

        if (i > 0 && password[i] == password[i - 1]) {
            consecutive_same_characters++;
        } else {
            consecutive_same_characters = 0;
        }
    }

    password_strength = 0;

    if (password_length >= MIN_LENGTH) {
        password_strength++;
    }

    if (num_digits >= MIN_NUM_DIGITS) {
        password_strength++;
    }

    if (num_letters >= MIN_NUM_LETTERS) {
        password_strength++;
    }

    if (num_symbols >= MIN_NUM_SYMBOLS) {
        password_strength++;
    }

    if (consecutive_same_characters <= MAX_CONSECUTIVE_SAME_CHARACTERS) {
        password_strength++;
    }

    return password_strength;
}