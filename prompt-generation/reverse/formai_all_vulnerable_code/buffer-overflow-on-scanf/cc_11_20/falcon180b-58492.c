//Falcon-180B DATASET v1.0 Category: Password management ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 20

struct Password {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

int main() {
    int num_passwords = 0;
    struct Password passwords[MAX_PASSWORDS];

    while (num_passwords < MAX_PASSWORDS) {
        printf("Enter a username: ");
        scanf("%s", passwords[num_passwords].username);

        printf("Enter a password: ");
        scanf("%s", passwords[num_passwords].password);

        num_passwords++;
    }

    int choice;
    while (1) {
        printf("\n1. Add a new password\n2. Delete a password\n3. View a password\n4. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            if (num_passwords >= MAX_PASSWORDS) {
                printf("Maximum number of passwords reached.\n");
            } else {
                printf("Enter a username: ");
                scanf("%s", passwords[num_passwords].username);

                printf("Enter a password: ");
                scanf("%s", passwords[num_passwords].password);

                num_passwords++;
            }
        } else if (choice == 2) {
            printf("Enter the username of the password you want to delete: ");
            scanf("%s", passwords[0].username);

            for (int i = 0; i < num_passwords; i++) {
                if (strcmp(passwords[i].username, passwords[0].username) == 0) {
                    memset(passwords[i].password, 0, MAX_PASSWORD_LENGTH);
                    num_passwords--;
                }
            }
        } else if (choice == 3) {
            printf("Enter the username of the password you want to view: ");
            scanf("%s", passwords[0].username);

            for (int i = 0; i < num_passwords; i++) {
                if (strcmp(passwords[i].username, passwords[0].username) == 0) {
                    printf("Username: %s\nPassword: %s\n", passwords[i].username, passwords[i].password);
                }
            }
        } else if (choice == 4) {
            break;
        }
    }

    return 0;
}