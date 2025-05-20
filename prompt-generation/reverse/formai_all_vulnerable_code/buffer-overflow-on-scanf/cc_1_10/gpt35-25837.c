//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: distributed
#include<stdio.h>
#include<string.h>

//Function to check if password contains uppercase letters
int containUpperCase(char* password){
    int i, len = strlen(password);
    for(i=0;i<len;i++){
        if(password[i]>='A' && password[i]<='Z')
            return 1;
    }
    return 0;
}

//Function to check if password contains lowercase letters
int containLowerCase(char* password){
    int i, len = strlen(password);
    for(i=0;i<len;i++){
        if(password[i]>='a' && password[i]<='z')
            return 1;
    }
    return 0;
}

//Function to check if password contains digits
int containDigits(char* password){
    int i, len = strlen(password);
    for(i=0;i<len;i++){
        if(password[i]>='0' && password[i]<='9')
            return 1;
    }
    return 0;
}

//Function to check if password contains special characters
int containSpecialChars(char* password){
    int i, len = strlen(password);
    for(i=0;i<len;i++){
        if(!(password[i]>='A' && password[i]<='Z') && !(password[i]>='a' && password[i]<='z') && !(password[i]>='0' && password[i]<='9'))
            return 1;
    }
    return 0;
}

//Function to check password strength
int checkPasswordStrength(char* password){
    if (strlen(password) < 8) //Checking password length
        return 0;
    else if (!containLowerCase(password)) //Checking if password contains lowercase letters
        return 0;
    else if (!containUpperCase(password)) //Checking if password contains uppercase letters
        return 0;
    else if (!containDigits(password)) //Checking if password contains digits
        return 0;
    else if (!containSpecialChars(password)) //Checking if password contains special characters
        return 0;
    else
        return 1;
}

int main(){
    char password[100];
    printf("Enter Password: ");
    scanf("%s",password);
    if(checkPasswordStrength(password))
        printf("Good Password\n");
    else
        printf("Weak Password\n");
    return 0;
}