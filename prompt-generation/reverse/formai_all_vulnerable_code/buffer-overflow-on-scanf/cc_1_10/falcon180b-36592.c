//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: ultraprecise
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 20
#define UPPER 'A'
#define LOWER 'a'
#define NUMBER '0'
#define SPECIAL_CHAR '!'

int is_valid_password(char *password);

int main() {
    char password[MAX_LENGTH + 1];
    int length;
    int i;

    printf("Enter a password (between %d and %d characters): ", MIN_LENGTH, MAX_LENGTH);
    scanf("%s", password);
    length = strlen(password);

    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Invalid password length.\n");
        exit(1);
    }

    if (!is_valid_password(password)) {
        printf("Weak password.\n");
        exit(1);
    }

    printf("Password is strong.\n");
    return 0;
}

int is_valid_password(char *password) {
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;
    int has_special_char = 0;
    int i;

    for (i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
        } else if (islower(password[i])) {
            has_lowercase = 1;
        } else if (isdigit(password[i])) {
            has_number = 1;
        } else if (password[i] == SPECIAL_CHAR) {
            has_special_char = 1;
        }
    }

    if (!has_uppercase ||!has_lowercase ||!has_number ||!has_special_char) {
        return 0;
    }

    return 1;
}