//Falcon-180B DATASET v1.0 Category: Password management ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100

typedef struct {
    char username[50];
    char password[50];
} Password;

int main() {
    char choice;
    int count = 0;
    Password passwords[MAX_PASSWORDS];

    do {
        printf("Password Manager\n");
        printf("1. Add a new password\n");
        printf("2. Search for a password\n");
        printf("3. Delete a password\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);
        printf("\n");

        switch(choice) {
            case '1':
                printf("Enter username: ");
                scanf("%s", passwords[count].username);
                printf("Enter password: ");
                scanf("%s", passwords[count].password);
                count++;
                printf("Password added successfully.\n");
                break;
            case '2':
                printf("Enter username to search: ");
                scanf("%s", passwords[0].username);
                for(int i = 1; i < count; i++) {
                    if(strcmp(passwords[i].username, passwords[0].username) == 0) {
                        printf("Password found: %s\n", passwords[i].password);
                    }
                }
                break;
            case '3':
                printf("Enter username to delete: ");
                scanf("%s", passwords[0].username);
                for(int i = 1; i < count; i++) {
                    if(strcmp(passwords[i].username, passwords[0].username) == 0) {
                        strcpy(passwords[i-1].username, passwords[i].username);
                        strcpy(passwords[i-1].password, passwords[i].password);
                        count--;
                        printf("Password deleted successfully.\n");
                        break;
                    }
                }
                break;
            case '4':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= '4');

    return 0;
}