//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: asynchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool isPasswordStrong(char*);

int main() {
    char password[100];
    printf("Enter password: ");
    scanf("%s", password);
 
    if (isPasswordStrong(password)) {
        printf("Password is strong\n");
    } else {
        printf("Password is weak\n");
    }
 
    return 0;
}

bool isPasswordStrong(char *password) {
    int length = strlen(password);
  
    int hasLowercase = 0;
    int hasUppercase = 0;
    int hasDigit = 0;
    int hasSpecialChar = 0;
 
    if (length < 8) {
        printf("Password must have at least 8 characters\n");
        return false;
    }
 
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            hasLowercase = 1;
        }
        if (isupper(password[i])) {
            hasUppercase = 1;
        }
        if (isdigit(password[i])) {
            hasDigit = 1;
        }
        if (!isalnum(password[i])) {
            hasSpecialChar = 1;
        }
    }
 
    if (!hasLowercase) {
        printf("Password must have at least one lowercase character\n");
        return false;
    }
 
    if (!hasUppercase) {
        printf("Password must have at least one uppercase character\n");
        return false;
    }
 
    if (!hasDigit) {
        printf("Password must have at least one digit\n");
        return false;
    }
 
    if (!hasSpecialChar) {
        printf("Password must have at least one special character\n");
        return false;
    }
 
    return true;
}