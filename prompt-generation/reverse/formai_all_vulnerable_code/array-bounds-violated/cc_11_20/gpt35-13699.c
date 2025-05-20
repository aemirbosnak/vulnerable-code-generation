//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: peaceful
/* 
Password Strength Checker
By: [Your Name]
Date: [Date]

This program checks the strength of a given password based on the following criteria:
- Minimum length of 8 characters
- At least 1 uppercase letter
- At least 1 lowercase letter
- At least 1 digit
- At least 1 special character (!,#,$,%,&,*,-,+,=,~,_,@)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// function to check if a character is a special character
int is_special(char c) {
    if (c == '!' || c == '#' || c == '$' || c == '%' || c == '&' || c == '*' || c == '-' || c == '+' || c == '=' || c == '~' || c == '_' || c == '@') {
        return 1;
    }
    return 0;
}

// main function
int main() {
    char password[100];
    printf("Enter your password: ");
    fgets(password, 100, stdin);

    // removing newline character from the end of the password
    if (password[strlen(password) - 1] == '\n') {
        password[strlen(password) - 1] = '\0';
    }

    int length = strlen(password);
    int upper = 0, lower = 0, digit = 0, special = 0;

    // checking each character of the password
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            upper = 1;
        } else if (islower(password[i])) {
            lower = 1;
        } else if (isdigit(password[i])) {
            digit = 1;
        } else if (is_special(password[i])) {
            special = 1;
        }
    }

    // checking strength of the password
    if (length < 8) {
        printf("Password is too short, it must be at least 8 characters long.\n");
    } else if (!upper) {
        printf("Password is too weak, it must contain at least 1 uppercase letter.\n");
    } else if (!lower) {
        printf("Password is too weak, it must contain at least 1 lowercase letter.\n");
    } else if (!digit) {
        printf("Password is too weak, it must contain at least 1 digit.\n");
    } else if (!special) {
        printf("Password is too weak, it must contain at least 1 special character.\n");
    } else {
        printf("Password is strong! Congratulations!\n");
    }

    return 0;
}