//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: all-encompassing
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MIN_LENGTH 8

int check_password_strength(char *password) {
    int lowercase = 0, uppercase = 0, digit = 0, special = 0;
    int length = strlen(password);

    for (int i = 0; i < length; ++i) {
        if (isalpha(password[i]) && islower(password[i])) {
            ++lowercase;
        }
        if (isalpha(password[i]) && isupper(password[i])) {
            ++uppercase;
        }
        if (isdigit(password[i])) {
            ++digit;
        }
        if (!isalnum(password[i])) {
            if (strchr("!@#$%^&*()_-+=`~{}|:;?<>,./[]", password[i])) {
                ++special;
            }
        }
    }

    return lowercase && uppercase && digit && special && length >= MIN_LENGTH;
}

int main() {
    char password[128];
    int strength;

    printf("Enter your password: ");
    scanf("%s", password);

    strength = check_password_strength(password);

    if (strength) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
        printf("Please make sure it has at least 1 lowercase character,\n");
        printf("at least 1 uppercase character,\n");
        printf("at least 1 digit character,\n");
        printf("at least 1 special character,\n");
        printf("and a minimum length of %d characters.\n", MIN_LENGTH);
    }

    return 0;
}