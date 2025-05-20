//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: accurate
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 100

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int length, i, score = 0;

    printf("Enter a password: ");
    scanf("%s", password);

    length = strlen(password);

    if (length < 8) {
        printf("Weak password\n");
        return 0;
    }

    if (length >= 8 && length <= 12) {
        score += 1;
    } else if (length > 12) {
        score += 2;
    }

    if (strpbrk(password, "@#$%^&+=")!= NULL) {
        score += 1;
    }

    if (strpbrk(password, "ABCDEFGHIJKLMNOPQRSTUVWXYZ")!= NULL) {
        score += 1;
    } else if (strpbrk(password, "abcdefghijklmnopqrstuvwxyz")!= NULL) {
        score += 1;
    }

    if (strpbrk(password, "0123456789")!= NULL) {
        score += 1;
    }

    if (score == 0) {
        printf("Weak password\n");
    } else if (score == 1) {
        printf("Fair password\n");
    } else if (score == 2) {
        printf("Good password\n");
    } else if (score == 3) {
        printf("Strong password\n");
    } else if (score == 4) {
        printf("Very strong password\n");
    }

    return 0;
}