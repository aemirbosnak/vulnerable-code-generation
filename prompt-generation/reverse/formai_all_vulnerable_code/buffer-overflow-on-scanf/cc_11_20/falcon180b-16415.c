//Falcon-180B DATASET v1.0 Category: Password management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_USERS 100
#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 20

struct user {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

int main() {
    struct user users[MAX_USERS];
    int num_users = 0;
    char choice;

    do {
        printf("\n\nPassword Manager\n");
        printf("-------------------\n");
        printf("1. Create user\n");
        printf("2. Delete user\n");
        printf("3. Change password\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
        case '1':
            if(num_users >= MAX_USERS) {
                printf("Maximum number of users reached.\n");
            } else {
                printf("Enter user name: ");
                scanf("%s", users[num_users].name);
                printf("Enter password: ");
                scanf("%s", users[num_users].password);
                num_users++;
            }
            break;
        case '2':
            printf("Enter user name to delete: ");
            char name[MAX_PASSWORD_LENGTH];
            scanf("%s", name);
            int i;
            for(i=0; i<num_users; i++) {
                if(strcmp(users[i].name, name) == 0) {
                    memset(users[i].name, 0, MAX_PASSWORD_LENGTH);
                    memset(users[i].password, 0, MAX_PASSWORD_LENGTH);
                    num_users--;
                    printf("User deleted.\n");
                    break;
                }
            }
            break;
        case '3':
            printf("Enter user name: ");
            char old_name[MAX_PASSWORD_LENGTH];
            scanf("%s", old_name);
            printf("Enter new password: ");
            char new_password[MAX_PASSWORD_LENGTH];
            scanf("%s", new_password);
            for(i=0; i<num_users; i++) {
                if(strcmp(users[i].name, old_name) == 0) {
                    strcpy(users[i].password, new_password);
                    printf("Password changed.\n");
                    break;
                }
            }
            break;
        case '4':
            printf("Exiting...\n");
        default:
            printf("Invalid choice.\n");
        }
    } while(choice!= '4');

    return 0;
}