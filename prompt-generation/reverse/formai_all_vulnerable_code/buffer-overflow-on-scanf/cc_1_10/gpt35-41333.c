//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 16

int checkPasswordLength(char *password){
    int length = strlen(password);
    if(length < MIN_LENGTH){
        printf("Password is too short. It should be at least %d characters long.\n", MIN_LENGTH);
        return 0;
    }else if(length > MAX_LENGTH){
        printf("Password is too long. It should be at most %d characters long.\n", MAX_LENGTH);
        return 0;
    }else{
        return 1;
    }
}

int checkPasswordContent(char *password){
    int containsUppercase = 0;
    int containsLowercase = 0;
    int containsDigit = 0;
    int containsSpecialChar = 0;
    
    for(int i = 0; i < strlen(password); i++){
        if(isupper(password[i])){
            containsUppercase = 1;
        }else if(islower(password[i])){
            containsLowercase = 1;
        }else if(isdigit(password[i])){
            containsDigit = 1;
        }else{
            containsSpecialChar = 1;
        }
    }
    
    if(!containsUppercase){
        printf("Password should contain at least one uppercase character.\n");
        return 0;
    }else if(!containsLowercase){
        printf("Password should contain at least one lowercase character.\n");
        return 0;
    }else if(!containsDigit){
        printf("Password should contain at least one digit.\n");
        return 0;
    }else if(!containsSpecialChar){
        printf("Password should contain at least one special character.\n");
        return 0;
    }else{
        return 1;
    }
}

int main(){
    printf("Please enter a password to check its strength:\n");
    char password[MAX_LENGTH+1];
    scanf("%s", password);
    
    int validLength = checkPasswordLength(password);
    int validContent = checkPasswordContent(password);
    
    if(validLength && validContent){
        printf("Congratulations! Your password is strong.");
    }else{
        printf("Sorry, your password is not strong enough. Please try again.");
    }
    
    return 0;
}