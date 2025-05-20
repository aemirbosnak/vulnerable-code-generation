//FormAI DATASET v1.0 Category: Password management ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 15 //maximum length of password
#define MAX_ATTEMPTS 3 //maximum number of attempts to enter password

int main(){
    char password[MAX_LENGTH+1]; //array to store password
    int attempts = 0; //count of attempts
    
    printf("Welcome to Password Manager!\n");
    
    //initial login prompt
    printf("Please enter your password (maximum %d characters):\n", MAX_LENGTH);
    scanf("%s",password);
    
    //check if password is correct, maximum attempts reached or invalid input
    while(strcmp(password,"password123") != 0 && attempts < MAX_ATTEMPTS){
        printf("Password incorrect! You have %d attempts remaining.\n", MAX_ATTEMPTS - attempts - 1);
        attempts++;
        printf("Please enter your password (maximum %d characters):\n", MAX_LENGTH);
        scanf("%s",password);
    }
    
    if(attempts == MAX_ATTEMPTS){
        printf("Maximum number of attempts reached. Program terminating.");
        return 0;
    }
    
    //password is correct, user is logged in
    printf("Login successful!\n");
    
    //menu for managing passwords
    int option=0;
    while(option!=4){
        printf("\nMenu:\n");
        printf("1. Add Password\n");
        printf("2. View Password\n");
        printf("3. Delete Password\n");
        printf("4. Exit\n");
        printf("Please enter the option number:\n");
        scanf("%d",&option);
        
        //switch statement for handling different cases
        switch(option){
            case 1: //add new password
                printf("Please enter the website name:\n");
                char website[MAX_LENGTH+1];
                scanf("%s",website);
                printf("Please enter the password (maximum %d characters):\n", MAX_LENGTH);
                char new_password[MAX_LENGTH+1];
                scanf("%s",new_password);
                printf("New password added successfully for %s\n", website);
                break;
                
            case 2: //view password
                printf("Please enter the website name:\n");
                char website2[MAX_LENGTH+1];
                scanf("%s",website2);
                printf("Password for %s: ********\n", website2);
                break;
                
            case 3: //delete password
                printf("Please enter the website name:\n");
                char website3[MAX_LENGTH+1];
                scanf("%s",website3);
                printf("Are you sure you want to delete the password for %s? (y/n)\n", website3);
                char confirmation;
                scanf(" %c",&confirmation);
                if(confirmation=='y' || confirmation=='Y')
                    printf("Password for %s deleted successfully!\n", website3);
                break;
                
            case 4: //exit
                printf("Goodbye!\n");
                break;
                
            default: //invalid input
                printf("Invalid input. Please try again.\n");
                break;
        }
    }
    
    return 0;
}