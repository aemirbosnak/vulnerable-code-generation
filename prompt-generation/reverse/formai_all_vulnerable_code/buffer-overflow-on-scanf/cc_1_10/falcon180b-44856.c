//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: brave
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 50

int is_valid_password(char *password);
int is_strong_password(char *password);

int main() {
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter a password to check its strength: ");
    scanf("%s", password);

    if (is_valid_password(password)) {
        if (is_strong_password(password)) {
            printf("Password is strong.\n");
        } else {
            printf("Password is weak.\n");
        }
    } else {
        printf("Invalid password.\n");
    }

    return 0;
}

int is_valid_password(char *password) {
    if (strlen(password) < 8 || strlen(password) > MAX_PASSWORD_LENGTH) {
        return 0;
    }

    for (int i = 0; i < strlen(password); i++) {
        if (!isalpha(password[i])) {
            return 0;
        }
    }

    return 1;
}

int is_strong_password(char *password) {
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;
    int has_special_char = 0;

    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
        } else if (islower(password[i])) {
            has_lowercase = 1;
        } else if (isdigit(password[i])) {
            has_number = 1;
        } else {
            has_special_char = 1;
        }
    }

    if (has_uppercase && has_lowercase && has_number && has_special_char) {
        return 1;
    } else {
        return 0;
    }
}