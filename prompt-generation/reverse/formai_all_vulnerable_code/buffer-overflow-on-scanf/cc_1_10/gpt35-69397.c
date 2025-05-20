//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: shocked
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool check_length(char password[]){
    if(strlen(password) < 8) {
        return false;
    }
    else {
        return true;
    }
}

bool check_uppercase(char password[]){
    int i;
    for(i=0; password[i]!='\0'; i++){
        if(password[i] >= 'A' && password[i] <= 'Z'){
            return true;
        }
    }
    return false;
}

bool check_lowercase(char password[]){
    int i;
    for(i=0; password[i]!='\0'; i++){
        if(password[i] >= 'a' && password[i] <= 'z'){
            return true;
        }
    }
    return false;
}

bool check_special(char password[]){
    int i;
    for(i=0; password[i]!='\0'; i++){
        if((password[i] >= '!' && password[i] <= '/') || (password[i] >= ':' && password[i] <= '@') || (password[i] >= '[' && password[i] <= '`') || (password[i] >= '{' && password[i] <='~')){
            return true;
        }
    }
    return false;
}

bool check_number(char password[]){
    int i;
    for(i=0; password[i]!='\0'; i++){
        if(password[i] >= '0' && password[i] <= '9'){
            return true;
        }
    }
    return false;
}

int main(){
    char password[50];
    printf("Enter Password: ");
    scanf("%s", password);
    
    bool is_length = check_length(password);
    bool is_uppercase = check_uppercase(password);
    bool is_lowercase = check_lowercase(password);
    bool is_special = check_special(password);
    bool is_number = check_number(password);
    
    printf("\nPassword Strength: ");
    
    if(is_length==true && is_uppercase==true && is_lowercase==true && is_special==true && is_number==true){
            printf("Strong\n");
    }
    else if((is_length==true && is_uppercase==true && is_lowercase==true && is_special==true) || (is_length==true && is_uppercase==true && is_lowercase==true && is_number==true) || (is_length==true && is_lowercase==true && is_special==true && is_number==true) || (is_length==true && is_uppercase==true && is_special==true && is_number==true)){
        printf("Moderate\n");
    }
    else{
        printf("Weak\n");
    }
    
    return 0;
}