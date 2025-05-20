//Falcon-180B DATASET v1.0 Category: Password management ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 64

typedef struct {
    char username[64];
    char password[PASSWORD_LENGTH];
    int is_admin;
} user_t;

user_t users[MAX_PASSWORDS];
int num_users = 0;

void add_user() {
    printf("Enter username: ");
    scanf("%s", users[num_users].username);

    printf("Enter password: ");
    scanf("%s", users[num_users].password);

    printf("Is this user an admin? (y/n): ");
    char choice;
    scanf(" %c", &choice);
    users[num_users].is_admin = (choice == 'y' || choice == 'Y');

    num_users++;
}

void remove_user() {
    printf("Enter username to remove: ");
    scanf("%s", users[num_users - 1].username);

    num_users--;
}

void list_users() {
    printf("Usernames:\n");
    for(int i=0; i<num_users; i++) {
        printf("%s\n", users[i].username);
    }
}

void change_password() {
    printf("Enter username: ");
    scanf("%s", users[num_users - 1].username);

    printf("Enter new password: ");
    scanf("%s", users[num_users - 1].password);
}

int main() {
    printf("Welcome to the password manager!\n");

    while(1) {
        printf("\nOptions:\n");
        printf("1. Add user\n");
        printf("2. Remove user\n");
        printf("3. List users\n");
        printf("4. Change password\n");
        printf("5. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_user();
                break;
            case 2:
                remove_user();
                break;
            case 3:
                list_users();
                break;
            case 4:
                change_password();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}