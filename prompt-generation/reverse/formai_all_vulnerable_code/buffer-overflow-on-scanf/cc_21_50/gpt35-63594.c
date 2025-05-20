//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: peaceful
#include<stdio.h>
#include<string.h>

int main(){
    char password[20];
    int length, upper_case=0, lower_case=0, digit=0, special_char=0, strength=0;
    
    //prompt user to enter password
    printf("Enter your password: ");
    scanf("%s", password);
    
    length = strlen(password);
    
    //check password length
     if(length < 8){
        printf("Weak Password! Password length must be atleast 8 characters.\n");
        return 0;
    }
    else if(length > 20){
        printf("Password length exceeded! Password length should not exceed 20 characters.\n");
        return 0;
    }
    
    //check for upper-case, lower-case, digits and special characters
    for(int i=0; i<length; i++){
        if(password[i] >= 'A' && password[i] <= 'Z'){
            upper_case++;
        }
        else if(password[i] >= 'a' && password[i] <= 'z'){
            lower_case++;
        }
        else if(password[i] >= '0' && password[i] <= '9'){
            digit++;
        }
        else{
            special_char++;
        }
    }
    
    //password strength calculation
    if(upper_case > 0 && lower_case > 0 && digit > 0 && special_char > 0){
        strength = 4;
    }
    else if((upper_case > 0 && lower_case > 0 && digit > 0) || (lower_case > 0 && digit > 0 && special_char > 0) || (digit > 0 && special_char > 0 && upper_case > 0) || (special_char > 0 && lower_case > 0 && upper_case > 0)){
        strength = 3;
    }
    else if((upper_case > 0 && lower_case > 0) || (lower_case > 0 && digit > 0) || (digit > 0 && special_char > 0) || (special_char > 0 && upper_case > 0)){
        strength = 2;
    }
    else{
        strength = 1;
    }

    //print password strength
    switch(strength){
        case 1:
            printf("Your password is very weak. Please use a combination of upper-case, lower-case, digits and special characters.\n");
            break;
        case 2:
            printf("Your password is weak. It must have a combination of upper-case, lower-case, digits and/or special characters.\n");
            break;
        case 3:
            printf("Your password is strong. Use a combination of upper-case, lower-case, digits and/or special characters for more security.\n");
            break;
        case 4:
            printf("Your password is very strong. Congratulations!\n");
            break;
    }
    
    return 0;
}