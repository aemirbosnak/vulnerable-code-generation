//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: active
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    char password[100];
    int length, upper, lower, digit, symbol, strength;

    // Getting input from user
    printf("Enter your password: ");
    scanf("%s", password);

    // Checking the length of password
    length = strlen(password);
    if(length < 8){
        printf("Password length is weak!\n"); // Weak password
        printf("Please enter a password with at least 8 characters.\n");
        return 0;
    }

    // Checking for at least 1 uppercase letter, 1 lowercase letter, and 1 digit
    upper = lower = digit = symbol = 0;
    for(int i=0; i<length; i++){
        if(isupper(password[i]))
            upper = 1;
        else if(islower(password[i]))
            lower = 1;
        else if(isdigit(password[i]))
            digit = 1;
        else
            symbol = 1;
    }
    if(!upper || !lower || !digit || !symbol){
        printf("Password must contain at least 1 uppercase letter, 1 lowercase letter, 1 digit, and 1 symbol.\n");
        return 0;
    }

    // Checking password strength
    strength = 0;
    if(length >= 8 && length <= 12)
        strength++;
    if(upper && lower)
        strength++;
    if(digit && symbol)
        strength++;
    if(length > 12)
        strength++;

    // Printing password strength
    switch(strength){
        case 1:
            printf("Your password is weak!\n");
            break;
        case 2:
            printf("Your password is moderate.\n");
            break;
        case 3:
            printf("Your password is strong.\n");
            break;
        case 4:
            printf("Your password is very strong!\n");
            break;
    }

    return 0;
}