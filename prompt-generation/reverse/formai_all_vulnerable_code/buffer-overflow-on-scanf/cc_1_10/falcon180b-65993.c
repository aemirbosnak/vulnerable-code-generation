//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int is_valid_password(char *password);
int is_between(int num, int min, int max);
int has_uppercase(char *password);
int has_lowercase(char *password);
int has_number(char *password);
int has_special_char(char *password);

int main() {
    char password[MAX_LENGTH];
    int length;
    int strength;

    printf("Enter your password: ");
    scanf("%s", password);
    length = strlen(password);

    strength = is_valid_password(password);

    if (strength == 0) {
        printf("Password is not strong enough.\n");
    } else if (strength == 1) {
        printf("Password is weak.\n");
    } else if (strength == 2) {
        printf("Password is moderate.\n");
    } else {
        printf("Password is strong.\n");
    }

    return 0;
}

int is_valid_password(char *password) {
    if (strlen(password) < 8) {
        return 0;
    }

    if (!has_uppercase(password)) {
        return 0;
    }

    if (!has_lowercase(password)) {
        return 0;
    }

    if (!has_number(password)) {
        return 0;
    }

    if (!has_special_char(password)) {
        return 0;
    }

    return 1;
}

int is_between(int num, int min, int max) {
    if (num >= min && num <= max) {
        return 1;
    }

    return 0;
}

int has_uppercase(char *password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            return 1;
        }
    }

    return 0;
}

int has_lowercase(char *password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            return 1;
        }
    }

    return 0;
}

int has_number(char *password) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            return 1;
        }
    }

    return 0;
}

int has_special_char(char *password) {
    int i;
    char special_chars[] = "!@#$%^&*()_+-=[]{}|;':\",.<>/?";
    for (i = 0; i < strlen(password); i++) {
        if (strchr(special_chars, password[i])!= NULL) {
            return 1;
        }
    }

    return 0;
}