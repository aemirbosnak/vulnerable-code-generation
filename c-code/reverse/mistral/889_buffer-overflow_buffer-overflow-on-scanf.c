#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MIN_LENGTH 8
#define UPPER 1
#define LOWER 1 << 1
#define DIGIT 1 << 2
#define SPECIAL 1 << 3

int main() {
    char password[100];
    int length = 0, upper_count = 0, lower_count = 0, digit_count = 0, special_count = 0;
    int requirements = UPPER | LOWER | DIGIT | SPECIAL;

    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);

    for (int i = 0; password[i]; ++i) {
        if (isupper(password[i])) ++upper_count;
        else if (islower(password[i])) ++lower_count;
        else if (isdigit(password[i])) ++digit_count;
        else if (strchr("!@#$%^&*()-_+=", password[i])) ++special_count;
        ++length;
    }

    if (length < MIN_LENGTH) {
        printf("Password is too short. Minimum length is %d.\n", MIN_LENGTH);
        return 1;
    }

    if (!(upper_count & requirements) || !(lower_count & requirements) ||
        !(digit_count & requirements) || !(special_count & requirements)) {
        printf("Password must contain at least one uppercase letter, one lowercase letter, one digit, and one special character.\n");
        return 1;
    }

    printf("Password is secure.\n");
    return 0;
}
