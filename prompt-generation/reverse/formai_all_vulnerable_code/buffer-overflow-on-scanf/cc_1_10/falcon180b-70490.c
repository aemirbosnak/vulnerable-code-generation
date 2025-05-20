//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: happy
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_LENGTH 100
#define MIN_LENGTH 8
#define MAX_TRIES 3

bool isPasswordValid(char* password, int length) {
    if(length < MIN_LENGTH) {
        printf("Error: Password must be at least %d characters long.\n", MIN_LENGTH);
        return false;
    }

    if(length > MAX_LENGTH) {
        printf("Error: Password cannot be longer than %d characters.\n", MAX_LENGTH);
        return false;
    }

    int numUppercase = 0, numLowercase = 0, numDigits = 0;

    for(int i = 0; i < length; i++) {
        if(isupper(password[i])) {
            numUppercase++;
        } else if(islower(password[i])) {
            numLowercase++;
        } else if(isdigit(password[i])) {
            numDigits++;
        }
    }

    if(numUppercase < 1 || numLowercase < 1 || numDigits < 1) {
        printf("Error: Password must contain at least one uppercase letter, one lowercase letter, and one digit.\n");
        return false;
    }

    if(length > 12 && numDigits < 2) {
        printf("Error: Password must contain at least two digits if it is longer than 12 characters.\n");
        return false;
    }

    if(length > 16 && numUppercase < 2 && numLowercase < 2) {
        printf("Error: Password must contain at least two uppercase letters and two lowercase letters if it is longer than 16 characters.\n");
        return false;
    }

    return true;
}

int main() {
    char password[MAX_LENGTH];

    printf("Welcome to the Password Strength Checker!\n");

    int tries = 0;
    while(tries < MAX_TRIES) {
        printf("Please enter a password: ");
        scanf("%s", password);

        if(isPasswordValid(password, strlen(password))) {
            printf("Congratulations, your password is strong!\n");
            break;
        } else {
            printf("Error: ");
            if(tries == MAX_TRIES - 1) {
                printf("You have reached the maximum number of tries. Goodbye.\n");
            } else {
                printf("Please try again.\n");
            }
            tries++;
        }
    }

    return 0;
}