//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_lowercase(char c) {
    return c >= 'a' && c <= 'z';
}

bool is_uppercase(char c) {
    return c >= 'A' && c <= 'Z';
}

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

bool is_special(char c) {
    return !is_lowercase(c) && !is_uppercase(c) && !is_digit(c); 
}

int count_lowercase(char* password, int length, int i) {
    if (i == length) {
        return 0;
    }
    return is_lowercase(password[i]) + count_lowercase(password, length, i+1);
}

int count_uppercase(char* password, int length, int i) {
    if (i == length) {
        return 0;
    }
    return is_uppercase(password[i]) + count_uppercase(password, length, i+1);
}

int count_digits(char* password, int length, int i) {
    if (i == length) {
        return 0;
    }
    return is_digit(password[i]) + count_digits(password, length, i+1);
}

int count_special(char* password, int length, int i) {
    if (i == length) {
        return 0;
    }
    return is_special(password[i]) + count_special(password, length, i+1);
}

bool has_lowercase(char* password, int length) {
    return count_lowercase(password, length, 0) > 0;
}

bool has_uppercase(char* password, int length) {
    return count_uppercase(password, length, 0) > 0;
}

bool has_digits(char* password, int length) {
    return count_digits(password, length, 0) > 0;
}

bool has_special(char* password, int length) {
    return count_special(password, length, 0) > 0;
}

bool is_strong(char* password, int length) {
    return length >= 8 && has_lowercase(password, length) && 
           has_uppercase(password, length) && has_digits(password, length) 
           && has_special(password, length);
}

void print_strength(char* password, int length) {
    if (is_strong(password, length)) {
        printf("Your password is strong!\n");
    }
    else {
        printf("Your password is weak. Please make it stronger.\n");
    }
}

int main() {
    char password[50];
    printf("Enter your password: ");
    fgets(password, 50, stdin);
    int length = strlen(password) - 1;
    password[length] = '\0'; 
    print_strength(password, length);
    return 0;
}