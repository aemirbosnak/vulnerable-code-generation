//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {

    char password[100];
    int len, i, hasLower = 0, hasUpper = 0, hasDigit = 0, hasSpecial = 0, strengthScore = 0;
    printf("Enter your Password:\t");
    scanf("%s", password);

    len = strlen(password);

    for (i = 0; i < len; i++) {
        if (islower(password[i]))
            hasLower++;
        else if (isupper(password[i]))
            hasUpper++;
        else if (isdigit(password[i]))
            hasDigit++;
        else
            hasSpecial++;
    }

    if (len >= 8 && hasLower && hasUpper && hasDigit && hasSpecial) {
        strengthScore += 200;
    }
    else if (len >= 8 && ((hasLower && hasUpper && hasDigit) || (hasLower && hasUpper && hasSpecial) || (hasLower && hasDigit && hasSpecial) || (hasUpper && hasDigit && hasSpecial)))
        strengthScore += 150;
    else if (len >= 8 && (hasLower || hasUpper) && hasDigit)
        strengthScore += 125;
    else if (len >= 8 && (hasLower || hasUpper) && hasSpecial)
        strengthScore += 100;
    else if (len >= 8 && hasLower && hasUpper)
        strengthScore += 75;
    else if (len >= 8 && (hasLower || hasUpper || hasDigit || hasSpecial))
        strengthScore += 50;
    else if (len >= 6)
        strengthScore += 25;

    printf("Your password's strength score is %d\n", strengthScore);

    if (strengthScore >= 200) {
        printf("Your password is considered STRONG\n");
    }
    else if (strengthScore >= 100) {
        printf("Your password is considered MODERATE\n");
    }
    else {
        printf("Your password is considered WEAK\n");
    }

    return 0;
}