//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LENGTH 100

int is_valid_password(char *password) {
    int length = strlen(password);

    // Check for length
    if (length < 8 || length > MAX_LENGTH) {
        printf("Password must be between 8 and %d characters long.\n", MAX_LENGTH);
        return 0;
    }

    // Check for complexity
    int has_uppercase = 0, has_lowercase = 0, has_number = 0, has_special = 0;

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
        } else if (islower(password[i])) {
            has_lowercase = 1;
        } else if (isdigit(password[i])) {
            has_number = 1;
        } else if (!isalnum(password[i])) {
            has_special = 1;
        }
    }

    if (!has_uppercase ||!has_lowercase ||!has_number ||!has_special) {
        printf("Password must contain at least one uppercase letter, one lowercase letter, one number, and one special character.\n");
        return 0;
    }

    return 1;
}

int main() {
    char password[MAX_LENGTH];

    printf("Enter password: ");
    scanf("%s", password);

    if (is_valid_password(password)) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }

    return 0;
}