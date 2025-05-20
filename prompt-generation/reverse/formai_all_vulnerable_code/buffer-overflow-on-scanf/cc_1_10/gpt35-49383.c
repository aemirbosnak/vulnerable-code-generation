//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 16

int check_uppercase(char *password) {
    int len = strlen(password);
    int i;
    for(i = 0; i < len; i++) {
        if(isupper(password[i])) {
            return 1;
        }
    }
    return 0;
}

int check_lowercase(char *password) {
    int len = strlen(password);
    int i;
    for(i = 0; i < len; i++) {
        if(islower(password[i])) {
            return 1;
        }
    }
    return 0;
}

int check_digit(char *password) {
    int len = strlen(password);
    int i;
    for(i = 0; i < len; i++) {
        if(isdigit(password[i])) {
            return 1;
        }
    }
    return 0;
}

int check_special_char(char *password) {
    int len = strlen(password);
    int i;
    for(i = 0; i < len; i++) {
        if(!isalnum(password[i])) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char password[MAX_PASSWORD_LENGTH + 1];
    printf("Enter your password: ");
    scanf("%s", password);
    int len = strlen(password);
    if(len < MIN_PASSWORD_LENGTH) {
        printf("Password too short.\n");
        exit(EXIT_SUCCESS);
    }
    if(len > MAX_PASSWORD_LENGTH) {
        printf("Password too long.\n");
        exit(EXIT_SUCCESS);
    }
    if(check_uppercase(password) == 0) {
        printf("Password must contain at least one uppercase letter.\n");
        exit(EXIT_SUCCESS);
    }
    if(check_lowercase(password) == 0) {
        printf("Password must contain at least one lowercase letter.\n");
        exit(EXIT_SUCCESS);
    }
    if(check_digit(password) == 0) {
        printf("Password must contain at least one digit.\n");
        exit(EXIT_SUCCESS);
    }
    if(check_special_char(password) == 0) {
        printf("Password must contain at least one special character.\n");
        exit(EXIT_SUCCESS);
    }
    printf("Password is strong.\n");
    return 0;
}