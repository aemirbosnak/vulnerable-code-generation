//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int length, uppercase, lowercase, number, special, score = 0;

    printf("Enter a password: ");
    scanf("%s", password);

    length = strlen(password);
    uppercase = lowercase = number = special = 0;

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase++;
        } else if (islower(password[i])) {
            lowercase++;
        } else if (isdigit(password[i])) {
            number++;
        } else {
            special++;
        }
    }

    if (length >= 10) {
        score += 30;
    } else if (length >= 8) {
        score += 20;
    } else if (length >= 6) {
        score += 10;
    }

    if (uppercase >= 2) {
        score += 10;
    }
    if (lowercase >= 2) {
        score += 10;
    }
    if (number >= 2) {
        score += 10;
    }
    if (special >= 2) {
        score += 10;
    }

    printf("Password strength score: %d out of 100\n", score);

    if (score >= 80) {
        printf("Password strength: Very Strong\n");
    } else if (score >= 60) {
        printf("Password strength: Strong\n");
    } else if (score >= 40) {
        printf("Password strength: Fair\n");
    } else if (score >= 20) {
        printf("Password strength: Weak\n");
    } else {
        printf("Password strength: Very Weak\n");
    }

    return 0;
}