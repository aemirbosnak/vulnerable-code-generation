//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int check_length(char* password) {
    int length = strlen(password);
    return length >= 8 && length <= 20;
}

int check_case(char* password) {
    int upper_case = 0, lower_case = 0;
    for(int i = 0; i < strlen(password); i++) {
        if(isupper(password[i]))
            upper_case = 1;
        else if(islower(password[i]))
            lower_case = 1;
    }
    return upper_case && lower_case;
}

int check_digit(char* password) {
    for(int i = 0; i < strlen(password); i++) {
        if(isdigit(password[i]))
            return 1;
    }
    return 0;
}

int check_special(char* password) {
    for(int i = 0; i < strlen(password); i++) {
        if(!isalnum(password[i]))
            return 1;
    }
    return 0;
}

int main() {
    char password[50];
    printf("Enter a password: ");
    scanf("%s", password);
    
    if(!check_length(password)) {
        printf("Password must be between 8 and 20 characters long.\n");
        return 0;
    }
    
    if(!check_case(password)) {
        printf("Password must contain at least one uppercase and one lowercase letter.\n");
        return 0;
    }
    
    if(!check_digit(password)) {
        printf("Password must contain at least one digit.\n");
        return 0;
    }
    
    if(!check_special(password)) {
        printf("Password must contain at least one special character.\n");
        return 0;
    }
    
    printf("Password is strong.\n");
    
    return 0;
}