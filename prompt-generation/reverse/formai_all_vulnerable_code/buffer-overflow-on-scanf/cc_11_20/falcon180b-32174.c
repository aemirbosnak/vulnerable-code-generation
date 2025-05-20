//Falcon-180B DATASET v1.0 Category: Password management ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 64
#define MAX_USERNAME_LENGTH 32

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

int main() {
    char choice;
    int numPasswords = 0;
    Password passwords[MAX_PASSWORDS];

    do {
        printf("\n\nPassword Manager\n");
        printf("------------------\n");
        printf("1. Add password\n");
        printf("2. Edit password\n");
        printf("3. Delete password\n");
        printf("4. View all passwords\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                if(numPasswords == MAX_PASSWORDS) {
                    printf("Maximum number of passwords reached.\n");
                } else {
                    printf("Enter username: ");
                    scanf("%s", passwords[numPasswords].username);
                    printf("Enter password: ");
                    scanf("%s", passwords[numPasswords].password);
                    numPasswords++;
                    printf("\nPassword added successfully.\n");
                }
                break;
            case '2':
                printf("Enter username of the password you want to edit: ");
                scanf("%s", passwords[0].username);
                for(int i=0; i<numPasswords; i++) {
                    if(strcmp(passwords[i].username, passwords[0].username) == 0) {
                        printf("Enter new password: ");
                        scanf("%s", passwords[i].password);
                        printf("\nPassword updated successfully.\n");
                        break;
                    }
                }
                break;
            case '3':
                printf("Enter username of the password you want to delete: ");
                scanf("%s", passwords[0].username);
                for(int i=0; i<numPasswords; i++) {
                    if(strcmp(passwords[i].username, passwords[0].username) == 0) {
                        strcpy(passwords[i].username, "");
                        strcpy(passwords[i].password, "");
                        numPasswords--;
                        printf("\nPassword deleted successfully.\n");
                        break;
                    }
                }
                break;
            case '4':
                printf("\nUsername\t\tPassword\n");
                for(int i=0; i<numPasswords; i++) {
                    if(strcmp(passwords[i].username, "")!= 0 && strcmp(passwords[i].password, "")!= 0) {
                        printf("%s\t\t%s\n", passwords[i].username, passwords[i].password);
                    }
                }
                break;
            case '5':
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while(choice!= '5');

    return 0;
}