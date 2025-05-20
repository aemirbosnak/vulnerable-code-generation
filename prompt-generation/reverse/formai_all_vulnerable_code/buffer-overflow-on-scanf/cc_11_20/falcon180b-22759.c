//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char password[100];
    int length, upper, lower, digit, special;
    int strength = 0;
    char *uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *lowercase = "abcdefghijklmnopqrstuvwxyz";
    char *digits = "0123456789";
    char *special_chars = "!@#$%^&*()_+{}:\"|\\<>?,./-=";

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    if(length < 8) {
        printf("Password must be at least 8 characters long.\n");
        return 0;
    }

    upper = lower = digit = special = 0;

    for(int i=0; i<length; i++) {
        if(isupper(password[i])) {
            upper = 1;
        } else if(islower(password[i])) {
            lower = 1;
        } else if(isdigit(password[i])) {
            digit = 1;
        } else if(strchr(special_chars, password[i])!= NULL) {
            special = 1;
        }
    }

    if(upper && lower && digit && special) {
        printf("Your password is very strong!\n");
        strength = 4;
    } else if(upper && lower && digit) {
        printf("Your password is strong.\n");
        strength = 3;
    } else if(upper && lower) {
        printf("Your password is moderate.\n");
        strength = 2;
    } else if(upper || lower || digit) {
        printf("Your password is weak.\n");
        strength = 1;
    } else {
        printf("Your password is very weak.\n");
        strength = 0;
    }

    return 0;
}