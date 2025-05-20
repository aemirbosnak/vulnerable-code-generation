//FormAI DATASET v1.0 Category: Password management ; Style: creative
#include<stdio.h>
#include<string.h>

#define MAX_LENGTH 100

// function to check if password is strong enough
int is_strong(char *pass){
    int upper=0, lower=0, digit=0, special=0, len;

    len = strlen(pass);

    if(len < 8){
        return 0;
    }

    for(int i=0;i<len;i++){
        if(pass[i]>='a' && pass[i]<='z'){
            lower++;
        }
        else if(pass[i]>='A' && pass[i]<='Z'){
            upper++;
        }
        else if(pass[i]>='0' && pass[i]<='9'){
            digit++;
        }
        else{
            special++;
        }
    }

    if(upper>=1 && lower>=1 && digit>=1 && special>=1){
        return 1;
    }

    return 0;
}

// main function
int main(){

    char password[MAX_LENGTH];
    char confirm_pass[MAX_LENGTH];
    int attempts = 3;

    printf("Enter a strong password: ");
    scanf("%s", password);

    while(!is_strong(password)){

        attempts--;

        if(attempts==0){
            printf("You have exceeded the maximum number of attempts. Program Exiting.\n");
            return 0;
        }

        printf("Password is not strong enough. Try again.\n");
        printf("(You have %d attempts remaining)\n",attempts);
        printf("Enter a strong password: ");
        scanf("%s", password);
    }

    printf("Password is strong enough!\n");

    // encrypting password
    for(int i=0;i<strlen(password);i++){
        password[i] = password[i] + i;
    }

    printf("Password encrypted!\n");

    // confirm password
    printf("Confirm password: ");
    scanf("%s", confirm_pass);

    while(strcmp(password,confirm_pass)!=0){

        attempts--;

        if(attempts==0){
            printf("You have exceeded the maximum number of attempts. Program Exiting.\n");
            return 0;
        }

        printf("Passwords do not match. Try again.\n");
        printf("(You have %d attempts remaining)\n",attempts);
        printf("Confirm password: ");
        scanf("%s", confirm_pass);
    }

    printf("Passwords match!\n");

    // succesfully changing password
    printf("Password changed successfully!");

    return 0;
}