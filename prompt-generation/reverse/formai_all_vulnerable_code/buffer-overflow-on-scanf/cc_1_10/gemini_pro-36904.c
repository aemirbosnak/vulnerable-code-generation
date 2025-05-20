//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Password strength constants
#define WEAK 0
#define OK 1
#define STRONG 2

// Password complexity constants
#define NO_UPPERCASE 0
#define NO_LOWERCASE 1
#define NO_DIGITS 2
#define NO_SYMBOLS 3

// Password complexity names
char *complexity_names[] = {
    "No uppercase letters",
    "No lowercase letters",
    "No digits",
    "No symbols"
};

// Password complexity weight calculation function
int complexity_weight(char *password) {
    int weight = 0;
    int length = strlen(password);

    for (int i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            weight += 1;
        } else if (password[i] >= 'a' && password[i] <= 'z') {
            weight += 1;
        } else if (password[i] >= '0' && password[i] <= '9') {
            weight += 1;
        } else {
            weight += 2;
        }
    }

    return weight;
}

// Password strength calculation function
int password_strength(char *password) {
    int complexity = complexity_weight(password);

    if (complexity < 5) {
        return WEAK;
    } else if (complexity >= 5 && complexity < 10) {
        return OK;
    } else {
        return STRONG;
    }
}

// Password complexity check function
int password_complexity_check(char *password) {
    int complexity_flags = 0;
    int length = strlen(password);

    for (int i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            complexity_flags &= ~(1 << NO_UPPERCASE);
        } else if (password[i] >= 'a' && password[i] <= 'z') {
            complexity_flags &= ~(1 << NO_LOWERCASE);
        } else if (password[i] >= '0' && password[i] <= '9') {
            complexity_flags &= ~(1 << NO_DIGITS);
        } else {
            complexity_flags &= ~(1 << NO_SYMBOLS);
        }
    }

    return complexity_flags;
}

// Password strength report function
void password_strength_report(char *password) {
    int strength = password_strength(password);
    int complexity_flags = password_complexity_check(password);

    printf("Password strength: ");
    switch (strength) {
        case WEAK:
            printf("Weak\n");
            break;
        case OK:
            printf("OK\n");
            break;
        case STRONG:
            printf("Strong\n");
            break;
    }

    printf("Password complexity:\n");
    for (int i = 0; i < 4; i++) {
        if (complexity_flags & (1 << i)) {
            printf("- %s\n", complexity_names[i]);
        }
    }
}

// Main function
int main() {
    // Get the password from the user
    char password[100];
    printf("Enter your password: ");
    scanf("%s", password);

    // Check the password strength and report the result
    password_strength_report(password);

    return 0;
}