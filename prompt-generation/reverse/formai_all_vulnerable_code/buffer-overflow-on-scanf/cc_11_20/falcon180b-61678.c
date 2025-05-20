//Falcon-180B DATASET v1.0 Category: Password management ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

struct password {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

int main() {
    int num_passwords = 0;
    struct password passwords[MAX_PASSWORDS];

    // Initialize the passwords array
    for (int i = 0; i < MAX_PASSWORDS; i++) {
        passwords[i].username[0] = '\0';
        passwords[i].password[0] = '\0';
    }

    // Loop until the user wants to exit
    while (1) {
        printf("Password Manager\n");
        printf("-----------------\n");
        printf("1. Add password\n");
        printf("2. Remove password\n");
        printf("3. Edit password\n");
        printf("4. View all passwords\n");
        printf("5. Exit\n");
        printf("\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_passwords == MAX_PASSWORDS) {
                printf("Password list is full.\n");
            } else {
                printf("Enter username: ");
                scanf("%s", passwords[num_passwords].username);
                printf("Enter password: ");
                scanf("%s", passwords[num_passwords].password);
                num_passwords++;
            }
            break;

        case 2:
            if (num_passwords == 0) {
                printf("Password list is empty.\n");
            } else {
                printf("Enter username to remove: ");
                scanf("%s", passwords[num_passwords - 1].username);
                num_passwords--;
            }
            break;

        case 3:
            if (num_passwords == 0) {
                printf("Password list is empty.\n");
            } else {
                printf("Enter username to edit: ");
                scanf("%s", passwords[num_passwords - 1].username);
                printf("Enter new password: ");
                scanf("%s", passwords[num_passwords - 1].password);
            }
            break;

        case 4:
            if (num_passwords == 0) {
                printf("Password list is empty.\n");
            } else {
                printf("Passwords:\n");
                for (int i = 0; i < num_passwords; i++) {
                    printf("%s: %s\n", passwords[i].username, passwords[i].password);
                }
            }
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice.\n");
            break;
        }
    }

    return 0;
}