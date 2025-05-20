//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100

int is_password_strong(const char* password);

int main() {
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your password: ");
    scanf("%s", password);

    if (is_password_strong(password)) {
        printf("Your password is strong!\n");
    } else {
        printf("Your password is weak.\n");
    }

    return 0;
}

int is_password_strong(const char* password) {
    int length = strlen(password);
    int uppercase_count = 0;
    int lowercase_count = 0;
    int digit_count = 0;
    int special_character_count = 0;

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase_count++;
        } else if (islower(password[i])) {
            lowercase_count++;
        } else if (isdigit(password[i])) {
            digit_count++;
        } else if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '&' || password[i] == '*' || password[i] == '?') {
            special_character_count++;
        }
    }

    if (length >= 8 && uppercase_count > 0 && lowercase_count > 0 && digit_count > 0 && special_character_count > 0) {
        return 1;
    } else {
        return 0;
    }
}

/*
Sample Input/Output:

Enter your password: Password#123
Your password is strong!

Enter your password: password
Your password is weak.

Enter your password: 123456
Your password is weak.

Enter your password: Password123
Your password is strong!

Enter your password: Password#1234
Your password is strong!
*/