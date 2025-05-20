//Falcon-180B DATASET v1.0 Category: Password management ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 20
#define MAX_USERNAME_LENGTH 20

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} password_entry;

int main() {
    int num_passwords = 0;
    password_entry passwords[MAX_PASSWORDS];

    char choice;
    do {
        printf("Password Management System\n");
        printf("1. Add Password\n");
        printf("2. Remove Password\n");
        printf("3. View Passwords\n");
        printf("4. Exit\n");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                printf("Enter username: ");
                scanf("%s", passwords[num_passwords].username);
                printf("Enter password: ");
                scanf("%s", passwords[num_passwords].password);
                num_passwords++;
                break;
            case '2':
                printf("Enter username to remove: ");
                scanf("%s", passwords[num_passwords-1].username);
                num_passwords--;
                break;
            case '3':
                printf("Username\tPassword\n");
                for(int i=0; i<num_passwords; i++) {
                    printf("%s\t%s\n", passwords[i].username, passwords[i].password);
                }
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while(choice!= '4');

    return 0;
}