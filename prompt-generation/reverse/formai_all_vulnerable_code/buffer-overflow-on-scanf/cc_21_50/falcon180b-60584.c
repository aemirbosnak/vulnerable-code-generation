//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: systematic
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    char password[100];
    int length;
    int uppercase = 0, lowercase = 0, number = 0, special = 0;
    int strength = 0;
    char *special_chars = "!@#$%^&*()_+-=[]{}|;:,.<>?";

    printf("Enter a password: ");
    scanf("%s", password);
    length = strlen(password);

    if (length < 8) {
        printf("Password is too short.\n");
        return 0;
    }

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase = 1;
        } else if (islower(password[i])) {
            lowercase = 1;
        } else if (isdigit(password[i])) {
            number = 1;
        } else if (strchr(special_chars, password[i])!= NULL) {
            special = 1;
        }
    }

    if (uppercase && lowercase && number && special) {
        strength = 4;
    } else if (uppercase && lowercase && number) {
        strength = 3;
    } else if (uppercase && lowercase || uppercase && number || lowercase && number) {
        strength = 2;
    } else if (uppercase || lowercase || number) {
        strength = 1;
    } else {
        strength = 0;
    }

    printf("Password strength: ");
    for (int i = 0; i < strength; i++) {
        printf("*");
    }
    printf("\n");

    return 0;
}