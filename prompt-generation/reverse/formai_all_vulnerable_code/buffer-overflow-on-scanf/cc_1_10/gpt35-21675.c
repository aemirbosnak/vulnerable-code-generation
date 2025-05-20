//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* This function checks if an input string contains
 * a special character or not */
int hasSpecialChar(char* str)
{
    for(int i=0; i<strlen(str); i++){
        if(str[i]>=33 && str[i]<=47)
            return 1;
        else if(str[i]>=58 && str[i]<=64)
            return 1;
        else if(str[i]>=91 && str[i]<=96)
            return 1;
        else if(str[i]>=123 && str[i]<=126)
            return 1;
    }
    return 0;
}

/* This function checks if an input string contains
 * numbers or not */
int hasNumeric(char* str)
{
    for(int i=0; i<strlen(str); i++){
        if(str[i]>=48 && str[i]<=57)
            return 1;
    }
    return 0;
}

/* This function checks if an input string contains
 * uppercase letters or not */
int hasUpperCase(char* str)
{
    for(int i=0; i<strlen(str); i++){
        if(str[i]>=65 && str[i]<=90)
            return 1;
    }
    return 0;
}

/* This function checks if an input string contains
 * lowercase letters or not */
int hasLowerCase(char* str)
{
    for(int i=0; i<strlen(str); i++){
        if(str[i]>=97 && str[i]<=122)
            return 1;
    }
    return 0;
}

int main()
{
    char password[50];
    int score = 0;

    printf("Enter the password to be checked:\n");
    scanf("%s", password);

    if(strlen(password)<6){
        printf("Password is too short.\n");
        return 0;
    }

    if(hasSpecialChar(password)) score++;
    if(hasNumeric(password)) score++;
    if(hasUpperCase(password)) score++;
    if(hasLowerCase(password)) score++;

    switch(score){
        case 0:
            printf("The password is too weak.\n");
            break;
        case 1:
            printf("The password is weak.\n");
            break;
        case 2:
            printf("The password is moderate.\n");
            break;
        case 3:
            printf("The password is strong.\n");
            break;
        case 4:
            printf("The password is very strong!\n");
            break;
    }

    return 0;
}