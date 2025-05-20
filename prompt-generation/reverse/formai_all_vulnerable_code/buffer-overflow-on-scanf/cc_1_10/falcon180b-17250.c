//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: detailed
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 20

int is_upper(char c) {
    return (c >= 'A' && c <= 'Z');
}

int is_lower(char c) {
    return (c >= 'a' && c <= 'z');
}

int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

int is_special(char c) {
    return (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '&' || c == '*' || c == '?' || c == '-' || c == '+');
}

int has_uppercase(char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (is_upper(password[i])) {
            return 1;
        }
    }
    return 0;
}

int has_lowercase(char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (is_lower(password[i])) {
            return 1;
        }
    }
    return 0;
}

int has_digit(char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (is_digit(password[i])) {
            return 1;
        }
    }
    return 0;
}

int has_special(char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (is_special(password[i])) {
            return 1;
        }
    }
    return 0;
}

int check_password_strength(char* password) {
    int score = 0;
    if (has_uppercase(password)) {
        score++;
    }
    if (has_lowercase(password)) {
        score++;
    }
    if (has_digit(password)) {
        score++;
    }
    if (has_special(password)) {
        score++;
    }
    if (strlen(password) > 12) {
        score++;
    }
    if (score <= 2) {
        printf("Weak\n");
    } else if (score <= 4) {
        printf("Average\n");
    } else {
        printf("Strong\n");
    }
}

int main() {
    char password[MAX_LENGTH];
    printf("Enter your password: ");
    scanf("%s", password);
    check_password_strength(password);
    return 0;
}