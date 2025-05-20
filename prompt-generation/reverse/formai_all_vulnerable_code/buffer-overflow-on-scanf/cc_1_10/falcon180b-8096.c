//Falcon-180B DATASET v1.0 Category: Password management ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

int main() {
    char choice;
    int num_passwords = 0;
    Password passwords[MAX_PASSWORDS];

    do {
        printf("Password Manager\n");
        printf("A) Add a new password\n");
        printf("D) Delete a password\n");
        printf("S) Search for a password\n");
        printf("Q) Quit\n");
        scanf("%c", &choice);

        switch(choice) {
            case 'A':
                if (num_passwords == MAX_PASSWORDS) {
                    printf("Maximum number of passwords reached\n");
                } else {
                    printf("Enter username: ");
                    scanf("%s", passwords[num_passwords].username);
                    printf("Enter password: ");
                    scanf("%s", passwords[num_passwords].password);
                    num_passwords++;
                }
                break;

            case 'D':
                printf("Enter username to delete: ");
                scanf("%s", passwords[num_passwords-1].username);
                num_passwords--;
                break;

            case 'S':
                printf("Enter username to search: ");
                scanf("%s", passwords[num_passwords-1].username);
                break;

            case 'Q':
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice!= 'Q');

    return 0;
}