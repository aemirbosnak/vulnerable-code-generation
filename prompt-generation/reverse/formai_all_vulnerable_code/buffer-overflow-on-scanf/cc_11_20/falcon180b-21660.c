//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int length, uppercase = 0, lowercase = 0, digit = 0, special = 0;

    printf("Enter your password: ");
    scanf("%s", password);
    length = strlen(password);

    //check for uppercase letters
    for(int i=0; i<length; i++) {
        if(isupper(password[i])) {
            uppercase = 1;
            break;
        }
    }

    //check for lowercase letters
    for(int i=0; i<length; i++) {
        if(islower(password[i])) {
            lowercase = 1;
            break;
        }
    }

    //check for digits
    for(int i=0; i<length; i++) {
        if(isdigit(password[i])) {
            digit = 1;
            break;
        }
    }

    //check for special characters
    for(int i=0; i<length; i++) {
        if(!isalnum(password[i])) {
            special = 1;
            break;
        }
    }

    //check password strength
    if(length < 8) {
        printf("Weak password\n");
    }
    else if(length >= 8 && length < 12) {
        if(uppercase && lowercase && digit) {
            printf("Moderate password\n");
        }
        else {
            printf("Weak password\n");
        }
    }
    else if(length >= 12) {
        if(uppercase && lowercase && digit && special) {
            printf("Strong password\n");
        }
        else {
            printf("Moderate password\n");
        }
    }

    return 0;
}