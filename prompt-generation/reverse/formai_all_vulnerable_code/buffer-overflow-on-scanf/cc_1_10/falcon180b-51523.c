//Falcon-180B DATASET v1.0 Category: Password management ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 10
#define MAX_PASSWORDS 100

struct account {
    char name[MAX_ACCOUNTS];
    char username[MAX_ACCOUNTS];
    char password[MAX_PASSWORDS];
};

void create_account(struct account *accounts) {
    int count = 0;
    while (count < MAX_ACCOUNTS) {
        printf("Enter the name of the account holder: ");
        scanf("%s", accounts[count].name);
        printf("Enter the username: ");
        scanf("%s", accounts[count].username);
        printf("Enter the password: ");
        scanf("%s", accounts[count].password);
        count++;
    }
}

void login(struct account *accounts) {
    char username[MAX_ACCOUNTS];
    char password[MAX_ACCOUNTS];
    int count = 0;

    printf("Enter the username: ");
    scanf("%s", username);

    printf("Enter the password: ");
    scanf("%s", password);

    while (count < MAX_ACCOUNTS) {
        if (strcmp(accounts[count].username, username) == 0 && strcmp(accounts[count].password, password) == 0) {
            printf("Login successful!\n");
            return;
        }
        count++;
    }

    printf("Invalid username or password.\n");
}

void main() {
    struct account accounts[MAX_ACCOUNTS];

    printf("Welcome to the password manager!\n");

    int choice;
    printf("1. Create account\n2. Login\n3. Exit\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            create_account(accounts);
            break;
        case 2:
            printf("Enter the username: ");
            scanf("%s", accounts[0].username);
            printf("Enter the password: ");
            scanf("%s", accounts[0].password);
            login(accounts);
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
    }
}