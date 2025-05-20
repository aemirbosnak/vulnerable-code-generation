//FormAI DATASET v1.0 Category: Password management ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 50

/* Structure for Password */
typedef struct {
    char website[50];
    char username[50];
    char password[50];
} Password;

/* Function to print all the available passwords */
void printPasswords(Password *passwords) {
    printf("\n******* Stored Passwords *********\n\n");
    printf("Website\t\tUsername\t\tPassword\n");
    printf("---------------------------------------------------------\n");
    for(int i=0; i<MAX_PASSWORDS; i++) {
        if(strcmp(passwords[i].website, "") != 0) {
            printf("%s\t\t%s\t\t%s\n", passwords[i].website, passwords[i].username, passwords[i].password);
        }
    }
}

/* Function to add new password */
void addPassword(Password *passwords) {
    char website[MAX_PASSWORD_LENGTH], username[MAX_PASSWORD_LENGTH], password[MAX_PASSWORD_LENGTH];
    printf("\nAdd Password");
    printf("\nWebsite: ");
    scanf("%s", website);
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    for(int i=0; i<MAX_PASSWORDS; i++) {
        if(strcmp(passwords[i].website, "") == 0) {
            strcpy(passwords[i].website, website);
            strcpy(passwords[i].username, username);
            strcpy(passwords[i].password, password);
            printf("\nPassword added successfully!\n");
            return;
        }
    }
    printf("\nCannot add more passwords. Maximum passwords limit reached.\n");
}

/* Function to search password for a website */
void searchPassword(Password *passwords) {
    char website[MAX_PASSWORD_LENGTH];
    printf("\nEnter the website name to search password for: ");
    scanf("%s", website);

    for(int i=0; i<MAX_PASSWORDS; i++) {
        if(strcmp(passwords[i].website, website) == 0) {
            printf("\nWebsite: %s", passwords[i].website);
            printf("\nUsername: %s", passwords[i].username);
            printf("\nPassword: %s", passwords[i].password);
            return;
        }
    }
    printf("\nNo password found for the given website.\n");
}

/* Function to delete a password for a website */
void deletePassword(Password *passwords) {
    char website[MAX_PASSWORD_LENGTH];
    printf("\nEnter the website name to delete password for: ");
    scanf("%s", website);

    for(int i=0; i<MAX_PASSWORDS; i++) {
        if(strcmp(passwords[i].website, website) == 0) {
            strcpy(passwords[i].website, "");
            strcpy(passwords[i].username, "");
            strcpy(passwords[i].password, "");
            printf("\nPassword deleted successfully from the vault.\n");
            return;
        }
    }
    printf("\nNo password found for the given website.\n");
}

int main(int argc, char const *argv[]) {
    Password passwords[MAX_PASSWORDS] = {{"google.com", "user1", "password1"}, {"facebook.com", "user2", "password2"}};
    int choice;

    while(1) {   // Infinite Loop to run until user exits
        printf("\n\nPassword Vault Menu\n");
        printf("1. Print all passwords\n");
        printf("2. Add new password\n");
        printf("3. Search password\n");
        printf("4. Delete password\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printPasswords(passwords);
                break;
            case 2:
                addPassword(passwords);
                break;
            case 3:
                searchPassword(passwords);
                break;
            case 4:
                deletePassword(passwords);
                break;
            case 5:
                printf("\nExiting Password Vault! Thank you!\n");
                exit(0);
            default:
                printf("\nInvalid Choice! Please enter a valid choice.\n");
        }
    }
    return 0;
}