//Falcon-180B DATASET v1.0 Category: Password management ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LENGTH 20

struct account {
    char username[LENGTH];
    char password[LENGTH];
};

void create_account(struct account *account) {
    printf("Enter username: ");
    scanf("%s", account->username);
    printf("Enter password: ");
    scanf("%s", account->password);
}

void login(struct account *accounts, int size, char *username, char *password) {
    for (int i = 0; i < size; i++) {
        if (strcmp(accounts[i].username, username) == 0 && strcmp(accounts[i].password, password) == 0) {
            printf("Login successful!\n");
            return;
        }
    }
    printf("Login failed.\n");
}

int main() {
    struct account accounts[100];
    int size = 0;

    while (1) {
        printf("1. Create account\n2. Login\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            if (size >= 100) {
                printf("Maximum number of accounts reached.\n");
            } else {
                create_account(&accounts[size]);
                size++;
            }
        } else if (choice == 2) {
            printf("Enter username: ");
            char username[LENGTH];
            scanf("%s", username);
            printf("Enter password: ");
            char password[LENGTH];
            scanf("%s", password);

            login(accounts, size, username, password);
        } else if (choice == 3) {
            break;
        }
    }

    return 0;
}