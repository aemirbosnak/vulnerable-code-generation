#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 32
#define MIN_UPPER 1
#define MIN_LOWER 1
#define MIN_DIGIT 1
#define MIN_SPECIAL 0
#define MAX_SPECIAL 3

int main() {
    char password[MAX_LENGTH];
    int upper, lower, digit, special;
    int length = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    upper = lower = digit = special = 0;

    for (int i = 0; i < length; ++i) {
        if (isupper(password[i])) ++upper;
        if (islower(password[i])) ++lower;
        if (isdigit(password[i])) ++digit;
        if (!isalnum(password[i]) && i < length - 1 && isalnum(password[i + 1])) ++special;
    }

    if (length < MIN_LENGTH) {
        printf("Password is too short.\n");
        return 1;
    }

    if (upper < MIN_UPPER) {
        printf("Password must contain at least one uppercase letter.\n");
        return 1;
    }

    if (lower < MIN_LOWER) {
        printf("Password must contain at least one lowercase letter.\n");
        return 1;
    }

    if (digit < MIN_DIGIT) {
        printf("Password must contain at least one digit.\n");
        return 1;
    }

    if (special < MIN_SPECIAL || special > MAX_SPECIAL) {
        printf("Password must contain at least one special character, and no more than three.\n");
        return 1;
    }

    printf("Password is strong.\n");
    return 0;
}
