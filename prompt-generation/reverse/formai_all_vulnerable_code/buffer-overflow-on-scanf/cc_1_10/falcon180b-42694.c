//Falcon-180B DATASET v1.0 Category: Password management ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password() {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    printf("Enter username: ");
    scanf("%s", passwords[num_passwords].username);

    printf("Enter password: ");
    scanf("%s", passwords[num_passwords].password);

    num_passwords++;
}

void delete_password() {
    if (num_passwords == 0) {
        printf("Error: No passwords found.\n");
        return;
    }

    printf("Enter username to delete: ");
    scanf("%s", passwords[0].username);

    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, passwords[0].username) == 0) {
            strcpy(passwords[i].username, "");
            strcpy(passwords[i].password, "");
            num_passwords--;
            printf("Password deleted successfully.\n");
            return;
        }
    }

    printf("Error: Password not found.\n");
}

void search_password() {
    if (num_passwords == 0) {
        printf("Error: No passwords found.\n");
        return;
    }

    printf("Enter username to search: ");
    scanf("%s", passwords[0].username);

    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, passwords[0].username) == 0) {
            printf("Password: %s\n", passwords[i].password);
            return;
        }
    }

    printf("Error: Password not found.\n");
}

int main() {
    int choice;

    printf("Welcome to Password Manager!\n");

    while (1) {
        printf("\n");
        printf("1. Add password\n");
        printf("2. Delete password\n");
        printf("3. Search password\n");
        printf("4. Exit\n");
        printf("\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                delete_password();
                break;
            case 3:
                search_password();
                break;
            case 4:
                exit(0);
            default:
                printf("Error: Invalid choice.\n");
        }
    }

    return 0;
}