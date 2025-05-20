//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

//Function to generate a secure password
char* generatePassword(int length){
    //List of characters to be used to generate password
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_+-=";
    
    //Calculate the size of the character set
    int charsetSize = strlen(charset);
    
    //Allocate memory for the password
    char* password = malloc(sizeof(char) * (length + 1));
    
    //Seed the random number generator
    srand(time(NULL));
    
    //Generate the password
    int i;
    for(i = 0; i < length; i++){
        password[i] = charset[rand() % charsetSize];
    }
    
    password[length] = '\0';
    return password;
}

int main(){
    int passwordLength;
    printf("Welcome to Secure Password Generator!\n");
    printf("Please enter the desired length of the password (minimum 8): ");
    scanf("%d", &passwordLength);
    
    //Ensure password length is at least 8 characters long
    if(passwordLength < 8){
        printf("Error: Password length must be at least 8 characters long\n");
        return 0;
    }
    
    //Generate the password
    char* password = generatePassword(passwordLength);
    
    //Check if password contains at least one uppercase letter, lowercase letter, and special character
    int i, containsLower = 0, containsUpper = 0, containsSpecial = 0;
    for(i = 0; i < passwordLength; i++){
        if(islower(password[i])){
            containsLower = 1;
        } else if(isupper(password[i])){
            containsUpper = 1;
        } else if(!isdigit(password[i]) && !isalpha(password[i])){
            containsSpecial = 1;
        }
    }
    
    //If password does not meet requirements, generate a new password
    while(!containsLower || !containsUpper || !containsSpecial){
        free(password);
        password = generatePassword(passwordLength);
        
        containsLower = 0;
        containsUpper = 0;
        containsSpecial = 0;
        for(i = 0; i < passwordLength; i++){
            if(islower(password[i])){
                containsLower = 1;
            } else if(isupper(password[i])){
                containsUpper = 1;
            } else if(!isdigit(password[i]) && !isalpha(password[i])){
                containsSpecial = 1;
            }
        }
    }
    
    //Print the generated password
    printf("Your secure password is: %s\n", password);
    
    //Free the allocated memory for the password
    free(password);
    
    return 0;
}