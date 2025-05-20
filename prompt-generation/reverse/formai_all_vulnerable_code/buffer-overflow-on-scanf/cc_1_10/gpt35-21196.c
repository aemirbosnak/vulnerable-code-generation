//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: energetic
#include<stdio.h>
#include<string.h>

void checkPasswordStrength(char password[]){

    int length, i, digitCount=0, uppercaseCount=0, lowercaseCount=0, symbolCount=0;

    length = strlen(password);

    if(length>=8){
        printf("Length is strong enough!\n");
    }
    else{
        printf("Password is too short, required length is at least 8.\n");
        return;
    }

    for(i=0; i<length; i++){
        if(password[i]>=48 && password[i]<=57){
            digitCount++;
        }
        else if(password[i]>=65 && password[i]<=90){
            uppercaseCount++;
        }
        else if(password[i]>=97 && password[i]<=122){
            lowercaseCount++;
        }
        else{
            symbolCount++;
        }
    }

    if(digitCount>=1){
        printf("Contains enough digits!\n");
    }
    else{
        printf("Password must contain at least 1 digit.\n");
    }

    if(uppercaseCount>=1){
        printf("Contains enough uppercase letters!\n");
    }
    else{
        printf("Password must contain at least 1 uppercase letter.\n");
    }

    if(lowercaseCount>=1){
        printf("Contains enough lowercase letters!\n");
    }
    else{
        printf("Password must contain at least 1 lowercase letter.\n");
    }

    if(symbolCount>=1){
        printf("Contains at least 1 symbol!\n");
    }
    else{
        printf("Password must contain at least 1 symbol.\n");
    }

}

int main(){

    char password[25];

    printf("Enter password:\n");
    scanf("%s", password);

    checkPasswordStrength(password);

    return 0;

}