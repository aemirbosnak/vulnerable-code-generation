//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASS_LEN 30
#define MIN_PASS_LEN 8
#define MIN_LOWER 1
#define MIN_UPPER 1
#define MIN_NUM 1
#define MIN_SPEC 1

void check_password_strength(char* password) {
    int len = strlen(password);
    int lower = 0, upper = 0, num = 0, spec = 0;

    for (int i = 0; i < len; i++) {
        if (isdigit(password[i])) {
            num++;
        } else if (isalpha(password[i])) {
            if (isupper(password[i])) {
                upper++;
            } else {
                lower++;
            }
        } else if (isalnum(password[i])) {
            spec++;
        }
    }

    if (len < MIN_PASS_LEN) {
        printf("Password too short\n");
        return;
    } else if (lower < MIN_LOWER) {
        printf("Password must contain at least %d lowercase letter(s)\n", MIN_LOWER);
        return;
    } else if (upper < MIN_UPPER) {
        printf("Password must contain at least %d uppercase letter(s)\n", MIN_UPPER);
        return;
    } else if (num < MIN_NUM) {
        printf("Password must contain at least %d number(s)\n", MIN_NUM);
        return;
    } else if (spec < MIN_SPEC) {
        printf("Password must contain at least %d special character(s)\n", MIN_SPEC);
        return;
    } else {
        printf("Password is strong\n");
    }
}

int main() {
    char password[MAX_PASS_LEN];
    printf("Enter your password: ");
    scanf("%s", password);
    check_password_strength(password);
    return 0;
}