//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: enthusiastic
// C Password Strength Checker Example Program
// By John Doe

#include <stdio.h>
#include <string.h>

int main() {
    char password[100];
    int passwordLength;
    int lowerCase = 0, upperCase = 0, numbers = 0, specialChars = 0;

    printf("Enter a password: ");
    scanf("%s", password);

    passwordLength = strlen(password);

    for (int i = 0; i < passwordLength; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            lowerCase++;
        } else if (password[i] >= 'A' && password[i] <= 'Z') {
            upperCase++;
        } else if (password[i] >= '0' && password[i] <= '9') {
            numbers++;
        } else if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '^' || password[i] == '&' || password[i] == '*' || password[i] == '(' || password[i] == ')' || password[i] == '-' || password[i] == '+' || password[i] == '=' || password[i] == '{' || password[i] == '}' || password[i] == '[' || password[i] == ']' || password[i] == '|' || password[i] == ':' || password[i] == ';' || password[i] == '\'' || password[i] == '"' || password[i] == '<' || password[i] == '>' || password[i] == ',' || password[i] == '.' || password[i] == '?' || password[i] == '/') {
            specialChars++;
        }
    }

    if (passwordLength >= 8) {
        printf("Password is strong!\n");
    } else {
        printf("Password is weak!\n");
    }

    if (lowerCase > 0) {
        printf("Password has lower case letters!\n");
    } else {
        printf("Password does not have lower case letters!\n");
    }

    if (upperCase > 0) {
        printf("Password has upper case letters!\n");
    } else {
        printf("Password does not have upper case letters!\n");
    }

    if (numbers > 0) {
        printf("Password has numbers!\n");
    } else {
        printf("Password does not have numbers!\n");
    }

    if (specialChars > 0) {
        printf("Password has special characters!\n");
    } else {
        printf("Password does not have special characters!\n");
    }

    return 0;
}