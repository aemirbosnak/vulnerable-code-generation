#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter your password: ");
    scanf("%s", password);

    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0, length = strlen(password);

    for (int i = 0; i < length; ++i) {
        if (isupper(password[i])) {
            hasUpper = 1;
        }
        if (islower(password[i])) {
            hasLower = 1;
        }
        if (isdigit(password[i])) {
            hasDigit = 1;
        }
        if (!isalnum(password[i]) && !isascii(password[i])) {
            hasSpecial = 1;
        }
    }

    if (length < 8 || !hasUpper || !hasLower || !hasDigit || !hasSpecial) {
        printf("Weak password\n");
    } else {
        printf("Strong password\n");
    }

    return 0;
}
