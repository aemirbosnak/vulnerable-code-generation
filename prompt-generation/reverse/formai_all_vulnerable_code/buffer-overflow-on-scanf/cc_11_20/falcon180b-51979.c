//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: happy
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

int main() {
    char password[100];
    int length, i, j, count = 0, lower = 0, upper = 0, digit = 0, special = 0;
    char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char digits[] = "0123456789";
    char specialChars[] = "!@#$%^&*()_+~`|}{[]\:;?><,./-=";
    char message[100];

    printf("Welcome to the Password Strength Checker!\n");
    printf("Please enter your password:\n");
    scanf("%s", password);

    length = strlen(password);

    for(i = 0; i < length; i++) {
        if(isalnum(password[i])) {
            if(isupper(password[i])) {
                upper++;
            } else if(islower(password[i])) {
                lower++;
            } else if(isdigit(password[i])) {
                digit++;
            }
        } else {
            for(j = 0; j < strlen(specialChars); j++) {
                if(password[i] == specialChars[j]) {
                    special++;
                    break;
                }
            }
        }
    }

    if(length >= 8) {
        count++;
    }

    if(lower > 0) {
        count++;
    }

    if(upper > 0) {
        count++;
    }

    if(digit > 0) {
        count++;
    }

    if(special > 0) {
        count++;
    }

    if(count == 5) {
        strcpy(message, "Your password is very strong!");
    } else if(count == 4) {
        strcpy(message, "Your password is strong.");
    } else if(count == 3) {
        strcpy(message, "Your password is decent.");
    } else if(count == 2) {
        strcpy(message, "Your password is weak.");
    } else if(count == 1) {
        strcpy(message, "Your password is very weak.");
    } else {
        strcpy(message, "Invalid password.");
    }

    printf("%s\n", message);

    return 0;
}