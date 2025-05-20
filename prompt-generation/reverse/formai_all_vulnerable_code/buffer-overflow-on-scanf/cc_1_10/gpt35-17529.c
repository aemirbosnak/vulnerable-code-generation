//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: modular
#include<stdio.h>
#include<string.h>

/* function prototypes */
int lengthCheck(char password[]);
int uppercaseCheck(char password[]);
int lowercaseCheck(char password[]);
int digitCheck(char password[]);
int specialCharCheck(char password[]);

int main() {
    char password[50];
    int length, upper, lower, digit, special;

    printf("Enter the password to be checked: ");
    scanf("%s", password);

    /* password strength checking */
    length = lengthCheck(password);
    upper = uppercaseCheck(password);
    lower = lowercaseCheck(password);
    digit = digitCheck(password);
    special = specialCharCheck(password);

    /* printing the result */
    printf("\nPassword strength check results:\n");

    if(length == 1 && upper == 1 && lower == 1 && digit == 1 && special == 1) {
        printf("The password is strong and meets all the criteria\n");
    } else {
        printf("The password is weak\n");
        if(length == 0) {
            printf("- The password must be at least 8 characters long\n");
        }
        if(upper == 0) {
            printf("- The password must contain an uppercase letter\n");
        }
        if(lower == 0) {
            printf("- The password must contain a lowercase letter\n");
        }
        if(digit == 0) {
            printf("- The password must contain a digit\n");
        }
        if(special == 0) {
            printf("- The password must contain a special character\n");
        }
    }

    return 0;
}


/* function to check the password length */
int lengthCheck(char password[]) {
    int len = strlen(password);
    if(len >= 8) {
        return 1;
    }
    return 0;
}

/* function to check if the password contains an uppercase letter */
int uppercaseCheck(char password[]) {
    int i;
    for(i=0; i<strlen(password); i++) {
        if(password[i]>='A' && password[i]<='Z') {
            return 1;   
        }   
    }
    return 0;
}

/* function to check if the password contains a lowercase letter */
int lowercaseCheck(char password[]) {
    int i;
    for(i=0; i<strlen(password); i++) {
        if(password[i]>='a' && password[i]<='z') {
            return 1;   
        }   
    }
    return 0;
}

/* function to check if the password contains a digit */
int digitCheck(char password[]) {
    int i;
    for(i=0; i<strlen(password); i++) {
        if(password[i]>='0' && password[i]<='9') {
            return 1;   
        }   
    }
    return 0;
}

/* function to check if the password contains a special character */
int specialCharCheck(char password[]) {
    int i;
    for(i=0; i<strlen(password); i++) {
        if(password[i]>=' ' && password[i]<='/') {
            return 1;   
        }   
    }
    return 0;
}