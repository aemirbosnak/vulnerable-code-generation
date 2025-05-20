#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char password[100];
    int length = 0, has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);
    if (length < 8) {
        printf("Password is too short. It should be at least 8 characters long.\n");
        return 1;
    }

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) has_upper = 1;
        if (islower(password[i])) has_lower = 1;
        if (isdigit(password[i])) has_digit = 1;
        if (!isalnum(password[i])) has_special = 1;
    }

    if (!has_upper) printf("Password should contain at least one uppercase letter.\n");
    if (!has_lower) printf("Password should contain at least one lowercase letter.\n");
    if (!has_digit) printf("Password should contain at least one digit.\n");
    if (!has_special) printf("Password should contain at least one special character.\n");

    if (has_upper && has_lower && has_digit && has_special && length >= 8) {
        printf("Strong password!\n");
    } else {
        printf("Weak password. Please improve it according to the guidelines.\n");
    }

    return 0;
}
