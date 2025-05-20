//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int length, uppercase, lowercase, digits, symbols;

    printf("Please enter your password: ");
    scanf("%s", password);

    length = strlen(password);
    uppercase = lowercase = digits = symbols = 0;

    for(int i = 0; i < length; i++) {
        if(isupper(password[i]))
            uppercase++;
        else if(islower(password[i]))
            lowercase++;
        else if(isdigit(password[i]))
            digits++;
        else
            symbols++;
    }

    printf("Password strength report: \n");
    
    if(length < 8)
        printf("- Password is too short. It should be at least 8 characters long.\n");
    else if(length <= 12)
        printf("- Password length is good. But it is weak because it doesn't have enough characters.\n");
    else
        printf("- Password length is good.\n");

    if(uppercase < 1)
        printf("- Password should contain at least one uppercase letter.\n");
    else if(uppercase == 1)
        printf("- Password has one uppercase letter. You can do better.\n");
    else
        printf("- Password has good number of uppercase letters.\n");

    if(lowercase < 1)
        printf("- Password should contain at least one lowercase letter.\n");
    else if(lowercase == 1)
        printf("- Password has one lowercase letter. You can do better.\n");
    else
        printf("- Password has good number of lowercase letters.\n");

    if(digits < 1)
        printf("- Password should contain at least one digit.\n");
    else if(digits == 1)
        printf("- Password has one digit. You can do better.\n");
    else
        printf("- Password has good number of digits.\n");

    if(symbols < 1)
        printf("- Password should contain at least one symbol (such as !, @, #, $, %, ^, & or *).\n");
    else if(symbols == 1)
        printf("- Password has one symbol. You can do better.\n");
    else
        printf("- Password has good number of symbols.\n");

    return 0;
}