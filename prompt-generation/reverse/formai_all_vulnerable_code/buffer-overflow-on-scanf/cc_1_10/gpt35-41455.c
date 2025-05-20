//FormAI DATASET v1.0 Category: Password management ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 30 // Maximum number of passwords

// Password structure
typedef struct{
    char website[50];
    char username[30];
    char password[30];
}Password;

int count = 0; // Count variable to keep track of number of passwords stored

Password passwords[MAX]; // Array to store passwords

// Function prototypes
void add_password();
void view_passwords();
void search_website();


int main(){
    int choice;

    printf("Welcome to the Password Manager!\n\n");

    while(1){
        printf("Please choose an option:\n");
        printf("1. Add new password\n");
        printf("2. View saved passwords\n");
        printf("3. Search passwords by website\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_password();
                break;
            case 2:
                view_passwords();
                break;
            case 3:
                search_website();
                break;
            case 4:
                printf("\nThank you for using the Password Manager!");
                exit(0); // Exit the program
            default:
                printf("\nInvalid choice, please try again.\n");
        }
    }

    return 0;
}


// Function to add a new password
void add_password(){
    if(count == MAX){
        printf("\nYou have reached the maximum number of passwords that can be stored.\n");
        return;
    }

    Password new_password;

    printf("\nPlease enter the website name: ");
    scanf("%s", new_password.website);

    printf("Please enter the username: ");
    scanf("%s", new_password.username);

    printf("Please enter the password: ");
    scanf("%s", new_password.password);

    passwords[count++] = new_password;

    printf("\nThe password has been added successfully!\n\n");
}


// Function to view all saved passwords
void view_passwords(){
    if(count == 0){
        printf("\nNo passwords have been saved yet.\n\n");
        return;
    }

    printf("\nWebsite\t\tUsername\t\tPassword\n");

    for(int i=0; i<count; i++){
        printf("%s\t\t%s\t\t%s\n", passwords[i].website, passwords[i].username, passwords[i].password);
    }

    printf("\n");
}


// Function to search for a stored password b website
void search_website(){
    if(count == 0){
        printf("\nNo passwords have been saved yet.\n\n");
        return;
    }

    char website[50];
    int found = 0;

    printf("\nPlease enter the website name to search for: ");
    scanf("%s", website);

    for(int i=0; i<count; i++){
        if(strcmp(passwords[i].website, website) == 0){
            found = 1;
            printf("\nWebsite: %s\n", passwords[i].website);
            printf("Username: %s\n", passwords[i].username);
            printf("Password: %s\n", passwords[i].password);
            break;
        }
    }

    if(!found){
        printf("\nThe website you searched for could not be found.\n\n");
    }
}