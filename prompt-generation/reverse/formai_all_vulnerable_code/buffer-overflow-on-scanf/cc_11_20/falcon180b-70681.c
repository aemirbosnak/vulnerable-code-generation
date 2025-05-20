//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: Romeo and Juliet
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main(){
    char password[100];
    int length, i;

    printf("Enter the password: ");
    scanf("%s", password);

    //Checking length of password
    length = strlen(password);

    if(length < 8){
        printf("Password should be at least 8 characters long.\n");
        return 0;
    }

    //Checking for uppercase letter
    for(i=0;i<length;i++){
        if(isupper(password[i])){
            printf("Password contains an uppercase letter.\n");
        }
        else{
            printf("Password does not contain an uppercase letter.\n");
            return 0;
        }
    }

    //Checking for lowercase letter
    for(i=0;i<length;i++){
        if(islower(password[i])){
            printf("Password contains a lowercase letter.\n");
        }
        else{
            printf("Password does not contain a lowercase letter.\n");
            return 0;
        }
    }

    //Checking for digit
    for(i=0;i<length;i++){
        if(isdigit(password[i])){
            printf("Password contains a digit.\n");
        }
        else{
            printf("Password does not contain a digit.\n");
            return 0;
        }
    }

    //Checking for special character
    for(i=0;i<length;i++){
        if(password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '&' || password[i] == '*' || password[i] == '?'){
            printf("Password contains a special character.\n");
        }
        else{
            printf("Password does not contain a special character.\n");
            return 0;
        }
    }

    printf("Password is strong.\n");
    return 0;
}