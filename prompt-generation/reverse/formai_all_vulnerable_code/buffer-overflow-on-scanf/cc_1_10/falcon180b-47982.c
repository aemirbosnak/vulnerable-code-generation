//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1024

int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

int is_lower(char c) {
    return (c >= 'a' && c <= 'z');
}

int is_upper(char c) {
    return (c >= 'A' && c <= 'Z');
}

int is_special(char c) {
    return (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '&' || c == '*');
}

int is_password_valid(char* password) {
    int len = strlen(password);
    if (len < 8 || len > MAX_LEN) {
        return 0;
    }
    int has_digit = 0;
    int has_lower = 0;
    int has_upper = 0;
    int has_special = 0;
    for (int i = 0; i < len; i++) {
        char c = tolower(password[i]);
        if (is_digit(c)) {
            has_digit = 1;
        } else if (is_lower(c)) {
            has_lower = 1;
        } else if (is_upper(c)) {
            has_upper = 1;
        } else if (is_special(c)) {
            has_special = 1;
        }
    }
    return has_digit && has_lower && has_upper && has_special;
}

void generate_password(char* password, int len) {
    for (int i = 0; i < len; i++) {
        char c = rand() % 26 + 'a';
        password[i] = c;
    }
    password[len] = '\0';
}

int main() {
    char password[MAX_LEN];
    int len;
    printf("Enter the desired length of the password: ");
    scanf("%d", &len);
    if (len < 8 || len > MAX_LEN) {
        printf("Invalid password length.\n");
        return 1;
    }
    generate_password(password, len);
    if (is_password_valid(password)) {
        printf("Password is valid.\n");
    } else {
        printf("Password is not valid.\n");
    }
    return 0;
}