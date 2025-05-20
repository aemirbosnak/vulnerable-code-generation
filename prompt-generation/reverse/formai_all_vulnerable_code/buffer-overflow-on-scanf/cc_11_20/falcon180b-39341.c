//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LOWERCASE 0
#define UPPERCASE 1
#define DIGIT 2
#define SPECIAL 3

int main() {
    char password[100];
    int length = 0, lowercase = 0, uppercase = 0, digit = 0, special = 0;
    int strength = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    for (int i = 0; i < length; i++) {
        if (isalpha(password[i])) {
            if (isupper(password[i])) {
                uppercase = 1;
            }
            else if (islower(password[i])) {
                lowercase = 1;
            }
        }
        else if (isdigit(password[i])) {
            digit = 1;
        }
        else {
            special = 1;
        }
    }

    if (length < 8) {
        printf("Password too short\n");
    }
    else if (length >= 8 && length < 16) {
        if (lowercase && uppercase && digit) {
            strength = 3;
            printf("Password is strong\n");
        }
        else {
            strength = 2;
            printf("Password is medium\n");
        }
    }
    else if (length >= 16 && (lowercase || uppercase || digit)) {
        strength = 4;
        printf("Password is very strong\n");
    }
    else {
        strength = 1;
        printf("Password is weak\n");
    }

    return 0;
}