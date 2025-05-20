//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char password[51];
    int upper = 0, lower = 0, digits = 0, special = 0;

    printf("Enter your password:\n");
    fgets(password, sizeof(password), stdin);

    int len = strlen(password);
    password[len-1] = '\0';

    for(int i = 0; i < len; i++) {
        if(password[i] >= 'A' && password[i] <= 'Z') {
            upper++;
        }
        else if(password[i] >= 'a' && password[i] <= 'z') {
            lower++;
        }
        else if(password[i] >= '0' && password[i] <= '9') {
            digits++;
        }
        else {
            special++;
        }
    }

    printf("\nChecking password strength...\n");
    printf("______________________________\n");

    if(len < 8) {
        printf("Password too short!\n");
    }

    if(lower == 0) {
        printf("Add some lowercase letters\n");
    }

    if(upper == 0) {
        printf("Add some uppercase letters\n");
    }

    if(digits == 0) {
        printf("Add some digits\n");
    }

    if(special == 0) {
        printf("Add some special characters\n");
    } else if(special % 2 != 0) {
        printf("Add one more special character\n");
    }

    if(len >= 8 && lower > 0 && upper > 0 && digits > 0 && special > 0 && special % 2 == 0) {
        printf("Great job! Your password is strong!\n");
    }

    return 0;
}