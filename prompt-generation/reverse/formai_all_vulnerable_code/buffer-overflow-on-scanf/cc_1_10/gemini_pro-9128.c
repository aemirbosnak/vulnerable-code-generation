//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: Linus Torvalds
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 256

typedef enum {
    WEAK,
    GOOD,
    STRONG,
    VERY_STRONG
} password_strength_t;

int check_length(const char *password) {
    if (strlen(password) < 8) {
        return WEAK;
    } else if (strlen(password) >= 8 && strlen(password) <= 12) {
        return GOOD;
    } else if (strlen(password) >= 13 && strlen(password) <= 16) {
        return STRONG;
    } else {
        return VERY_STRONG;
    }
}

int check_uppercase(const char *password) {
    int count = 0;
    for (int i = 0; password[i] != '\0'; i++) {
        if (isupper(password[i])) {
            count++;
        }
    }
    if (count >= 1) {
        return 1;
    } else {
        return 0;
    }
}

int check_lowercase(const char *password) {
    int count = 0;
    for (int i = 0; password[i] != '\0'; i++) {
        if (islower(password[i])) {
            count++;
        }
    }
    if (count >= 1) {
        return 1;
    } else {
        return 0;
    }
}

int check_digits(const char *password) {
    int count = 0;
    for (int i = 0; password[i] != '\0'; i++) {
        if (isdigit(password[i])) {
            count++;
        }
    }
    if (count >= 1) {
        return 1;
    } else {
        return 0;
    }
}

int check_symbols(const char *password) {
    int count = 0;
    for (int i = 0; password[i] != '\0'; i++) {
        if (!isalnum(password[i])) {
            count++;
        }
    }
    if (count >= 1) {
        return 1;
    } else {
        return 0;
    }
}

int check_password_strength(const char *password) {
    int length = check_length(password);
    int uppercase = check_uppercase(password);
    int lowercase = check_lowercase(password);
    int digits = check_digits(password);
    int symbols = check_symbols(password);

    int total = length + uppercase + lowercase + digits + symbols;

    if (total < 3) {
        return WEAK;
    } else if (total >= 3 && total < 5) {
        return GOOD;
    } else if (total >= 5 && total < 7) {
        return STRONG;
    } else {
        return VERY_STRONG;
    }
}

int main() {
    char password[MAX_STR_LEN];

    printf("Enter your password: ");
    scanf("%s", password);

    int strength = check_password_strength(password);

    switch (strength) {
        case WEAK:
            printf("Your password is weak.\n");
            break;
        case GOOD:
            printf("Your password is good.\n");
            break;
        case STRONG:
            printf("Your password is strong.\n");
            break;
        case VERY_STRONG:
            printf("Your password is very strong.\n");
            break;
    }

    return 0;
}