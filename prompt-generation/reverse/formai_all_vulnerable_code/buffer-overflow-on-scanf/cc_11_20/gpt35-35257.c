//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Donald Knuth
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main() {
    char password[100];
    int i, uppercase, lowercase, digit, special, len, score = 0;

    printf("Enter the password to be checked:\n");
    scanf("%s", password);

    len = strlen(password);

    if(len >= 8) {
        score++;
    }

    uppercase = lowercase = digit = special = 0;

    for(i=0; i<len; i++) {
        if(isupper(password[i])) {
            uppercase++;
        }
        else if(islower(password[i])) {
            lowercase++;
        }
        else if(isdigit(password[i])) {
            digit++;
        }
        else {
            special++;
        }
    }

    if(uppercase > 0) {
        score++;
    }

    if(lowercase > 0) {
        score++;
    }

    if(digit > 0) {
        score++;
    }

    if(special > 0) {
        score++;
    }

    switch(score) {
        case 0:
        printf("Password is too weak.\n");
        break;
        
        case 1:
        printf("Password is weak.\n");
        break;
        
        case 2:
        printf("Password is medium.\n");
        break;
        
        case 3:
        printf("Password is strong.\n");
        break;
        
        case 4:
        printf("Password is very strong.\n");
        break;
    }

    return 0;
}