//FormAI DATASET v1.0 Category: Password management ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

// function to check if the entered password meets the requirements
int check_password(char* password){
    int length=0,upper=0,lower=0,numeric=0,special=0;
    for(int i=0;password[i]!='\0';i++){
        length++;
        if(isupper(password[i])) upper++;
        if(islower(password[i])) lower++;
        if(isdigit(password[i])) numeric++;
        if(!isalnum(password[i])) special++;
    }
    if(length<8 || upper<1 || lower<1 || numeric<1 || special<1){
        return 0; // password does not meet the requirements
    }
    return 1; // password meets the requirements
}

// structure for storing username and password
struct credentials{
    char username[20];
    char password[20];
};

int main(){
    struct credentials database[50]; // creating a database to store username and password
    int n = 0;
    int choice;
    while(1){ // infinite loop to keep the program running until the user chooses to exit
        printf("Welcome to the Medieval Password Management System!\n");
        printf("Choose an option:\n");
        printf("1. Add a new username and password.\n");
        printf("2. View all stored usernames and passwords.\n");
        printf("3. Exit.\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                printf("Enter the new username (maximum 20 characters): ");
                scanf("%s",database[n].username);
                printf("Enter the new password (minimum 8 characters with at least 1 uppercase letter, 1 lowercase letter, 1 numeric digit, and 1 special character): ");
                scanf("%s",database[n].password);
                while(check_password(database[n].password)!=1){ // if the entered password does not meet the requirements, keep prompting the user to enter a new password
                    printf("Invalid Password! Password must be at least 8 characters with at least 1 uppercase letter, 1 lowercase letter, 1 numeric digit, and 1 special character.\n");
                    printf("Enter the new password: ");
                    scanf("%s",database[n].password);
                }
                printf("\nNew username and password added to the database!\n");
                printf("Press any key to continue.\n");
                getchar();
                getchar();
                n++;
                break;
            }
            case 2:{
                printf("The stored usernames and passwords are:\n");
                for(int i=0;i<n;i++){
                    printf("%s : %s\n",database[i].username,database[i].password);
                }
                printf("Press any key to continue.\n");
                getchar();
                getchar();
                break;
            }
            case 3:{
                printf("Thank you for using the Medieval Password Management System!\n");
                exit(0); // exit the program 
                break;
            }
            default:{
                printf("Invalid input! Please choose an option 1-3.\n");
                printf("Press any key to continue.\n");
                getchar();
                getchar();
                break;
            }
        }
    }
    return 0;
}