//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: scientific
#include<stdio.h>
#include<string.h>
#include<ctype.h>

void checkPasswordStrength(char*);

int main() {
    char password[20];
    printf("Enter your password: ");
    scanf("%s", password);

    checkPasswordStrength(password);

    return 0;
}

void checkPasswordStrength(char* password) {

    int length = strlen(password);
    int i;
    int digits = 0;
    int upperCase = 0;
    int lowerCase = 0;
    int specialChars = 0;
    int strength = 0;

    for (i = 0; i < length; i++) {

        if (isdigit(password[i])) {
            digits++;
        }

        if (isupper(password[i])) {
            upperCase++;
        }

        if (islower(password[i])) {
            lowerCase++;
        }

        if (password[i] == '~' || password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' ||
                password[i] == '%' || password[i] == '^' || password[i] == '&' || password[i] == '*' || password[i] == '('
                || password[i] == ')' || password[i] == '-' || password[i] == '_' || password[i] == '+' || password[i] == '=') {
            specialChars++;
        }

    }

    if (length < 8) {
        printf("Your password is Weak\n");
        printf("Recommended: Password should have atleast 8 characters\n");
        return;
    }

    if (digits < 1) {
        printf("Your password is Weak\n");
        printf("Recommended: Password should have atleast 1 digit\n");
        return;
    }

    if (upperCase < 1) {
        printf("Your password is Weak\n");
        printf("Recommended: Password should have atleast 1 uppercase character\n");
        return;
    }

    if (lowerCase < 1) {
        printf("Your password is Weak\n");
        printf("Recommended: Password should have atleast 1 lowercase character\n");
        return;
    }

    if (specialChars < 1) {
        printf("Your password is Weak\n");
        printf("Recommended: Password should have atleast 1 special character\n");
        return;
    }

    printf("Your password is Strong\n");
}