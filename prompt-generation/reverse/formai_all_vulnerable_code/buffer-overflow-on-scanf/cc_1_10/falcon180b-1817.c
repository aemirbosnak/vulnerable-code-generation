//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 32
#define MIN_PASSWORD_LENGTH 8
#define UPPER_CASE 'A'
#define LOWER_CASE 'a'
#define NUMBER '0'
#define SPECIAL_CHAR '!'

int is_valid_password(char *password);
int is_strong_password(char *password);

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter your password: ");
    scanf("%s", password);

    if (is_valid_password(password)) {
        if (is_strong_password(password)) {
            printf("Your password is strong.\n");
        } else {
            printf("Your password is weak.\n");
        }
    } else {
        printf("Invalid password.\n");
    }

    return 0;
}

int is_valid_password(char *password) {
    int length = strlen(password);

    if (length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH) {
        return 0;
    }

    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i]) && password[i]!= SPECIAL_CHAR) {
            return 0;
        }
    }

    return 1;
}

int is_strong_password(char *password) {
    int has_upper = 0;
    int has_lower = 0;
    int has_number = 0;
    int has_special = 0;

    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            has_upper = 1;
        } else if (islower(password[i])) {
            has_lower = 1;
        } else if (isdigit(password[i])) {
            has_number = 1;
        } else if (password[i] == SPECIAL_CHAR) {
            has_special = 1;
        }
    }

    if (has_upper && has_lower && has_number && has_special) {
        return 1;
    } else {
        return 0;
    }
}