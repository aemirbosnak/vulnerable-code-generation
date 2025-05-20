//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100
#define MIN_LENGTH 8
#define MIN_UPPERCASE 1
#define MIN_LOWERCASE 1
#define MIN_DIGITS 1
#define MIN_SPECIAL 1

int is_uppercase(char c);
int is_lowercase(char c);
int is_digit(char c);
int is_special(char c);
int count_chars(char str[], int n, int (*f)(char));
int check_password_strength(char password[]);

int main() {
    char password[MAX_LENGTH];
    printf("Enter a password: ");
    scanf("%s", password);
    int strength = check_password_strength(password);
    switch (strength) {
        case 0:
            printf("Weak\n");
            break;
        case 1:
            printf("Medium\n");
            break;
        case 2:
            printf("Strong\n");
            break;
        default:
            printf("Invalid\n");
    }
    return 0;
}

int is_uppercase(char c) {
    return (c >= 'A' && c <= 'Z');
}

int is_lowercase(char c) {
    return (c >= 'a' && c <= 'z');
}

int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

int is_special(char c) {
    return (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*');
}

int count_chars(char str[], int n, int (*f)(char)) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (f(str[i]) == 1) {
            count++;
        }
    }
    return count;
}

int check_password_strength(char password[]) {
    int length = strlen(password);
    if (length < MIN_LENGTH) {
        return -1;
    }
    int uppercase_count = count_chars(password, length, is_uppercase);
    int lowercase_count = count_chars(password, length, is_lowercase);
    int digit_count = count_chars(password, length, is_digit);
    int special_count = count_chars(password, length, is_special);
    if (uppercase_count < MIN_UPPERCASE || lowercase_count < MIN_LOWERCASE || digit_count < MIN_DIGITS || special_count < MIN_SPECIAL) {
        return -1;
    }
    int strength = 0;
    if (length >= 12) {
        strength++;
    }
    if (uppercase_count >= 2 || lowercase_count >= 2) {
        strength++;
    }
    if (digit_count >= 2) {
        strength++;
    }
    if (special_count >= 2) {
        strength++;
    }
    return strength;
}