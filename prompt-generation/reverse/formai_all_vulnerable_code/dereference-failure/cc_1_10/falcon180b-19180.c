//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 32

int is_password_valid(char *password) {
    int length = strlen(password);
    if (length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH) {
        return 0;
    }
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;
    int has_special_character = 0;
    for (int i = 0; i < length; i++) {
        char c = tolower(password[i]);
        if (isalpha(c)) {
            has_uppercase = has_uppercase || isupper(c);
            has_lowercase = has_lowercase || islower(c);
        } else if (isdigit(c)) {
            has_number = 1;
        } else {
            has_special_character = 1;
        }
    }
    if (!has_uppercase ||!has_lowercase ||!has_number ||!has_special_character) {
        return 0;
    }
    return 1;
}

char *generate_password(int length) {
    char *password = malloc(length + 1);
    if (password == NULL) {
        return NULL;
    }
    for (int i = 0; i < length; i++) {
        char c = rand() % (26 + 26 + 10);
        if (c < 26) {
            password[i] = 'a' + c;
        } else if (c < 52) {
            password[i] = 'A' + (c - 26);
        } else {
            password[i] = '0' + (c - 52);
        }
    }
    password[length] = '\0';
    return password;
}

int main() {
    int length = 12;
    char *password = generate_password(length);
    int is_valid = is_password_valid(password);
    if (is_valid) {
        printf("Password is valid.\n");
    } else {
        printf("Password is not valid.\n");
    }
    free(password);
    return 0;
}