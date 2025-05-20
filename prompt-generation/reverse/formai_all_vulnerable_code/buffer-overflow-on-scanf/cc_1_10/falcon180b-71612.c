//Falcon-180B DATASET v1.0 Category: Password management ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 20

typedef struct {
    char username[50];
    char password[PASSWORD_LENGTH];
} Password;

int main() {
    int choice;
    char username[50];
    Password passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    do {
        printf("\nWelcome to the Password Manager!\n");
        printf("1. Add a new password\n");
        printf("2. View a saved password\n");
        printf("3. Delete a saved password\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the username: ");
                scanf("%s", username);
                strcpy(passwords[num_passwords].username, username);
                printf("Enter the password: ");
                scanf("%s", passwords[num_passwords].password);
                num_passwords++;
                break;

            case 2:
                printf("Enter the username: ");
                scanf("%s", username);
                for(int i=0; i<num_passwords; i++) {
                    if(strcmp(username, passwords[i].username) == 0) {
                        printf("Password: %s\n", passwords[i].password);
                        break;
                    }
                }
                break;

            case 3:
                printf("Enter the username: ");
                scanf("%s", username);
                for(int i=0; i<num_passwords; i++) {
                    if(strcmp(username, passwords[i].username) == 0) {
                        memset(passwords[i].password, '\0', PASSWORD_LENGTH);
                        printf("Password deleted.\n");
                        break;
                    }
                }
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice!= 4);

    return 0;
}