//Falcon-180B DATASET v1.0 Category: Password management ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    if(numPasswords >= MAX_PASSWORDS) {
        printf("Sorry, you have reached the maximum number of passwords.\n");
        return;
    }

    printf("Enter the name of the website or service:\n");
    scanf("%s", passwords[numPasswords].name);

    printf("Enter the password:\n");
    scanf("%s", passwords[numPasswords].password);

    numPasswords++;

    printf("Password added successfully.\n");
}

void viewPasswords() {
    if(numPasswords == 0) {
        printf("No passwords found.\n");
        return;
    }

    printf("Name\t\tPassword\n");
    for(int i=0; i<numPasswords; i++) {
        printf("%s\t%s\n", passwords[i].name, passwords[i].password);
    }
}

void searchPassword() {
    if(numPasswords == 0) {
        printf("No passwords found.\n");
        return;
    }

    printf("Enter the name of the website or service to search for:\n");
    char searchName[MAX_PASSWORD_LENGTH];
    scanf("%s", searchName);

    int found = 0;
    for(int i=0; i<numPasswords; i++) {
        if(strcmp(passwords[i].name, searchName) == 0) {
            printf("Name: %s\nPassword: %s\n", passwords[i].name, passwords[i].password);
            found = 1;
        }
    }

    if(!found) {
        printf("Password not found.\n");
    }
}

void deletePassword() {
    if(numPasswords == 0) {
        printf("No passwords found.\n");
        return;
    }

    printf("Enter the name of the website or service to delete:\n");
    char deleteName[MAX_PASSWORD_LENGTH];
    scanf("%s", deleteName);

    int found = 0;
    for(int i=0; i<numPasswords; i++) {
        if(strcmp(passwords[i].name, deleteName) == 0) {
            memset(passwords[i].name, 0, MAX_PASSWORD_LENGTH);
            memset(passwords[i].password, 0, MAX_PASSWORD_LENGTH);
            numPasswords--;
            found = 1;
        }
    }

    if(!found) {
        printf("Password not found.\n");
    }
}

int main() {
    printf("Welcome to the password manager.\n");

    int choice;
    do {
        printf("1. Add password\n");
        printf("2. View passwords\n");
        printf("3. Search password\n");
        printf("4. Delete password\n");
        printf("5. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addPassword();
                break;
            case 2:
                viewPasswords();
                break;
            case 3:
                searchPassword();
                break;
            case 4:
                deletePassword();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 5);

    return 0;
}