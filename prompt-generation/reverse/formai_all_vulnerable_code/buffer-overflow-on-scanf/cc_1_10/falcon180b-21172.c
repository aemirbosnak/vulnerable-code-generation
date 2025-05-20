//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100
#define MIN_LENGTH 8
#define MIN_LOWER 1
#define MIN_UPPER 1
#define MIN_NUMBER 1
#define MIN_SPECIAL 1

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

int count_lower(char *password) {
    int count = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (is_lower(password[i])) {
            count++;
        }
    }
    return count;
}

int count_upper(char *password) {
    int count = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (is_upper(password[i])) {
            count++;
        }
    }
    return count;
}

int count_number(char *password) {
    int count = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (is_number(password[i])) {
            count++;
        }
    }
    return count;
}

int count_special(char *password) {
    int count = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (is_special(password[i])) {
            count++;
        }
    }
    return count;
}

int check_password_strength(char *password) {
    int length = strlen(password);
    if (length < MIN_LENGTH) {
        printf("Password is too short.\n");
        return 0;
    } else if (length > MAX_LENGTH) {
        printf("Password is too long.\n");
        return 0;
    }

    int lower_count = count_lower(password);
    int upper_count = count_upper(password);
    int number_count = count_number(password);
    int special_count = count_special(password);

    if (lower_count < MIN_LOWER || upper_count < MIN_UPPER || number_count < MIN_NUMBER || special_count < MIN_SPECIAL) {
        printf("Password does not meet complexity requirements.\n");
        return 0;
    } else {
        printf("Password is strong.\n");
        return 1;
    }
}

int main() {
    char password[MAX_LENGTH];
    printf("Enter a password: ");
    scanf("%s", password);
    check_password_strength(password);
    return 0;
}