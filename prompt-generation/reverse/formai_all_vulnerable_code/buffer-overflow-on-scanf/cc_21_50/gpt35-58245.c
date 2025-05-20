//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char password[101];
    printf("Enter your password: ");
    scanf("%s", password);

    int length = strlen(password);
    int uppercase = 0, lowercase = 0, digit = 0, special = 0;

    for (int i = 0; i < length; i++) {
        char ch = password[i];

        if (ch >= 'A' && ch <= 'Z') {
            uppercase++;
        } else if (ch >= 'a' && ch <= 'z') {
            lowercase++;
        } else if (ch >= '0' && ch <= '9') {
            digit++;
        } else {
            special++;
        }
    }

    int score = 0;
    char *comments[5] = {"Do you even know what a password is?", "Weak password, try again",
                         "Not bad, but could be better", "Pretty good, but not quite there yet",
                         "Amazing! Your password is rock solid"};

    if (length >= 10) {
        score += 3;
    } else if (length >= 8) {
        score += 2;
    } else {
        score += 1;
    }

    if (uppercase > 0 && lowercase > 0 && digit > 0 && special > 0) {
        score += 4;
    } else if (uppercase > 0 && lowercase > 0 && digit > 0) {
        score += 3;
    } else if (lowercase > 0 && digit > 0 && special > 0) {
        score += 2;
    } else if (lowercase > 0 && uppercase > 0) {
        score += 1;
    } else {
        score += 0;
    }

    printf("Password strength: %d/10\n", score);

    int index = score / 2;
    printf("Comments: %s", comments[index]);

    return 0; 
}