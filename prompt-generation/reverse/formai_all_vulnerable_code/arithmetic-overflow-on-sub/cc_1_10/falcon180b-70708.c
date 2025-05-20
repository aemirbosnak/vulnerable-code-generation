//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 64
#define MIN_PASSWORD_LENGTH 8
#define MAX_ATTEMPTS 5
#define DELAY_MS 1000

enum password_strength {
    WEAK,
    MEDIUM,
    STRONG
};

int get_password(char* password, int max_length) {
    char ch;
    int i = 0;

    while (i < max_length - 1) {
        ch = getchar();

        if (ch == '\n') {
            password[i] = '\0';
            break;
        } else if (isalnum(ch)) {
            password[i++] = ch;
        }
    }

    return i;
}

int check_password_strength(char* password) {
    int length = strlen(password);
    int uppercase_count = 0;
    int lowercase_count = 0;
    int digit_count = 0;

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase_count++;
        } else if (islower(password[i])) {
            lowercase_count++;
        } else if (isdigit(password[i])) {
            digit_count++;
        }
    }

    if (length < MIN_PASSWORD_LENGTH) {
        return WEAK;
    } else if (uppercase_count && lowercase_count && digit_count) {
        return STRONG;
    } else {
        return MEDIUM;
    }
}

void delay(int ms) {
    clock_t start_time = clock();
    while (clock() - start_time < ms);
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int attempts_left = MAX_ATTEMPTS;

    while (attempts_left > 0) {
        printf("Enter a password: ");
        int password_length = get_password(password, MAX_PASSWORD_LENGTH);

        enum password_strength strength = check_password_strength(password);

        if (strength == STRONG) {
            printf("Password is strong.\n");
            break;
        } else if (strength == MEDIUM) {
            printf("Password is medium.\n");
            attempts_left--;
        } else {
            printf("Password is weak.\n");
            attempts_left--;
        }

        delay(DELAY_MS);
    }

    return 0;
}