//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: sophisticated
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool hasLowerCase(char c) {
    if(c >= 'a' && c <= 'z')
        return true;
    else
        return false;
}

bool hasUpperCase(char c) {
    if(c >= 'A' && c <= 'Z')
        return true;
    else
        return false;
}

bool hasDigit(char c) {
    if(c >= '0' && c <= '9')
        return true;
    else
        return false;
}

bool hasSpecial(char c) {
    if((c >= '!' && c <= '/') || (c >= ':' && c <= '@') || (c >= '[' && c <= '`') || (c >= '{' && c <= '~'))
        return true;
    else
        return false;
}

int main() {
    char password[50];
    int length, strength = 0;
    bool hasLower = false, hasUpper = false, hasNum = false, hasSpec = false;

    printf("Enter a password: ");
    scanf("%s", password);

    length = strlen(password);

    for(int i = 0; i < length; i++) {
        char c = password[i];
        if(hasLowerCase(c))
            hasLower = true;
        if(hasUpperCase(c))
            hasUpper = true;
        if(hasDigit(c))
            hasNum = true;
        if(hasSpecial(c))
            hasSpec = true;
    }

    if((length >= 8) && (hasLower == true) && (hasUpper == true) && (hasNum == true) && (hasSpec == true))
        strength = 5;
    else if((length >= 8) && ((hasLower == true) || (hasUpper == true)) && (hasNum == true) && (hasSpec == true))
        strength = 4;
    else if((length >= 8) && ((hasLower == true) || (hasUpper == true) || (hasNum == true)))
        strength = 3;
    else if(length >= 6)
        strength = 2;
    else if(length < 6)
        strength = 1;

    switch(strength) {
        case 1:
            printf("\nThe password '%s' is weak. Please choose a password with at least 6 characters.", password);
            break;
        case 2:
            printf("\nThe password '%s' is moderate. Please choose a stronger password with at least 8 characters.", password);
            break;
        case 3:
            printf("\nThe password '%s' is strong. Keep up the good work!", password);
            break;
        case 4:
            printf("\nThe password '%s' is very strong. Impressive!", password);
            break;
        case 5:
            printf("\nThe password '%s' is extremely strong. You are a password ninja!", password);
            break;
    }

    return 0;
}