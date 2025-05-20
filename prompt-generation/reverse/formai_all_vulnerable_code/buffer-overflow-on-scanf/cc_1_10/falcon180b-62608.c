//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: calm
/*
 * This program checks the strength of a given password. * It uses a set of rules to determine the password's strength. * The rules are as follows:
 * 1. The password must be at least 8 characters long. * 2. The password must contain at least one uppercase letter. * 3. The password must contain at least one lowercase letter. * 4. The password must contain at least one digit. * 5. The password must contain at least one special character. * The program returns a message indicating the strength of the password. */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define PASSWORD_LENGTH_MIN 8
#define PASSWORD_WEAK 0
#define PASSWORD_MEDIUM 1
#define PASSWORD_STRONG 2

int is_valid_password(char *password);
int check_password_strength(char *password);

int main() {
    char password[100];
    printf("Enter your password: ");
    scanf("%s", password);
    int strength = check_password_strength(password);
    switch(strength) {
        case PASSWORD_WEAK:
            printf("Your password is weak.\n");
            break;
        case PASSWORD_MEDIUM:
            printf("Your password is medium.\n");
            break;
        case PASSWORD_STRONG:
            printf("Your password is strong.\n");
            break;
        default:
            printf("Invalid password.\n");
            break;
    }
    return 0;
}

int is_valid_password(char *password) {
    int length = strlen(password);
    if(length < PASSWORD_LENGTH_MIN) {
        return 0;
    }
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_digit = 0;
    int has_special = 0;
    for(int i=0; i<length; i++) {
        if(isupper(password[i])) {
            has_uppercase = 1;
        } else if(islower(password[i])) {
            has_lowercase = 1;
        } else if(isdigit(password[i])) {
            has_digit = 1;
        } else {
            has_special = 1;
        }
    }
    if(has_uppercase && has_lowercase && has_digit && has_special) {
        return 1;
    } else {
        return 0;
    }
}

int check_password_strength(char *password) {
    if(!is_valid_password(password)) {
        return PASSWORD_WEAK;
    }
    int length = strlen(password);
    if(length >= 12) {
        return PASSWORD_STRONG;
    } else {
        return PASSWORD_MEDIUM;
    }
}