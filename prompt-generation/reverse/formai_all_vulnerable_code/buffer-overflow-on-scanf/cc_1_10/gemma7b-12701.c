//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: lively
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PASSWORD_LENGTH 20

void check_password(char *password) {
    int strength = 0;
    int has_upper = 0;
    int has_number = 0;
    int has_symbol = 0;

    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            has_upper = 1;
        } else if (password[i] >= '0' && password[i] <= '9') {
            has_number = 1;
        } else if (password[i] >= '!' && password[i] <= '~') {
            has_symbol = 1;
        }
    }

    if (has_upper && has_number && has_symbol) {
        strength = 5;
    } else if (has_upper || has_number || has_symbol) {
        strength = 3;
    } else {
        strength = 1;
    }

    switch (strength) {
        case 5:
            printf("Your password is very strong!\n");
            break;
        case 3:
            printf("Your password is moderate.\n");
            break;
        case 1:
            printf("Your password is weak. Please choose a stronger one.\n");
            break;
    }
}

int main() {
    char password[PASSWORD_LENGTH];

    printf("Enter your password: ");
    scanf("%s", password);

    check_password(password);

    return 0;
}