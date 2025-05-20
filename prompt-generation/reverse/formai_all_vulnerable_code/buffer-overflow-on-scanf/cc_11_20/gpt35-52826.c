//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: careful
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char password[20];
    int length, upper, lower, digit, special;
    int i, score = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    if (length < 8) {
        printf("Password length should be at least 8 characters\n");
        return 0;
    }

    for (i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            digit = 1;
        }
        else if (isupper(password[i])) {
            upper = 1;
        }
        else if (islower(password[i])) {
            lower = 1;
        }
        else if (ispunct(password[i])) {
            special = 1;
        }
    }

    score = digit + upper + lower + special;

    if (score == 1) {
        printf("Password strength is weak\n");
    }
    else if (score == 2) {
        printf("Password strength is moderate\n");
    }
    else if (score == 3) {
        printf("Password strength is strong\n");
    }
    else if (score == 4) {
        printf("Password strength is very strong\n");
    }

    return 0;
}