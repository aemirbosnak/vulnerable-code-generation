//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: ultraprecise
#include<stdio.h>
#include<string.h>

/*Function to check if given password is strong*/
int checkStrongPassword(char* password){
    int len = strlen(password);

    /*Checking length of password*/
    if(len<8){
        printf("Password should be at least 8 characters long.\n");
        return 0;
    }

    /*Declaring and initializing variables*/
    int upper=0,lower=0,number=0,special=0;
    int i;
    for(i=0;i<len;i++){
        /*Checking for uppercase letters*/
        if(password[i]>='A' && password[i]<='Z'){
            upper = 1;
        }
        /*Checking for lowercase letters*/
        else if(password[i]>='a' && password[i]<='z'){
            lower = 1;
        }
        /*Checking for digits*/
        else if(password[i]>='0' && password[i]<='9'){
            number = 1;
        }
        /*Checking for special characters*/
        else{
            special = 1;
        }
    }

    /*Checking if all conditions are met*/
    if(upper==1 && lower==1 && number==1 && special==1){
        printf("Password is strong.\n");
        return 1;
    }
    else{
        printf("Password should contain atleast one uppercase letter, one lowercase letter, one digit, and one special character.\n");
        return 0;
    }
}

/*Function to get password from user*/
char* getPassword(){
    char* password = (char*)malloc(sizeof(char)*50);
    printf("Enter password: ");
    scanf("%s",password);
    return password;
}

/*Main function*/
int main(){
    char* password = getPassword();
    int isPasswordStrong = checkStrongPassword(password);
    free(password);
    return 0;
}