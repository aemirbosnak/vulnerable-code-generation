#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 32

int main() {
    char password[MAX_LENGTH];
    int upper, lower, digit, special, length;

    printf("Enter password (8-32 characters): ");
    scanf("%s", password);

    length = strlen(password);
    upper = lower = digit = special = 0;

    for (int i = 0; i < length; ++i) {
        if (isupper(password[i]))
            upper = 1;
        else if (islower(password[i]))
            lower = 1;
        else if (isdigit(password[i]))
            digit = 1;
        else if (strchr("!@#$%^&*()-_+=", password[i]))
            special = 1;
    }

    printf("\nPassword Analysis:\n");
    printf("Length: %d\n", length);
    printf("Uppercase: %s\n", upper ? "Present" : "Absent");
    printf("Lowercase: %s\n", lower ? "Present" : "Absent");
    printf("Digits: %s\n", digit ? "Present" : "Absent");
    printf("Special Characters: %s\n", special ? "Present" : "Absent");

    if (length < MIN_LENGTH)
        printf("Security Level: Weak\n");
    else if (upper && lower && digit && special)
        printf("Security Level: Strong\n");
    else if (upper && lower && (digit || special))
        printf("Security Level: Medium\n");
    else
        printf("Security Level: Weak\n");

    return 0;
}
