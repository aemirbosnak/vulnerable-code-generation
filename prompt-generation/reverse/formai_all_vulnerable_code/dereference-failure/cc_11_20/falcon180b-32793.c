//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 64

int is_valid_password(const char* password) {
    int length = strlen(password);
    if (length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH) {
        return 0;
    }
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;
    int has_special_char = 0;
    for (int i = 0; i < length; i++) {
        char c = tolower(password[i]);
        if (isalpha(c)) {
            if (isupper(c)) {
                has_uppercase = 1;
            } else {
                has_lowercase = 1;
            }
        } else if (isdigit(c)) {
            has_number = 1;
        } else if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '&' || c == '*' || c == '?') {
            has_special_char = 1;
        }
    }
    if (has_uppercase && has_lowercase && has_number && has_special_char) {
        return 1;
    } else {
        return 0;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <password>\n", argv[0]);
        return 1;
    }
    char* password = argv[1];
    int is_valid = is_valid_password(password);
    if (is_valid) {
        printf("Password is strong\n");
    } else {
        printf("Password is weak\n");
    }
    return 0;
}