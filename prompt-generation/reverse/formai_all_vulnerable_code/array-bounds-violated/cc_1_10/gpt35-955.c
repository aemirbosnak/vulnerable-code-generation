//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Claude Shannon
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_PASS_LENGTH 50 // Maximum allowed password length

bool has_upper(char *password){
    for(int i=0; i<strlen(password); i++){
        if(isupper(password[i])){
            return true;
        }
    }
    return false;
}

bool has_lower(char *password){
    for(int i=0; i<strlen(password); i++){
        if(islower(password[i])){
            return true;
        }
    }
    return false;
}

bool has_digit(char *password){
    for(int i=0; i<strlen(password); i++){
        if(isdigit(password[i])){
            return true;
        }
    }
    return false;
}

bool has_special(char *password){
    for(int i=0; i<strlen(password); i++){
        if(!isalnum(password[i])){
            return true;
        }
    }
    return false;
}

int get_password_strength(char* password){
    int strength = 0;
    bool has_uppercase = has_upper(password);
    bool has_lowercase = has_lower(password);
    bool has_digit_char = has_digit(password);
    bool has_special_char = has_special(password);
    int pass_length = strlen(password);

    // Check pass length
    if(pass_length >= 8){
        strength += 1;
    }
    if(pass_length >= 12){
        strength += 1;
    }

    // Check lower case
    if(has_lowercase){
        strength += 1;
    }

    // Check upper case
    if(has_uppercase){
        strength += 1;
    }

    // Check digit
    if(has_digit_char){
        strength += 1;
    }
    
    // Check Special Character
    if(has_special_char){
        strength += 1;
    }

    return strength;
}

int main(){
    char password[MAX_PASS_LENGTH];

    printf("Enter your password: ");
    fgets(password, MAX_PASS_LENGTH, stdin);  // Read password from user input

    // Remove the newline character from the end of the password
    int password_length = strlen(password);
    if (password[password_length - 1] == '\n') {
        password[password_length - 1] = '\0';
    }

    int password_strength = get_password_strength(password);
    
    // Print message based on password strength
    switch(password_strength){
        case 0:
            printf("Your password is very weak\n");
            break;
        case 1:
            printf("Your password is weak\n");
            break;
        case 2:
            printf("Your password is medium\n");
            break;
        case 3:
            printf("Your password is strong\n");
            break;
        case 4:
            printf("Your password is very strong\n");
            break;
        default:
            printf("Invalid password strength\n");
            break;
    }

    return 0;
}