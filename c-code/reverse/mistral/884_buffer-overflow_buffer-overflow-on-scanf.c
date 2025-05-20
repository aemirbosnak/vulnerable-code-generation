#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 10

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int uppercase, lowercase, digit, special_char, length;
    int complexity = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);
    if (length < 8) {
        printf("Password too short.\n");
        return 1;
    }

    for (int i = 0; i < length; ++i) {
        if (isupper(password[i])) {
            ++uppercase;
        }
        if (islower(password[i])) {
            ++lowercase;
        }
        if (isdigit(password[i])) {
            ++digit;
        }
        if (!isalnum(password[i]) && password[i] != '_' && password[i] != '-') {
            ++special_char;
        }
    }

    if (uppercase > 0 && lowercase > 0 && digit > 0 && special_char > 0) {
        complexity = 1;
    }

    if (length > 12) {
        complexity += 2;
    }

    if (length < 16) {
        complexity += 1;
    }

    if (complexity < 3) {
        printf("Your password is weak.\n");
    } else if (complexity == 3) {
        printf("Your password is medium.\n");
    } else {
        printf("Your password is strong.\n");
    }

    return 0;
}
