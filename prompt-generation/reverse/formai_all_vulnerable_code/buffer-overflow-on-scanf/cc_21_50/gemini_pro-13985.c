//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char password[101];
    int strength = 0;

    printf("Dearest user, please enter your password: ");
    scanf("%s", password);

    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            strength += 2;
        } else if (password[i] >= 'a' && password[i] <= 'z') {
            strength += 1;
        } else if (password[i] >= '0' && password[i] <= '9') {
            strength += 1;
        } else {
            strength += 3;
        }
    }

    if (strlen(password) < 8) {
        strength -= 2;
    }

    if (strength < 0) {
        strength = 0;
    } else if (strength > 10) {
        strength = 10;
    }

    switch (strength) {
        case 0:
            printf("Your password is extremely weak. Please consider making it stronger.\n");
            break;
        case 1:
        case 2:
            printf("Your password is weak. Please consider making it stronger.\n");
            break;
        case 3:
        case 4:
            printf("Your password is moderate. It could be stronger, but it's not too bad.\n");
            break;
        case 5:
        case 6:
            printf("Your password is strong. Good job!\n");
            break;
        case 7:
        case 8:
            printf("Your password is very strong. You're doing great!\n");
            break;
        case 9:
        case 10:
            printf("Your password is extremely strong. You're a password security master!\n");
            break;
        default:
            printf("I'm not sure how strong your password is. Please try again.\n");
            break;
    }

    return 0;
}