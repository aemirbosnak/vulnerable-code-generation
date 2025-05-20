//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 20
#define MIN_NUM 1
#define MAX_NUM 3
#define MIN_LOWER 1
#define MAX_LOWER 3
#define MIN_UPPER 1
#define MAX_UPPER 3
#define MIN_SPECIAL 1
#define MAX_SPECIAL 3

int is_lower(char c) {
    return (c >= 'a' && c <= 'z');
}

int is_upper(char c) {
    return (c >= 'A' && c <= 'Z');
}

int is_number(char c) {
    return (c >= '0' && c <= '9');
}

int is_special(char c) {
    return (!is_lower(c) &&!is_upper(c) &&!is_number(c));
}

int is_valid(char *password) {
    int length = strlen(password);
    int num_lower = 0;
    int num_upper = 0;
    int num_number = 0;
    int num_special = 0;

    for (int i = 0; i < length; i++) {
        if (is_lower(password[i])) {
            num_lower++;
        }
        else if (is_upper(password[i])) {
            num_upper++;
        }
        else if (is_number(password[i])) {
            num_number++;
        }
        else if (is_special(password[i])) {
            num_special++;
        }
    }

    return (length >= MIN_LENGTH && length <= MAX_LENGTH &&
            num_lower >= MIN_LOWER && num_lower <= MAX_LOWER &&
            num_upper >= MIN_UPPER && num_upper <= MAX_UPPER &&
            num_number >= MIN_NUM && num_number <= MAX_NUM &&
            num_special >= MIN_SPECIAL && num_special <= MAX_SPECIAL);
}

int main() {
    char password[MAX_LENGTH + 1];
    int valid = 0;

    printf("Enter a password: ");
    scanf("%s", password);

    valid = is_valid(password);

    if (valid) {
        printf("Password is strong.\n");
    }
    else {
        printf("Password is weak.\n");
    }

    return 0;
}