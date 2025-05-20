#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MIN_LENGTH 8

int main() {
    char password[100];
    int has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0;
    int length;

    printf("Enter your password: ");
    scanf("%s", password);
    length = strlen(password);

    if (length < MIN_LENGTH) {
        printf("Password is too short. It must be at least %d characters long.\n", MIN_LENGTH);
        return 1;
    }

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) has_upper = 1;
        if (islower(password[i])) has_lower = 1;
        if (isdigit(password[i])) has_digit = 1;
        if (!isalnum(password[i])) has_special = 1;
    }

    if (has_upper && has_lower && has_digit && has_special) {
        printf("Your password is strong!\n");
    } else {
        printf("Weak password! Ensure it contains uppercase, lowercase, digits, and special characters.\n");
    }

    return 0;
}
