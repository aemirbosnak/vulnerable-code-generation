//FormAI DATASET v1.0 Category: Password management ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100 // Maximum passwords 

// Password structure
struct Password{
    char name[20];
    char username[20];
    char password[20];
};

// Declaration of functions
void add_password(struct Password passwords[]);
void view_passwords(struct Password passwords[]);
void search_password(struct Password passwords[], char name[]);
void delete_password(struct Password passwords[], char name[]);

int main(){
    printf("Password Management System\n\n");
    printf("1. Add Password\n");
    printf("2. View Passwords\n");
    printf("3. Search Password\n");
    printf("4. Delete Password\n");
    printf("5. Exit\n\n");

    struct Password passwords[MAX]; // Create an array of passwords
    int choice;
    char name[20];

    do{
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: add_password(passwords);
                    break;
            case 2: view_passwords(passwords);
                    break;
            case 3: printf("Enter the name of password to be searched: ");
                    scanf("%s", name);
                    search_password(passwords, name);
                    break;
            case 4: printf("Enter the name of password to be deleted: ");
                    scanf("%s", name);
                    delete_password(passwords, name);
                    break;
            case 5: printf("Exiting...Thank you for using Password Management System\n");
                    break;
            default: printf("Invalid choice. Please enter a valid choice\n\n");
        }
    }while(choice!=5);

    return 0;
}

// Function to add a new password
void add_password(struct Password passwords[]){
    int i=0;

    while(passwords[i].name[0]!='\0')
        i++;

    if(i>=MAX){
        printf("Cannot add more passwords. Maximum passwords reached\n\n");
        return;
    }

    printf("Enter the name of password: ");
    scanf("%s", passwords[i].name);

    printf("Enter the username: ");
    scanf("%s", passwords[i].username);

    printf("Enter the password: ");
    scanf("%s", passwords[i].password);

    printf("Password added successfully\n\n");
}

// Function to view all passwords
void view_passwords(struct Password passwords[]){
    int i=0;

    printf("Name\tUsername\tPassword\n");
    printf("----\t--------\t--------\n");

    while(passwords[i].name[0]!='\0'){
        printf("%s\t%s\t%s\n", passwords[i].name, passwords[i].username, passwords[i].password);
        i++;
    }

    printf("\n");
}

// Function to search a password by its name
void search_password(struct Password passwords[], char name[]){
    int i=0;

    while(passwords[i].name[0]!='\0'){
        if(strcmp(passwords[i].name, name)==0){
            printf("%s\nUsername: %s\nPassword: %s\n\n", passwords[i].name, passwords[i].username, passwords[i].password);
            return;
        }
        i++;
    }

    printf("Password not found\n\n");
}

// Function to delete a password by its name
void delete_password(struct Password passwords[], char name[]){
    int i=0;

    while(passwords[i].name[0]!='\0'){
        if(strcmp(passwords[i].name, name)==0){
            passwords[i].name[0]='\0';
            passwords[i].username[0]='\0';
            passwords[i].password[0]='\0';
            printf("Password deleted successfully\n\n");
            return;
        }
        i++;
    }

    printf("Password not found\n\n");
}