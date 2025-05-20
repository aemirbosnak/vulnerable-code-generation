//Falcon-180B DATASET v1.0 Category: Password management ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 1000
#define PASSWORD_LENGTH 32

typedef struct {
    char username[32];
    char password[32];
} password_t;

password_t passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *username, char *password) {
    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);
    num_passwords++;
}

int main() {
    char choice;
    int i;

    do {
        printf("Welcome to the password manager!\n\n");
        printf("1. Add a new password\n");
        printf("2. Remove a password\n");
        printf("3. Search for a password\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                printf("Enter username: ");
                scanf("%s", passwords[num_passwords].username);
                printf("Enter password: ");
                scanf("%s", passwords[num_passwords].password);
                num_passwords++;
                printf("Password added!\n");
                break;
            case '2':
                printf("Enter username to remove: ");
                scanf("%s", passwords[num_passwords].username);
                for(i=0; i<num_passwords-1; i++) {
                    if(strcmp(passwords[i].username, passwords[num_passwords].username) == 0) {
                        strcpy(passwords[i].username, passwords[num_passwords].username);
                        strcpy(passwords[i].password, passwords[num_passwords].password);
                    }
                }
                num_passwords--;
                printf("Password removed!\n");
                break;
            case '3':
                printf("Enter username to search: ");
                scanf("%s", passwords[num_passwords].username);
                for(i=0; i<num_passwords; i++) {
                    if(strcmp(passwords[i].username, passwords[num_passwords].username) == 0) {
                        printf("Password found!\n");
                        printf("Username: %s\n", passwords[i].username);
                        printf("Password: %s\n", passwords[i].password);
                    }
                }
                break;
            case '4':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= '4');

    return 0;
}