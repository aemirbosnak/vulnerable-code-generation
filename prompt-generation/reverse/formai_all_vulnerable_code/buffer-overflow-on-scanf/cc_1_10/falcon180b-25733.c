//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define LOWER "abcdefghijklmnopqrstuvwxyz"
#define UPPER "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define DIGITS "0123456789"
#define SPECIAL "!@#$%^&*()_+-=[]{}|;':\",.<>/?"

int main() {
    int length, i, j;
    char password[100];
    char lowercase, uppercase, digit, special;
    char *lower, *upper, *digits, *specials;
    printf("Enter password length: ");
    scanf("%d", &length);
    printf("Enter lowercase letters (y/n): ");
    scanf(" %c", &lowercase);
    printf("Enter uppercase letters (y/n): ");
    scanf(" %c", &uppercase);
    printf("Enter digits (y/n): ");
    scanf(" %c", &digit);
    printf("Enter special characters (y/n): ");
    scanf(" %c", &special);
    if(lowercase == 'y') {
        lower = LOWER;
    } else {
        lower = "";
    }
    if(uppercase == 'y') {
        upper = UPPER;
    } else {
        upper = "";
    }
    if(digit == 'y') {
        digits = DIGITS;
    } else {
        digits = "";
    }
    if(special == 'y') {
        specials = SPECIAL;
    } else {
        specials = "";
    }
    srand(time(0));
    for(i = 0; i < length; i++) {
        if(i == 0) {
            password[i] = tolower(rand() % 26 + 'a');
        } else {
            j = rand() % 4;
            if(j == 0) {
                password[i] = tolower(rand() % 26 + 'a');
            } else if(j == 1) {
                password[i] = toupper(rand() % 26 + 'A');
            } else if(j == 2) {
                password[i] = rand() % 10 + '0';
            } else {
                password[i] = specials[rand() % strlen(specials)];
            }
        }
    }
    printf("Your password is: %s\n", password);
    return 0;
}