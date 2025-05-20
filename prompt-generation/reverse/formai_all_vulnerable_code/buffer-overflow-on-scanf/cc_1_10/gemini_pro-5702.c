//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 128

typedef enum {
    WEAK,
    MEDIUM,
    STRONG
} StrengthLevel;

int check_length(char *password) {
    int length = strlen(password);
    if (length < MIN_LENGTH) {
        return WEAK;
    } else if (length >= MIN_LENGTH && length <= MAX_LENGTH) {
        return MEDIUM;
    } else {
        return STRONG;
    }
}

int check_variety(char *password) {
    int variety = 0;
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            variety++;
        } else if (isupper(password[i])) {
            variety++;
        } else if (islower(password[i])) {
            variety++;
        } else if (ispunct(password[i])) {
            variety++;
        }
    }
    if (variety < 3) {
        return WEAK;
    } else if (variety >= 3 && variety <= 4) {
        return MEDIUM;
    } else {
        return STRONG;
    }
}

int check_strength(char *password) {
    int length = check_length(password);
    int variety = check_variety(password);
    if (length == WEAK || variety == WEAK) {
        return WEAK;
    } else if (length == MEDIUM && variety == MEDIUM) {
        return MEDIUM;
    } else {
        return STRONG;
    }
}

void print_strength(int strength) {
    switch (strength) {
        case WEAK:
            printf("Weak\n");
            break;
        case MEDIUM:
            printf("Medium\n");
            break;
        case STRONG:
            printf("Strong\n");
            break;
    }
}

int main() {
    char password[MAX_LENGTH];
    printf("Enter your password: ");
    scanf("%s", password);
    int strength = check_strength(password);
    printf("Your password is: ");
    print_strength(strength);
    return 0;
}