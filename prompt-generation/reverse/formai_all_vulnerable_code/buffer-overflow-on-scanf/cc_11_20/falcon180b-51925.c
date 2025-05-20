//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: irregular
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100

int main() {
    char password[MAX_LENGTH];
    printf("Enter your password: ");
    scanf("%s", password);

    int length = strlen(password);
    if (length < 8) {
        printf("Password is too short.\n");
        return 1;
    }

    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_digit = 0;
    int has_special = 0;

    for (int i = 0; i < length; i++) {
        char c = tolower(password[i]);
        if (isalpha(c)) {
            has_uppercase = has_uppercase || isupper(c);
            has_lowercase = has_lowercase || islower(c);
        } else if (isdigit(c)) {
            has_digit = 1;
        } else {
            has_special = 1;
        }
    }

    if (!has_uppercase) {
        printf("Password must contain at least one uppercase letter.\n");
        return 1;
    }

    if (!has_lowercase) {
        printf("Password must contain at least one lowercase letter.\n");
        return 1;
    }

    if (!has_digit) {
        printf("Password must contain at least one digit.\n");
        return 1;
    }

    if (!has_special) {
        printf("Password must contain at least one special character.\n");
        return 1;
    }

    printf("Password is strong.\n");
    return 0;
}