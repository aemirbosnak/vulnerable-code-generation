//FormAI DATASET v1.0 Category: Password management ; Style: lively
#include <stdio.h>
#include <string.h>

//Structure to hold password data
typedef struct {
    char website[20];
    char username[20];
    char password[20];
} Password;

//Function declarations
void add_password();
void view_passwords();
void update_password();

//Array of Password structures to hold password data
Password passwords[10];
//Variable to keep track of the number of passwords stored
int numPasswords = 0;

int main() {
    int choice;

    printf("Welcome to Password Manager!\n");

    //Loop to display menu and get user choice
    do {
        printf("\nMenu:\n");
        printf("1. Add a password\n");
        printf("2. View passwords\n");
        printf("3. Update a password\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        //Switch statement to perform user's chosen action
        switch(choice) {
            case 1:
                add_password();
                break;
            case 2:
                view_passwords();
                break;
            case 3:
                update_password();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice != 4);

    return 0;
}

//Function to add a password to the password database
void add_password() {
    Password newPass;

    printf("Enter website name: ");
    scanf("%s", newPass.website);

    printf("Enter username: ");
    scanf("%s", newPass.username);

    printf("Enter password: ");
    scanf("%s", newPass.password);

    //Add the new password to the passwords array
    passwords[numPasswords] = newPass;
    numPasswords++;

    printf("Password added successfully!\n");
}

//Function to view all passwords stored in the password database
void view_passwords() {
    if(numPasswords == 0) {
        printf("No passwords stored.\n");
        return;
    }

    printf("Website          Username          Password\n");
    printf("------------------------------------------------\n");

    for(int i=0; i<numPasswords; i++) {
        printf("%-16s %-16s %s\n", passwords[i].website, passwords[i].username, passwords[i].password);
    }
}

//Function to update an existing password in the password database
void update_password() {
    char website[20];
    int passwordIndex = -1;

    printf("Enter website name: ");
    scanf("%s", website);

    //Loop to find the index of the password to be updated
    for(int i=0; i<numPasswords; i++) {
        if(strcmp(website, passwords[i].website) == 0) {
            passwordIndex = i;
            break;
        }
    }

    if(passwordIndex == -1) {
        printf("Password not found.\n");
        return;
    }

    printf("Enter new username: ");
    scanf("%s", passwords[passwordIndex].username);

    printf("Enter new password: ");
    scanf("%s", passwords[passwordIndex].password);

    printf("Password updated successfully!\n");
}