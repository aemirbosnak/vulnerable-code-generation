//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: intelligent
#include<stdio.h>
#include<string.h>

//Function declarations
int checkLength(char password[]);
int checkUpperCase(char password[]);
int checkLowerCase(char password[]);
int checkDigit(char password[]);
int checkSpecial(char password[]);

//Main function
int main(){
    char password[100];

    printf("Enter your password:\n");
    scanf("%s", password);

    //Checking the length
    int len = checkLength(password);
    if (len == 0){
        printf("Password must be of minimum 8 characters.\n");
        return 0;
    }
    if(len < 8){
        printf("Password is weak. It must be of minimum 8 characters.\n");
        return 0;
    }

    //Checking for uppercase letters
    int uppercase = checkUpperCase(password);
    if (uppercase == 0){
        printf("Password must contain at least one uppercase letter.\n");
        return 0;
    }

    //Checking for lowercase letters
    int lowercase = checkLowerCase(password);
    if (lowercase == 0){
        printf("Password must contain at least one lowercase letter.\n");
        return 0;
    }

    //Checking for digits
    int digit = checkDigit(password);
    if (digit == 0){
        printf("Password must contain at least one digit.\n");
        return 0;
    }

    //Checking for special characters
    int special = checkSpecial(password);
    if (special == 0){
        printf("Password must contain at least one special character.\n");
        return 0;
    }

    printf("Congratulations! Your password is strong and secure.\n");
    return 0;
}

//Function to check length
int checkLength(char password[]){
    int len = strlen(password);
    if(len >= 8){
        return len;
    }else{
        return 0;
    }
}

//Function to check for uppercase letters
int checkUpperCase(char password[]){
    int i, len = strlen(password);
    for(i=0;i<len;i++){
        if(password[i]>='A' && password[i]<='Z'){
            return 1;
        }
    }
    return 0;
}

//Function to check for lowercase letters
int checkLowerCase(char password[]){
    int i, len = strlen(password);
    for(i=0;i<len;i++){
        if(password[i]>='a' && password[i]<='z'){
            return 1;
        }
    }
    return 0;
}

//Function to check for digits
int checkDigit(char password[]){
    int i, len = strlen(password);
    for(i=0;i<len;i++){
        if(password[i]>='0' && password[i]<='9'){
            return 1;
        }
    }
    return 0;
}

//Function to check for special characters
int checkSpecial(char password[]){
    int i, len = strlen(password);
    for(i=0;i<len;i++){
        if((password[i]>='!' && password[i]<='/') || 
        (password[i]>=':' && password[i]<='@')){
            return 1;
        }
    }
    return 0;
}