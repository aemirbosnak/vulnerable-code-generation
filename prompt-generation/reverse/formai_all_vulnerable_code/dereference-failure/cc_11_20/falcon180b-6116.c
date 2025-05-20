//Falcon-180B DATASET v1.0 Category: Password management ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 32
#define MAX_USERNAME_LENGTH 32

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char confirm_password[MAX_PASSWORD_LENGTH];
} password_t;

int main() {
    int num_passwords = 0;
    password_t passwords[MAX_PASSWORDS];

    printf("Welcome to the password management system!\n");

    while (1) {
        printf("\n");
        printf("1. Add a new password\n");
        printf("2. Edit an existing password\n");
        printf("3. Delete a password\n");
        printf("4. View all passwords\n");
        printf("5. Exit\n");
        printf("\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_passwords >= MAX_PASSWORDS) {
                printf("You have reached the maximum number of passwords.\n");
                break;
            }

            printf("Enter the username: ");
            scanf("%s", passwords[num_passwords].username);

            printf("Enter the password: ");
            scanf("%s", passwords[num_passwords].password);

            printf("Confirm the password: ");
            scanf("%s", passwords[num_passwords].confirm_password);

            if (strcmp(passwords[num_passwords].password, passwords[num_passwords].confirm_password)) {
                printf("Passwords do not match.\n");
                break;
            }

            num_passwords++;
            printf("Password added successfully.\n");
            break;

        case 2:
            printf("Enter the username of the password you want to edit: ");
            scanf("%s", passwords[num_passwords - 1].username);

            printf("Enter the new password: ");
            scanf("%s", passwords[num_passwords - 1].password);

            printf("Confirm the new password: ");
            scanf("%s", passwords[num_passwords - 1].confirm_password);

            if (strcmp(passwords[num_passwords - 1].password, passwords[num_passwords - 1].confirm_password)) {
                printf("Passwords do not match.\n");
                break;
            }

            printf("Password edited successfully.\n");
            break;

        case 3:
            printf("Enter the username of the password you want to delete: ");
            scanf("%s", passwords[num_passwords - 1].username);

            num_passwords--;
            printf("Password deleted successfully.\n");
            break;

        case 4:
            printf("\n");
            for (int i = 0; i < num_passwords; i++) {
                printf("Username: %s\n", passwords[i].username);
                printf("Password: %s\n\n", passwords[i].password);
            }
            break;

        case 5:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}