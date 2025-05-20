//FormAI DATASET v1.0 Category: Password management ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

//maximum number of passwords that can be stored
#define MAX_PASSWORDS 100

//maximum length of the password
#define MAX_PASSWORD_LEN 30

//structure to store password
typedef struct password {
    char website[50];
    char username[50];
    char pass[MAX_PASSWORD_LEN+1]; //+1 for \0 
} password;

//global variables
password passwords[MAX_PASSWORDS];
unsigned int num_passwords = 0;

//function prototypes
void menu();
void add_password();
void list_passwords();
void search_password();

int main() {
    menu();
    return 0;
}

//displays the menu and waits for user input
void menu() {
    char choice;
    do {
        printf("\nPassword Manager\n");
        printf("1. Add a password\n");
        printf("2. List all passwords\n");
        printf("3. Search for a password\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                add_password();
                break;
            case '2':
                list_passwords();
                break;
            case '3':
                search_password();
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid input! Try again.\n");
                break;
        }
    } while(choice != '4');
}

//adds a new password to the store
void add_password() {
    // check if we have reached the maximum number of passwords
    if(num_passwords >= MAX_PASSWORDS) {
        printf("Cannot add more passwords.\n");
        return;
    } 

    // ask for website, username and password
    password new_password;
    printf("Enter the website: ");
    scanf("%s", new_password.website); //do not use & for arrays

    printf("Enter the username: ");
    scanf("%s", new_password.username);

    printf("Enter the password (max %d characters): ", MAX_PASSWORD_LEN);
    scanf("%s", new_password.pass);

    //add the new password to the array
    passwords[num_passwords++] = new_password;

    printf("Password added successfully!\n");   
}

//displays a list of all passwords
void list_passwords() {
    if(num_passwords == 0) {
        printf("No passwords saved yet.\n");
        return;
    }

    printf("Listing all passwords:\n");
    for(int i=0;i<num_passwords;i++) {
        printf("Website: %s | Username: %s | Password: %s\n", 
            passwords[i].website, passwords[i].username, passwords[i].pass);
    }
}

//searches for a password by website or username
void search_password() {
    if(num_passwords == 0) {
        printf("No passwords saved yet.\n");
        return;
    }

    char search_query[MAX_PASSWORD_LEN+1];
    printf("Enter the website or username to search: ");
    scanf("%s", search_query);

    int matches = 0;
    for(int i=0;i<num_passwords;i++) {
        if(strcmp(search_query, passwords[i].website)==0 || strcmp(search_query, passwords[i].username)==0) {
            printf("Website: %s | Username: %s | Password: %s\n", 
                passwords[i].website, passwords[i].username, passwords[i].pass);
            matches++;
        }
    }

    if(matches == 0) {
        printf("No password matches found.\n");
    } else {
        printf("%d password matches found.\n", matches);
    }
}