//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: automated
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main(){

    char password[50];
    int length,i;

    printf("Enter the password: ");
    scanf("%s",password);

    length=strlen(password);

    if(length<8){
        printf("Password should be at least 8 characters long.\n");
        exit(0);
    }

    int has_uppercase=0,has_lowercase=0,has_number=0,has_special=0;

    for(i=0;i<length;i++){

        if(isupper(password[i])){
            has_uppercase=1;
        }

        if(islower(password[i])){
            has_lowercase=1;
        }

        if(isdigit(password[i])){
            has_number=1;
        }

        if(password[i]=='!' || password[i]=='@' || password[i]=='#' || password[i]=='$' || password[i]=='%' || password[i]=='^' || password[i]=='&' || password[i]=='*' || password[i]=='(' || password[i]==')' || password[i]=='-' || password[i]=='_' || password[i]=='+' || password[i]=='=' || password[i]=='{' || password[i]=='}' || password[i]=='[' || password[i]==']' || password[i]=='|' || password[i]==';' || password[i]==':' || password[i]=='"' || password[i]=='\'' || password[i]==',' || password[i]=='.' || password[i]=='<' || password[i]=='>' || password[i]=='/' || password[i]=='?' || password[i]=='~' || password[i]=='`' || password[i]=='{' || password[i]=='|' || password[i]=='}' || password[i]=='~' || password[i]=='`'){
            has_special=1;
        }

    }

    if(has_uppercase && has_lowercase && has_number && has_special){
        printf("Password is strong.\n");
    }

    else{
        printf("Password is weak.\n");
    }

    return 0;
}