//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: shocked
#include<stdio.h>
#include<string.h>

int main(void) {
    char password[50];
    int i, length, hasLower, hasUpper, hasDigit, hasSpecialChar, score = 0;

    printf("Enter the password to be checked: ");
    scanf("%s", password);

    length = strlen(password);

    for(i=0;i<length;i++) {
        if(password[i] >= 'a' && password[i] <= 'z') {
            hasLower = 1;
        }
        if(password[i] >= 'A' && password[i] <= 'Z') {
            hasUpper = 1;
        }
        if(password[i] >= '0' && password[i] <= '9') {
            hasDigit = 1;
        }
        if(password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '^' || password[i] == '&' || password[i] == '*') {
            hasSpecialChar = 1;
        }
    }

    if(length < 8 || hasLower != 1 || hasUpper != 1 || hasDigit != 1 || hasSpecialChar != 1) {
        printf("Password Strength: Weak\n");
        printf("Your password needs to have at least:\n1 uppercase letter\n1 lowercase letter\n1 digit\n1 special character (@, #, $, ^, &, *). \n");
    }
    else {
        score = length * 5;
        score += hasLower * 10;
        score += hasUpper * 15;
        score += hasDigit * 10;
        score += hasSpecialChar * 20;

        if(score < 50) {
            printf("Password Strength: Weak\n");
            printf("Your password needs improvement!!\n");
        }
        else if(score < 75) {
            printf("Password Strength: Medium\n");
            printf("Your password is okay, but could be better!!\n");
        }
        else if(score < 100) {
            printf("Password Strength: Good\n");
            printf("Your password is strong, but not the best!!\n");
        }
        else {
            printf("Password Strength: Excellent\n");
            printf("WOW! You have an excellent password!!\n");
        }
    }
    
    return 0;
}