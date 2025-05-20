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
    int uppercase, lowercase, digit, special, length;
    uppercase = lowercase = digit = special = length = 0;

    printf("Enter a password (minimum length: %d, maximum length: %d):\n", MIN_LENGTH, MAX_LENGTH);
    scanf("%s", password);

    length = strlen(password);

    for (int i = 0; i < length; ++i) {
        if (isupper(password[i])) ++uppercase;
        if (islower(password[i])) ++lowercase;
        if (isdigit(password[i])) ++digit;
        if (!isalnum(password[i]) && !isspace(password[i])) ++special;
    }

    if (length < MIN_LENGTH)
        printf("Password is too short.\n");
    else if (uppercase == 0)
        printf("Password must contain at least one uppercase letter.\n");
    else if (lowercase == 0)
        printf("Password must contain at least one lowercase letter.\n");
    else if (digit == 0)
        printf("Password must contain at least one digit.\n");
    else if (special == 0)
        printf("Password must contain at least one special character.\n");
    else
        printf("Password is strong.\n");

    return 0;
}
