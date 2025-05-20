//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Function to check if password is strong
int isStrong(char* password){
    int i;
    int hasUpper = 0, hasLower = 0, hasDigit = 0;
    int length = strlen(password);

    //Checking the length of password
    if(length<8){
        return 0;
    }
    for(i=0; i<length; i++){
        //Checking if password has upper case letters
        if(isupper(*(password+i))){
            hasUpper = 1;
        }
        //Checking if password has lower case letters
        if(islower(*(password+i))){
            hasLower = 1;
        }
        //Checking if password has digits
        if(isdigit(*(password+i))){
            hasDigit = 1;
        }
    }
    //Checking if password meets all requirements
    if(hasUpper && hasLower && hasDigit){
        return 1;
    }
    else{
        return 0;
    }
}

int main() {
    char password[100];

    //Taking input from user
    printf("Enter your password: ");
    scanf("%s", password);

    //Checking if password is strong
    if(isStrong(password)){
        printf("Your password is strong.\n");
    }
    else{
        printf("Your password is not strong. Please make sure it has at least 8 characters, at least one upper case letter, one lower case letter, and one digit.\n");
    }

    return 0;
}