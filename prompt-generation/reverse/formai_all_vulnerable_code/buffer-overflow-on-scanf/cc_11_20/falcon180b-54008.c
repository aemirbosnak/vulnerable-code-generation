//Falcon-180B DATASET v1.0 Category: Password management ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50
#define MAX_USERNAME_LENGTH 50

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

int main() {
    char choice;
    int num_passwords = 0;
    Password passwords[MAX_PASSWORDS];

    do {
        printf("Password Manager\n");
        printf("1. Add password\n");
        printf("2. Remove password\n");
        printf("3. View all passwords\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                if(num_passwords >= MAX_PASSWORDS) {
                    printf("Maximum number of passwords reached.\n");
                    break;
                }
                printf("Enter username: ");
                scanf("%s", passwords[num_passwords].username);
                printf("Enter password: ");
                scanf("%s", passwords[num_passwords].password);
                printf("Password added successfully.\n");
                num_passwords++;
                break;
            case '2':
                if(num_passwords == 0) {
                    printf("No passwords to remove.\n");
                    break;
                }
                printf("Enter username of password to remove: ");
                scanf("%s", passwords[0].username);
                for(int i=0; i<num_passwords; i++) {
                    if(strcmp(passwords[i].username, passwords[0].username) == 0) {
                        memset(passwords[i].password, 0, MAX_PASSWORD_LENGTH);
                        printf("Password removed successfully.\n");
                        break;
                    }
                }
                break;
            case '3':
                if(num_passwords == 0) {
                    printf("No passwords to view.\n");
                    break;
                }
                printf("Passwords:\n");
                for(int i=0; i<num_passwords; i++) {
                    printf("%s - %s\n", passwords[i].username, passwords[i].password);
                }
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= '4');

    return 0;
}