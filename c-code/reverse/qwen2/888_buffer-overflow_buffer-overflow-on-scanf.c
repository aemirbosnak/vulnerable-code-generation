#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <ctype.h>

void check_password_strength(char *password) {
    int length = 0;
    int has_uppercase = 0, has_lowercase = 0, has_digit = 0, has_special = 0;

    while (password[length] != '\0') {
        if (isupper(password[length])) has_uppercase = 1;
        if (islower(password[length])) has_lowercase = 1;
        if (isdigit(password[length])) has_digit = 1;
        if (!isalnum(password[length])) has_special = 1;
        length++;
    }

    printf("Password length: %d\n", length);
    printf("Contains uppercase: %s\n", has_uppercase ? "Yes" : "No");
    printf("Contains lowercase: %s\n", has_lowercase ? "Yes" : "No");
    printf("Contains digits: %s\n", has_digit ? "Yes" : "No");
    printf("Contains special characters: %s\n", has_special ? "Yes" : "No");

    if (length >= 8 && has_uppercase && has_lowercase && has_digit && has_special) {
        printf("Strong password!\n");
    } else {
        printf("Weak password!\n");
    }
}

int main() {
    char password[5];

    printf("Enter your password: ");
    scanf("%s", password);

    check_password_strength(password);

    return 0;
}
