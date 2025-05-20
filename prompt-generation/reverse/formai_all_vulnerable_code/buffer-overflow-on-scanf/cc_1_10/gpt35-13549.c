//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: energetic
#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 16
#define NUM_SPECIAL_CHARS 6

char special_chars[NUM_SPECIAL_CHARS] = {'!', '@', '#', '$', '%', '&'};

int check_password_length(char *password) {
    int length = strlen(password);
    if (length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH) {
        return 0;
    }
    return 1;
}

int check_password_uppercase(char *password) {
    int i;
    for(i=0; i<strlen(password); i++) {
        if(isupper(password[i])) {
            return 1;
        }
    }
    return 0;
}

int check_password_lowercase(char *password) {
    int i;
    for(i=0; i<strlen(password); i++) {
        if(islower(password[i])) {
            return 1;
        }
    }
    return 0;
}

int check_password_digit(char *password) {
    int i;
    for(i=0; i<strlen(password); i++) {
        if(isdigit(password[i])) {
            return 1;
        }
    }
    return 0;
}

int check_password_special(char *password) {
    int i, j;
    for(i=0; i<strlen(password); i++) {
        for(j=0; j<NUM_SPECIAL_CHARS; j++) {
            if(password[i] == special_chars[j]) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Please enter a password (8-16 characters) containing at least one uppercase letter, one lowercase letter, one digit and one special character from the following list: !,@,#,$,%%,&\n");
    scanf("%s", password);
    
    if(!check_password_length(password)) {
        printf("Password must be between 8 and 16 characters in length\n");
        return 1;
    }
    
    if(!check_password_uppercase(password)) {
        printf("Password must contain at least one uppercase letter\n");
        return 1;
    }
    
    if(!check_password_lowercase(password)) {
        printf("Password must contain at least one lowercase letter\n");
        return 1;
    }
    
    if(!check_password_digit(password)) {
        printf("Password must contain at least one digit\n");
        return 1;
    }
    
    if(!check_password_special(password)) {
        printf("Password must contain at least one of the following special characters: !,@,#,$,%%,&\n");
        return 1;
    }
    
    printf("Password strength OK!\n");
    return 0;
}