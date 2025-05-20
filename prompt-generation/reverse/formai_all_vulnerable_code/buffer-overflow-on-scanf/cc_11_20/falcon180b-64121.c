//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main() {
    char password[100];
    int length, i, sum = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    //Check for minimum length
    if(length < 8) {
        printf("Password should be at least 8 characters long.\n");
        return 0;
    }

    //Check for uppercase letters
    for(i = 0; i < length; i++) {
        if(isupper(password[i])) {
            sum += 1;
        }
    }

    //Check for lowercase letters
    for(i = 0; i < length; i++) {
        if(islower(password[i])) {
            sum += 1;
        }
    }

    //Check for digits
    for(i = 0; i < length; i++) {
        if(isdigit(password[i])) {
            sum += 1;
        }
    }

    //Check for special characters
    for(i = 0; i < length; i++) {
        if(!isalnum(password[i])) {
            sum += 1;
        }
    }

    //Calculate the strength of the password
    if(sum == 0) {
        printf("Very Weak\n");
    } else if(sum == 1) {
        printf("Weak\n");
    } else if(sum == 2) {
        printf("Fair\n");
    } else if(sum == 3) {
        printf("Good\n");
    } else if(sum == 4) {
        printf("Strong\n");
    } else {
        printf("Very Strong\n");
    }

    return 0;
}