//Falcon-180B DATASET v1.0 Category: Password management ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 64
#define MAX_USERNAME_LENGTH 64

struct password {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password() {
    printf("Enter username: ");
    scanf("%s", passwords[num_passwords].username);

    printf("Enter password: ");
    scanf("%s", passwords[num_passwords].password);

    num_passwords++;
}

void edit_password() {
    printf("Enter username to edit: ");
    char username[MAX_USERNAME_LENGTH];
    scanf("%s", username);

    int index = -1;
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(username, passwords[i].username) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("User not found.\n");
        return;
    }

    printf("Enter new password: ");
    scanf("%s", passwords[index].password);
}

void delete_password() {
    printf("Enter username to delete: ");
    char username[MAX_USERNAME_LENGTH];
    scanf("%s", username);

    int index = -1;
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(username, passwords[i].username) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("User not found.\n");
        return;
    }

    for (int i = index; i < num_passwords - 1; i++) {
        strcpy(passwords[i].username, passwords[i + 1].username);
        strcpy(passwords[i].password, passwords[i + 1].password);
    }

    num_passwords--;
}

void view_passwords() {
    printf("Username\t\t\tPassword\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%s\t\t\t%s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    printf("Welcome to the password manager!\n");

    int choice = 0;
    while (choice!= 4) {
        printf("\n");
        printf("1. Add password\n");
        printf("2. Edit password\n");
        printf("3. Delete password\n");
        printf("4. Exit\n");
        printf("\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                edit_password();
                break;
            case 3:
                delete_password();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}