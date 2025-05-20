//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASS_LEN 32

int is_upper(char ch) {
    return (ch >= 'A' && ch <= 'Z');
}

int is_lower(char ch) {
    return (ch >= 'a' && ch <= 'z');
}

int is_digit(char ch) {
    return (ch >= '0' && ch <= '9');
}

int is_special(char ch) {
    return (!is_upper(ch) &&!is_lower(ch) &&!is_digit(ch));
}

int count_uppers(char *pass) {
    int count = 0;
    for (int i = 0; i < strlen(pass); i++) {
        if (is_upper(pass[i])) {
            count++;
        }
    }
    return count;
}

int count_lowers(char *pass) {
    int count = 0;
    for (int i = 0; i < strlen(pass); i++) {
        if (is_lower(pass[i])) {
            count++;
        }
    }
    return count;
}

int count_digits(char *pass) {
    int count = 0;
    for (int i = 0; i < strlen(pass); i++) {
        if (is_digit(pass[i])) {
            count++;
        }
    }
    return count;
}

int count_specials(char *pass) {
    int count = 0;
    for (int i = 0; i < strlen(pass); i++) {
        if (is_special(pass[i])) {
            count++;
        }
    }
    return count;
}

int main() {
    char pass[MAX_PASS_LEN];
    printf("Enter password: ");
    scanf("%s", pass);

    int upper_count = count_uppers(pass);
    int lower_count = count_lowers(pass);
    int digit_count = count_digits(pass);
    int special_count = count_specials(pass);

    int score = 0;
    if (strlen(pass) >= 8) {
        score += 1;
    }
    if (upper_count >= 1) {
        score += 1;
    }
    if (lower_count >= 1) {
        score += 1;
    }
    if (digit_count >= 1) {
        score += 1;
    }
    if (special_count >= 1) {
        score += 1;
    }

    printf("Password strength score: %d\n", score);

    return 0;
}