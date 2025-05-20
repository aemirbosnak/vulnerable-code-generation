#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char password[100];
    int has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0;
    int length = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) has_upper = 1;
        if (islower(password[i])) has_lower = 1;
        if (isdigit(password[i])) has_digit = 1;
        if (!isalnum(password[i])) has_special = 1;
    }

    printf("Password Length: %d\n", length);
    printf("Contains Uppercase: %s\n", has_upper ? "Yes" : "No");
    printf("Contains Lowercase: %s\n", has_lower ? "Yes" : "No");
    printf("Contains Digits: %s\n", has_digit ? "Yes" : "No");
    printf("Contains Special Characters: %s\n", has_special ? "Yes" : "No");

    return 0;
}
