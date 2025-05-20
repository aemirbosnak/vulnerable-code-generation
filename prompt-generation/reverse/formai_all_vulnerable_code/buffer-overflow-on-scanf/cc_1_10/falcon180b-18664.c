//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: complex
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define LENGTH 8 // Minimum password length
#define UPPER 1 // Upper case letter
#define LOWER 2 // Lower case letter
#define NUMBER 4 // Number
#define SPECIAL 8 // Special character

int main() {
    char password[LENGTH + 1];
    int score = 0;
    int i;

    printf("Enter your password: ");
    scanf("%s", password);

    if (strlen(password) < LENGTH) {
        printf("Password is too short.\n");
        return 1;
    }

    for (i = 0; i < strlen(password); i++) {
        if (isalpha(password[i])) {
            if (isupper(password[i])) {
                score += UPPER;
            } else if (islower(password[i])) {
                score += LOWER;
            }
        } else if (isdigit(password[i])) {
            score += NUMBER;
        } else {
            score += SPECIAL;
        }
    }

    if (score < 3) {
        printf("Password is too weak.\n");
    } else if (score < 6) {
        printf("Password is weak.\n");
    } else if (score < 9) {
        printf("Password is moderate.\n");
    } else {
        printf("Password is strong.\n");
    }

    return 0;
}