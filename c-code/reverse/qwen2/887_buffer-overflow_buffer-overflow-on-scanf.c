#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MIN_LENGTH 8

void checkPasswordStrength(char *password) {
    int hasLower = 0, hasUpper = 0, hasDigit = 0, hasSpecial = 0;
    int length = strlen(password);

    if (length < MIN_LENGTH) {
        printf("Weak: Password is too short. It should be at least %d characters long.\n", MIN_LENGTH);
        return;
    }

    for (int i = 0; i < length; i++) {
        if (islower(password[i])) hasLower = 1;
        if (isupper(password[i])) hasUpper = 1;
        if (isdigit(password[i])) hasDigit = 1;
        if (!isalnum(password[i])) hasSpecial = 1;
    }

    if (hasLower && hasUpper && hasDigit && hasSpecial) {
        printf("Strong: Password meets all criteria.\n");
    } else {
        printf("Medium: Password meets some criteria but could be stronger.\n");
    }
}

int main() {
    char password[256];
    printf("Enter your password: ");
    scanf("%s", password);
    checkPasswordStrength(password);
    return 0;
}
