//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: minimalist
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MIN_LEN 8
#define MAX_LEN 20

int main() {
    char password[MAX_LEN + 1];
    int len, i;
    int has_lower = 0, has_upper = 0, has_number = 0, has_special = 0, has_invalid = 0;

    printf("Please enter your password: ");
    scanf("%s", password);

    len = strlen(password);

    if (len < MIN_LEN || len > MAX_LEN) {
        printf("Password length must be between %d and %d characters\n", MIN_LEN, MAX_LEN);
        return 1;
    }

    for (i = 0; password[i]; i++) {
        if (isspace(password[i])) {
            printf("Password contains invalid character: space\n");
            has_invalid = 1;
        }
        else if (islower(password[i])) {
            has_lower = 1;
        }
        else if (isupper(password[i])) {
            has_upper = 1;
        }
        else if (isdigit(password[i])) {
            has_number = 1;
        }
        else {
            has_special = 1;
        }
    }

    if (!has_lower) {
        printf("Password must contain at least one lowercase letter\n");
        has_invalid = 1;
    }
    if (!has_upper) {
        printf("Password must contain at least one uppercase letter\n");
        has_invalid = 1;
    }
    if (!has_number) {
        printf("Password must contain at least one number\n");
        has_invalid = 1;
    }
    if (!has_special) {
        printf("Password must contain at least one special character\n");
        has_invalid = 1;
    }

    if (!has_invalid) {
        printf("Password is strong. Good job!\n");
        return 0;
    }
    else {
        return 1;
    }
}