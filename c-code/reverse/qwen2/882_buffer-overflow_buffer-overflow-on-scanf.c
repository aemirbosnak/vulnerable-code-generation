#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <ctype.h>

int main() {
    char password[10];
    int has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0;
    printf("Enter your password: ");
    scanf("%s", password);
    for (int i = 0; password[i] != '\0'; i++) {
        if (isupper(password[i])) has_upper = 1;
        if (islower(password[i])) has_lower = 1;
        if (isdigit(password[i])) has_digit = 1;
        if (!isalnum(password[i])) has_special = 1;
    }
    if (strlen(password) >= 8 && has_upper && has_lower && has_digit && has_special) {
        printf("Strong password!\n");
    } else {
        printf("Weak password!\n");
    }
    return 0;
}
