//Falcon-180B DATASET v1.0 Category: Password management ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[50];
    char password[MAX_PASSWORD_LENGTH];
} password_t;

int main() {
    char choice;
    password_t passwords[MAX_PASSWORDS];
    int num_passwords = 0;
    int i;

    printf("Welcome to Password Manager!\n\n");

    do {
        printf("Please choose an option:\n");
        printf("1. Add a new password\n");
        printf("2. View all passwords\n");
        printf("3. Delete a password\n");
        printf("4. Exit\n");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                printf("Enter username: ");
                scanf("%s", passwords[num_passwords].username);
                printf("Enter password: ");
                scanf("%s", passwords[num_passwords].password);
                num_passwords++;
                printf("\nPassword added successfully!\n");
                break;
            case '2':
                for(i = 0; i < num_passwords; i++) {
                    printf("Username: %s\nPassword: %s\n\n", passwords[i].username, passwords[i].password);
                }
                break;
            case '3':
                printf("Enter username to delete: ");
                scanf("%s", passwords[num_passwords-1].username);
                printf("\nPassword deleted successfully!\n");
                num_passwords--;
                break;
            case '4':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option!\n");
        }
    } while(choice!= '4');

    return 0;
}