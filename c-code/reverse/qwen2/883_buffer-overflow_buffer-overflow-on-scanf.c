#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char password[100];
    int has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0;
    int length = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    for (int i = 0; password[i] != '\0'; i++) {
        if (isupper(password[i])) has_upper = 1;
        if (islower(password[i])) has_lower = 1;
        if (isdigit(password[i])) has_digit = 1;
        if (!isalnum(password[i])) has_special = 1;
        length++;
    }

    printf("Password length: %d\n", length);
    printf("Contains uppercase letter: %s\n", has_upper ? "Yes" : "No");
    printf("Contains lowercase letter: %s\n", has_lower ? "Yes" : "No");
    printf("Contains digit: %s\n", has_digit ? "Yes" : "No");
    printf("Contains special character: %s\n", has_special ? "Yes" : "No");

    if (length >= 8 && has_upper && has_lower && has_digit && has_special) {
        printf("Strong password!\n");
    } else {
        printf("Weak password! Consider adding more complexity.\n");
    }

    return 0;
}
