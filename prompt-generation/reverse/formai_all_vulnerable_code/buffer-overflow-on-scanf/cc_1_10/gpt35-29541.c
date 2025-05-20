//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Function to check if a character is a digit */
int is_digit(char ch){
    if(ch >= '0' && ch <= '9'){
        return 1;
    }
    return 0;
}

/* Function to check if a character is an uppercase letter */
int is_uppercase(char ch){
    if(ch >= 'A' && ch <= 'Z'){
        return 1;
    }
    return 0;
}

/* Function to check if a character is a lowercase letter */
int is_lowercase(char ch){
    if(ch >= 'a' && ch <= 'z'){
        return 1;
    }
    return 0;
}

/* Function to check if a character is a special character */
int is_special(char ch){
    if(ch == '!' || ch == '@' || ch == '#' || ch == '$' || ch == '%' || ch == '^' || ch == '&' || ch == '*' || ch == '(' || ch == ')' || ch == '-' || ch == '+' || ch == '_' || ch == '=' || ch == '{' || ch == '}' || ch == '[' || ch == ']' || ch == ':' || ch == ';' || ch == '"' || ch == '\'' || ch == '<' || ch == '>' || ch == ',' || ch == '.' || ch == '/' || ch == '?' || ch == '|' || ch == '\\'){
        return 1;
    }
    return 0;
}

/* Function to check if the password contains at least one of each type of character */
int is_valid_password(char password[]){
    int has_digit = 0;
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_special = 0;
    int length = strlen(password);
    for(int i=0;i<length;i++){
        if(is_digit(password[i])){
            has_digit = 1;
        } else if(is_uppercase(password[i])){
            has_uppercase = 1;
        } else if(is_lowercase(password[i])){
            has_lowercase = 1;
        } else if(is_special(password[i])){
            has_special = 1;
        }
    }
    if(has_digit && has_uppercase && has_lowercase && has_special){
        return 1;
    }
    return 0;
}

/* Function to calculate the strength of the password */
int password_strength(char password[]){
    int length = strlen(password);
    int strength = 0;
    if(length >= 8){
        strength += 10;
    }
    if(length >= 12){
        strength += 10;
    }
    if(length >= 16){
        strength += 10;
    }
    if(is_valid_password(password)){
        strength += 20;
    }
    return strength;
}

int main(){
    char password[100];
    printf("Enter password: ");
    scanf("%s", password);
    int strength = password_strength(password);
    printf("Password strength: %d\n", strength);
    return 0;
}