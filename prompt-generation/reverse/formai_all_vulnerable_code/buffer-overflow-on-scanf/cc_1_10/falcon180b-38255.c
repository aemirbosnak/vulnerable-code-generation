//Falcon-180B DATASET v1.0 Category: Password management ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

int main() {
    char choice;
    int numPasswords = 0;
    Password passwords[MAX_PASSWORDS];

    do {
        printf("Welcome to the password manager!\n");
        printf("Please enter your choice:\n");
        printf("1. Add a new password\n");
        printf("2. Remove a password\n");
        printf("3. View all passwords\n");
        printf("4. Exit\n");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                printf("Enter the username: ");
                scanf("%s", passwords[numPasswords].username);
                printf("Enter the password: ");
                scanf("%s", passwords[numPasswords].password);
                numPasswords++;
                break;
            case '2':
                printf("Enter the username of the password you want to remove: ");
                scanf("%s", passwords[numPasswords].username);
                for(int i=0; i<numPasswords; i++) {
                    if(strcmp(passwords[i].username, passwords[numPasswords].username) == 0) {
                        for(int j=i; j<numPasswords-1; j++) {
                            strcpy(passwords[j].username, passwords[j+1].username);
                            strcpy(passwords[j].password, passwords[j+1].password);
                        }
                        numPasswords--;
                        break;
                    }
                }
                break;
            case '3':
                printf("Username\tPassword\n");
                for(int i=0; i<numPasswords; i++) {
                    printf("%s\t%s\n", passwords[i].username, passwords[i].password);
                }
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while(choice!= '4');

    return 0;
}