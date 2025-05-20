//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

int main() {
    char password[20];
    int length, upper = 0, lower = 0, digit = 0, special = 0, strength = 0;

    printf("Enter password: ");
    scanf("%s", password);

    length = strlen(password);

    for(int i = 0; i < length; i++) {
        if(password[i] >= 'A' && password[i] <= 'Z') {
            upper = 1;
        }
        else if(password[i] >= 'a' && password[i] <= 'z') {
            lower = 1;
        }
        else if(password[i] >= '0' && password[i] <= '9') {
            digit = 1;
        }
        else {
            special = 1;
        }
    }

    if(length >= 7 && upper && lower && digit && special) {
        strength = 4;
    }
    else if(length >= 7 && (upper || lower) && digit && special) {
        strength = 3;
    }
    else if(length >= 7 && ((upper && digit) || (lower && digit) || (upper && lower))) {
        strength = 2;
    }
    else if(length >= 7 && (upper || lower || digit || special)) {
        strength = 1;
    }

    printf("Password Strength: ");

    if(strength == 4) {
        printf("Very Strong");
    }
    else if(strength == 3) {
        printf("Strong");
    }
    else if(strength == 2) {
        printf("Moderate");
    }
    else if(strength == 1) {
        printf("Weak");
    }
    else {
        printf("Very Weak");
    }

    return 0;
}