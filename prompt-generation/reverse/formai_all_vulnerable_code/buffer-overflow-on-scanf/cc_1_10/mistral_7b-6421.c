//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define WEAK 0
#define MODERATE 1
#define STRONG 2
#define VERY_STRONG 3

void check_password_length(char *password, int *password_strength);
void check_password_complexity(char *password, int length, int *password_strength);
void print_fortune(int strength);

int main() {
    char password[101];
    int password_strength = WEAK;

    printf("Welcome, traveler, to the password fortuneteller! Please enter your password: ");
    scanf("%s", password);

    check_password_length(password, &password_strength);
    if (password_strength == WEAK) {
        printf("Your password, %s, is too short. I sense a weakness within you.\n", password);
    }

    if (password_strength == WEAK || password_strength == MODERATE) {
        check_password_complexity(password, strlen(password), &password_strength);
    }

    print_fortune(password_strength);

    return 0;
}

void check_password_length(char *password, int *password_strength) {
    int length = strlen(password);

    if (length < MIN_LENGTH) {
        *password_strength = WEAK;
    } else {
        *password_strength = MODERATE;
    }
}

void check_password_complexity(char *password, int length, int *password_strength) {
    int i, count_digits = 0, count_uppercase = 0, count_lowercase = 0, count_special_chars = 0;

    for (i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            count_digits++;
        }

        if (isupper(password[i])) {
            count_uppercase++;
        }

        if (islower(password[i])) {
            count_lowercase++;
        }

        if (!isalnum(password[i])) {
            count_special_chars++;
        }
    }

    if (count_digits < 1) {
        *password_strength = MODERATE;
    } else {
        if (count_uppercase < 1) {
            *password_strength = STRONG;
        } else {
            if (count_lowercase < 1) {
                *password_strength = VERY_STRONG;
            }

            if (count_special_chars < 3) {
                *password_strength = STRONG;
            } else {
                *password_strength = VERY_STRONG;
            }
        }
    }
}

void print_fortune(int strength) {
    switch (strength) {
        case WEAK:
            printf("Your password, %s, is weak. Protect your secrets, traveler.\n", "your_password_here");
            break;
        case MODERATE:
            printf("Your password, %s, is moderate. Consider adding numbers, uppercase letters, and special characters.\n", "your_password_here");
            break;
        case STRONG:
            printf("Your password, %s, is strong. Your secrets are well guarded, traveler.\n", "your_password_here");
            break;
        case VERY_STRONG:
            printf("Your password, %s, is very strong. Your secrets are impenetrable, traveler.\n", "your_password_here");
            break;
    }
}