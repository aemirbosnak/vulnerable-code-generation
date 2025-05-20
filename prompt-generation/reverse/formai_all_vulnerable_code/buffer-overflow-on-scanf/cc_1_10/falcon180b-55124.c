//Falcon-180B DATASET v1.0 Category: Password management ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_PASSWORDS 1000
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} account_t;

account_t accounts[MAX_ACCOUNTS];
int num_accounts = 0;

void add_account() {
    printf("Enter your username: ");
    scanf("%s", accounts[num_accounts].username);

    printf("Enter your password: ");
    scanf("%s", accounts[num_accounts].password);

    num_accounts++;
}

int login() {
    printf("Enter your username: ");
    char username[MAX_USERNAME_LENGTH];
    scanf("%s", username);

    int i;
    for (i = 0; i < num_accounts; i++) {
        if (strcmp(username, accounts[i].username) == 0) {
            printf("Enter your password: ");
            char password[MAX_PASSWORD_LENGTH];
            scanf("%s", password);

            if (strcmp(password, accounts[i].password) == 0) {
                return 1;
            } else {
                printf("Incorrect password.\n");
            }
        }
    }

    return 0;
}

int main() {
    int choice;

    do {
        printf("\n");
        printf("1. Add account\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_account();
            break;

        case 2:
            if (login()) {
                printf("Login successful!\n");
            }
            break;

        case 3:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}