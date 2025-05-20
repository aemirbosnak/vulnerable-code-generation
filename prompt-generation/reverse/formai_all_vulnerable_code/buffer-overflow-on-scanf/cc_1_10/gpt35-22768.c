//FormAI DATASET v1.0 Category: System administration ; Style: curious
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

//Function to get password and check for dictionary words
int is_valid_password(char password[]){
    char line[1000];
    FILE *fptr;
    fptr=fopen("dictionary.txt","r");
    if(fptr == NULL){
        return 1; //If file doesn't exist, consider password valid
    }
    else{
        while(fgets(line,1000,fptr)){
            if(strstr(password, line) != NULL){
                return 0; //If dictionary word found, consider password invalid
            }
        }
    }
    fclose(fptr);
    return 1; //If no dictionary words found, consider password valid
}

//Main function
int main(){
    char username[20],password[20],confirm_password[20];
    int flag=0;

    printf("Welcome to the System Administration Portal!\n");
    printf("Please create your account with a strong password\n");

    //Take input for username
    printf("Enter your username: ");
    scanf("%s",username);

    //Take input for password
    do{
        printf("Enter password (minimum length - 8, atleast one uppercase, one lowercase, one digit and one special character): ");
        scanf("%s",password);

        //Check for password length
        if(strlen(password) < 8){
            printf("Error: Password too short!\n");
            flag=1;
        }

        //Check for at least one uppercase letter
        int i,count_upper=0,count_lower=0,count_digit=0,count_special=0;
        for(i=0;i<strlen(password);i++){
            if(isupper(password[i])){
                count_upper++;
            }
            else if(islower(password[i])){
                count_lower++;
            }
            else if(isdigit(password[i])){
                count_digit++;
            }
            else if(ispunct(password[i])){
                count_special++;
            }
        }

        if(count_upper < 1){
            printf("Error: Password must contain at least one uppercase letter!\n");
            flag=1;
        }

        //Check for at least one lowercase letter
        if(count_lower < 1){
            printf("Error: Password must contain at least one lowercase letter!\n");
            flag=1;
        }

        //Check for at least one digit
        if(count_digit < 1){
            printf("Error: Password must contain at least one digit!\n");
            flag=1;
        }

        //Check for at least one special character
        if(count_special < 1){
            printf("Error: Password must contain at least one special character!\n");
            flag=1;
        }

        //Check for dictionary words
        if(is_valid_password(password) == 0){
            printf("Error: Password cannot contain dictionary words!\n");
            flag=1;
        }

    }while(flag);

    //Confirm password
    printf("\nConfirm password: ");
    scanf("%s",confirm_password);

    if(strcmp(password,confirm_password) != 0){
        printf("\nError: Passwords do not match! Please try again.\n");
        return 0;
    }

    //If all conditions satisfied, create account
    printf("\nCongratulations! Account created successfully!");
    printf("\nUsername: %s",username);
    printf("\nPassword: %s",password);

    return 0;
}