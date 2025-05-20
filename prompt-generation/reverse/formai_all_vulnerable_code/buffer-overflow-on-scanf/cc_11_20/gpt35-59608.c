//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: happy
#include <stdio.h>
#include <string.h>

int main() {
    char password[50];
    int length, upper, lower, digit, special, i;
    int score = 0;

    printf("Enter your password: ");
    scanf("%s", &password);
    length = strlen(password);

    for (i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            upper++;
        }
        else if (password[i] >= 'a' && password[i] <= 'z') {
            lower++;
        }
        else if (password[i] >= '0' && password[i] <= '9') {
            digit++;
        }
        else {
            special++;
        }
    }

    if (length >= 8) {
        score++;
    }
    if (upper > 0 && lower > 0) {
        score++;
    }
    if (digit > 0) {
        score++;
    }
    if (special > 0) {
        score++;
    }

    printf("Your password score is %d out of 4.\n", score);

    if (score == 4) {
        printf("Congratulations! Your password is very strong.\n");
    }
    else if (score >= 2) {
        printf("Your password is moderate. Please try to make it stronger.\n");
    }
    else {
        printf("Your password is weak. Please try again with a stronger password.\n");
    }

    return 0;
}