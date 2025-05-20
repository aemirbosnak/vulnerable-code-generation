#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define PASSWORD_LENGTH 10

int main() {
    char password[PASSWORD_LENGTH];
    int uppercase = 0, lowercase = 0, digit = 0, special = 0, length = 0;

    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; password[i]; ++i) {
        if (isupper(password[i])) ++uppercase;
        else if (islower(password[i])) ++lowercase;
        else if (isdigit(password[i])) ++digit;
        else ++special;
        ++length;
    }

    if (length < 8)
        printf("Weak\n");
    else if (uppercase < 2 || lowercase < 2 || digit < 2 || special < 1)
        printf("Medium\n");
    else
        printf("Strong\n");

    return 0;
}
