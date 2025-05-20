//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: energetic
#include<stdio.h>
#include<string.h>

int check_password_strength(char password[]){
    int len;
    int is_upper = 0, is_lower = 0, has_digit = 0, has_special = 0;
    
    len = strlen(password);
    
    if(len < 8){
        return 0;
    }
    
    for(int i=0; i<len; i++){
        if(password[i] >= 'A' && password[i] <= 'Z'){
            is_upper = 1;
        }
        if(password[i] >= 'a' && password[i] <= 'z'){
            is_lower = 1;
        }
        if(password[i] >= '0' && password[i] <= '9'){
            has_digit = 1;
        }
        if((password[i] >= '!' && password[i] <= '/') || (password[i] >= ':' && password[i] <= '@')){
            has_special = 1;
        }
    }
    
    if(is_upper && is_lower && has_digit && has_special){
        return 1;
    }
    return 0;
}

int main(){
    char password[50];
    int strength;
    
    printf("Enter your password: ");
    scanf("%s", password);
    
    strength = check_password_strength(password);
    
    if(strength){
        printf("Congratulations! Your password is strong.");
    }else{
        printf("Oops! Your password is not strong enough. Please try again with a stronger password.");
    }
    
    return 0;
}