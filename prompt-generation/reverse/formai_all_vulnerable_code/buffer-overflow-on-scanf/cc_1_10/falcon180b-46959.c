//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: single-threaded
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 100
#define MIN_PASSWORD_LENGTH 8

int is_valid_password(char* password) {
    int length = strlen(password);

    if (length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH) {
        return 0;
    }

    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;
    int has_special_char = 0;

    for (int i = 0; i < length; i++) {
        char c = password[i];

        if (isupper(c)) {
            has_uppercase = 1;
        } else if (islower(c)) {
            has_lowercase = 1;
        } else if (isdigit(c)) {
            has_number = 1;
        } else if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '&' || c == '*') {
            has_special_char = 1;
        }
    }

    if (has_uppercase && has_lowercase && has_number && has_special_char) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char password[MAX_PASSWORD_LENGTH] = {0};
    int length = 0;

    printf("Enter password: ");
    scanf("%s", password);

    length = strlen(password);

    if (is_valid_password(password)) {
        printf("Password is strong\n");
    } else {
        printf("Password is weak\n");
    }

    return 0;
}