//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*Function to check the strength of a password*/
int check_password_strength(char *password){
    int i, has_uppercase=0, has_lowercase=0, has_digit=0, has_special=0;
    int length = strlen(password);

    /*Checking if the password is too short*/
    if(length < 8){
        printf("Password should be at least 8 characters long.\n");
        return 0;
    }

    for(i=0; i<length; i++){

        /*Checking for uppercase character(s)*/
        if(isupper(password[i])){
            has_uppercase = 1;
            continue;
        }

        /*Checking for lowercase character(s)*/
        if(islower(password[i])){
            has_lowercase = 1;
            continue;
        }

        /*Checking for digit(s)*/
        if(isdigit(password[i])){
            has_digit = 1;
            continue;
        }

        /*Checking for special character(s)*/
        if(password[i] == '@' || password[i] == '#' || password[i] == '%' || password[i] == '$'){
            has_special = 1;
            continue;
        }
    }

    /*Printing appropriate message according to password strength*/
    if(has_uppercase && has_lowercase && has_digit && has_special){
        printf("Password is strong enough!\n");
        return 1;
    }
    else if((has_uppercase && has_lowercase && has_digit) || (has_lowercase && has_digit && has_special) || (has_uppercase && has_digit && has_special) || (has_uppercase && has_lowercase && has_special)){
        printf("Password is medium strength.\n");
        return 1;
    }
    else{
        printf("Password is weak. Try again.\n");
        return 0;
    }
}

int main(){
    char password[100];

    /*Getting password from the user*/
    printf("Enter your password: ");
    scanf("%s", password);

    /*Checking password strength*/
    check_password_strength(password);

    return 0;
}