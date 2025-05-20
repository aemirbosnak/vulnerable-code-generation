//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: satisfied
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX_LENGTH 20

int main() {
    char password[MAX_LENGTH];
    int length, i;
    int upperCount, lowerCount, digitCount, specialCount;
    int strength = 0; 

    printf("Enter your password: ");
    fgets(password, MAX_LENGTH, stdin);
    length = strlen(password);

    // remove newline character from password
    if (password[length-1] == '\n') {
        password[length-1] = '\0';
        length--;
    }

    // check length requirement
    if (length >= 8 && length <= 16) {
        strength += 1;
    }

    // count number of uppercase, lowercase, digits, special characters
    upperCount = lowerCount = digitCount = specialCount = 0;
    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            upperCount++;
        }
        else if (islower(password[i])) {
            lowerCount++;
        }
        else if (isdigit(password[i])) {
            digitCount++;
        }
        else {
            specialCount++;
        }
    }

    // check uppercase requirement
    if (upperCount >= 1) {
        strength += 1;
    }

    // check lowercase requirement
    if (lowerCount >= 1) {
        strength += 1;
    }

    // check digit requirement
    if (digitCount >= 1) {
        strength += 1;
    }

    // check special character requirement
    if (specialCount >= 1) {
        strength += 1;
    }

    // print password strength message
    switch (strength) {
        case 0:
        case 1:
            printf("Weak password.\n");
            break;
        case 2:
            printf("Moderate password.\n");
            break;
        case 3:
        case 4:
            printf("Strong password.\n");
            break;
        default:
            printf("Invalid password.\n");
    }

    return 0;
}