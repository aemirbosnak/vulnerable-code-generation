//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: safe
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[21];
    int uppercase = 0, lowercase = 0, digits = 0, symbols = 0, length = 0, strength = 0;
    
    printf("Enter a password: ");
    scanf("%s", password);
    length = strlen(password);
    
    for(int i = 0; i < length; i++) {
        if(isupper(password[i])) uppercase++;
        if(islower(password[i])) lowercase++;
        if(isdigit(password[i])) digits++;
        if(!isalnum(password[i])) symbols++;
    }

    if(length < 8) {
        printf("Password is too short.\n");
    }
    else if(length > 20) {
        printf("Password is too long.\n");
    }
    else if(uppercase < 1) {
        printf("Password must contain at least one uppercase letter.\n");
    }
    else if(lowercase < 1) {
        printf("Password must contain at least one lowercase letter.\n");
    }
    else if(digits < 1) {
        printf("Password must contain at least one digit.\n");
    }
    else if(symbols < 1) {
        printf("Password must contain at least one symbol.\n");
    }
    else {
        strength = (length * 10) + (uppercase * 5) + (lowercase * 5) + (digits * 5) + (symbols * 10);
        
        if(strength < 50) {
            printf("Password strength is weak.\n");
        }
        else if(strength < 75) {
            printf("Password strength is medium.\n");
        }
        else if(strength < 100) {
            printf("Password strength is strong.\n");
        }
        else {
            printf("Password strength is very strong.\n");
        }
    }

    return 0;
}