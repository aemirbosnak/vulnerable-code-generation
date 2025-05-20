//Falcon-180B DATASET v1.0 Category: Password management ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100

typedef struct {
    char username[50];
    char password[100];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    char username[50];
    char password[100];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    strcpy(passwords[numPasswords].username, username);
    strcpy(passwords[numPasswords].password, password);

    numPasswords++;
}

void viewPasswords() {
    int i;

    printf("\nUsername\t\tPassword\n");
    for(i=0; i<numPasswords; i++) {
        printf("%s\t\t%s\n", passwords[i].username, passwords[i].password);
    }
}

void searchPassword() {
    char searchUsername[50];
    int i;

    printf("Enter username to search: ");
    scanf("%s", searchUsername);

    for(i=0; i<numPasswords; i++) {
        if(strcmp(passwords[i].username, searchUsername) == 0) {
            printf("\nUsername: %s\nPassword: %s\n", passwords[i].username, passwords[i].password);
            break;
        }
    }
}

void main() {
    int choice;

    do {
        printf("\nPassword Manager\n");
        printf("1. Add Password\n2. View Passwords\n3. Search Password\n4. Exit\n");
        printf("Enter your choice: ");
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
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 4);
}