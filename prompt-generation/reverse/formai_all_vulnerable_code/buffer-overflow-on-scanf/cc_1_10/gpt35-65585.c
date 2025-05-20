//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum {
    WEAK,
    MEDIUM,
    STRONG
} strength;

strength password_strength(char password[]) {
    int n = strlen(password);
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;
    int has_special_character = 0;

    for (int i=0; i<n; i++) {
        char c = password[i];
        if (isupper(c)) {
            has_uppercase = 1;
        } else if (islower(c)) {
            has_lowercase = 1;
        } else if (isdigit(c)) {
            has_number = 1;
        } else {
            has_special_character = 1;
        }
    }

    if (n < 8 || n > 16) {
        return WEAK;
    } else if (!has_uppercase || !has_lowercase || !has_number || !has_special_character) {
        return MEDIUM;
    } else {
        return STRONG;
    }
}

int main() {
    // get password from user
    char password[100];
    printf("Enter a password: ");
    scanf("%s", password);

    // check password strength
    strength s = password_strength(password);

    // print password strength level
    switch(s) {
        case WEAK:
            printf("Password is weak\n");
            break;
        case MEDIUM:
            printf("Password is medium\n");
            break;
        case STRONG:
            printf("Password is strong\n");
            break;
    }

    return 0;
}