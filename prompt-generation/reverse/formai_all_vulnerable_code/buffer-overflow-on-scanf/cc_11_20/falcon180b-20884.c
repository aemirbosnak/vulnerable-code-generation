//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: Donald Knuth
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char password[100];
    int length;
    printf("Enter your password: ");
    scanf("%s", password);
    length = strlen(password);

    int hasUppercase = 0, hasLowercase = 0, hasNumber = 0, hasSpecialChar = 0;
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            hasUppercase = 1;
        } else if (islower(password[i])) {
            hasLowercase = 1;
        } else if (isdigit(password[i])) {
            hasNumber = 1;
        } else if (!isalnum(password[i])) {
            hasSpecialChar = 1;
        }
    }

    int score = 0;
    if (length >= 8) {
        score += 1;
    }
    if (hasUppercase) {
        score += 1;
    }
    if (hasLowercase) {
        score += 1;
    }
    if (hasNumber) {
        score += 1;
    }
    if (hasSpecialChar) {
        score += 1;
    }

    switch (score) {
        case 5:
            printf("Password is very strong.\n");
            break;
        case 4:
            printf("Password is strong.\n");
            break;
        case 3:
            printf("Password is moderate.\n");
            break;
        case 2:
            printf("Password is weak.\n");
            break;
        case 1:
            printf("Password is very weak.\n");
            break;
        default:
            printf("Invalid password.\n");
            break;
    }
    return 0;
}