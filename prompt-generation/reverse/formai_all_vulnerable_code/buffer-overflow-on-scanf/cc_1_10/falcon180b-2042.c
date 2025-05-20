//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: invasive
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 100

bool is_password_valid(char *password);
void generate_password(char *password);

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int length;

    printf("Enter password length (between 8 and 100): ");
    scanf("%d", &length);

    if (length < 8 || length > MAX_PASSWORD_LENGTH) {
        printf("Invalid password length.\n");
        return 1;
    }

    printf("Enter password: ");
    scanf("%s", password);

    if (!is_password_valid(password)) {
        printf("Invalid password.\n");
        return 1;
    }

    printf("Password is valid.\n");
    return 0;
}

bool is_password_valid(char *password) {
    int length = strlen(password);

    if (length < 8) {
        return false;
    }

    int has_uppercase = false;
    int has_lowercase = false;
    int has_digit = false;
    int has_special = false;

    for (int i = 0; i < length; i++) {
        char c = password[i];

        if (isupper(c)) {
            has_uppercase = true;
        } else if (islower(c)) {
            has_lowercase = true;
        } else if (isdigit(c)) {
            has_digit = true;
        } else if (!isalnum(c)) {
            has_special = true;
        }
    }

    if (!has_uppercase ||!has_lowercase ||!has_digit ||!has_special) {
        return false;
    }

    return true;
}

void generate_password(char *password) {
    int length = strlen(password);

    if (length < 8) {
        printf("Password must be at least 8 characters long.\n");
        return;
    }

    int has_uppercase = false;
    int has_lowercase = false;
    int has_digit = false;
    int has_special = false;

    for (int i = 0; i < length; i++) {
        char c = password[i];

        if (isupper(c)) {
            has_uppercase = true;
        } else if (islower(c)) {
            has_lowercase = true;
        } else if (isdigit(c)) {
            has_digit = true;
        } else if (!isalnum(c)) {
            has_special = true;
        }
    }

    if (!has_uppercase ||!has_lowercase ||!has_digit ||!has_special) {
        printf("Password must contain at least one uppercase letter, one lowercase letter, one digit, and one special character.\n");
        return;
    }

    printf("Password is valid.\n");
}