//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 32
#define NUM_PASSWORDS 5

int is_valid_password(char *password) {
    int length = strlen(password);
    if (length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH) {
        return 0;
    }
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;
    int has_special = 0;
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
        } else if (isalnum(c)) {
            has_special = 1;
        }
    }
    if (!has_uppercase ||!has_lowercase ||!has_number ||!has_special) {
        return 0;
    }
    return 1;
}

int main() {
    char passwords[NUM_PASSWORDS][MAX_PASSWORD_LENGTH];
    for (int i = 0; i < NUM_PASSWORDS; i++) {
        printf("Enter password %d: ", i + 1);
        scanf("%s", passwords[i]);
    }
    int num_weak_passwords = 0;
    for (int i = 0; i < NUM_PASSWORDS; i++) {
        if (!is_valid_password(passwords[i])) {
            printf("Password %d is weak.\n", i + 1);
            num_weak_passwords++;
        }
    }
    if (num_weak_passwords == 0) {
        printf("All passwords are strong.\n");
    } else {
        printf("%d passwords are weak.\n", num_weak_passwords);
    }
    return 0;
}