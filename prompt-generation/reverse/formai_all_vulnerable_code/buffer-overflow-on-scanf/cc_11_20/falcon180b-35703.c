//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 100

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int length;
    int upperCaseCount = 0;
    int lowerCaseCount = 0;
    int numberCount = 0;
    int specialCharCount = 0;
    int totalCount = 0;

    printf("Enter password to check strength: ");
    scanf("%s", password);

    length = strlen(password);

    if (length < 8) {
        printf("Password is weak. Please choose a longer password.\n");
        return 0;
    }

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            upperCaseCount++;
            totalCount++;
        }
        else if (islower(password[i])) {
            lowerCaseCount++;
            totalCount++;
        }
        else if (isdigit(password[i])) {
            numberCount++;
            totalCount++;
        }
        else if (isalpha(password[i]) &&!isdigit(password[i])) {
            specialCharCount++;
            totalCount++;
        }
    }

    if (totalCount == 0) {
        printf("Password is weak. Please choose a stronger password.\n");
        return 0;
    }

    if (upperCaseCount > 0 && lowerCaseCount > 0 && numberCount > 0 && specialCharCount > 0) {
        printf("Password is strong.\n");
    }
    else {
        printf("Password is moderate. Please consider adding more complexity.\n");
    }

    return 0;
}