//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: innovative
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    char password[50];
    int length=0,lowercase=0,uppercase=0,digit=0,special=0,count=0;
    
    printf("Enter password: ");
    gets(password);
    length = strlen(password);
    
    if(length < 8){
        printf("\nYour password is too short, must be at least 8 characters.");
    }
    else{
        for(int i=0;i<length;i++){
            if(islower(password[i])){
                lowercase++;
            }
            else if(isupper(password[i])){
                uppercase++;
            }
            else if(isdigit(password[i])){
                digit++;
            }
            else{
                special++;
            }
        }
        
        if(lowercase > 0){
            count++;
        }
        if(uppercase > 0){
            count++;
        }
        if(digit > 0){
            count++;
        }
        if(special > 0){
            count++;
        }
        
        if(count < 3){
            printf("\nYour password is weak. It should contain at least 3 of the following: Lowercase letters, Uppercase letters, Digits, and Special characters.");
        }
        else{
            printf("\nYour password is strong!");
        }
    }
    return 0;
}