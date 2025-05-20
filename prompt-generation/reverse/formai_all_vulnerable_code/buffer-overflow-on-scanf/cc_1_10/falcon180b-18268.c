//Falcon-180B DATASET v1.0 Category: Password management ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 50
#define MAX_PASSWORD_LENGTH 50
#define MAX_USERNAME_LENGTH 50

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password() {
    printf("Enter username: ");
    scanf("%s", passwords[num_passwords].username);

    printf("Enter password: ");
    scanf("%s", passwords[num_passwords].password);

    num_passwords++;
}

void remove_password() {
    printf("Enter username to remove: ");
    char username[MAX_USERNAME_LENGTH];
    scanf("%s", username);

    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            num_passwords--;
            memmove(&passwords[i], &passwords[i+1], sizeof(Password) * (num_passwords - i));
            break;
        }
    }
}

void update_password() {
    printf("Enter username to update: ");
    char username[MAX_USERNAME_LENGTH];
    scanf("%s", username);

    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            printf("Enter new password: ");
            scanf("%s", passwords[i].password);
            break;
        }
    }
}

void view_passwords() {
    printf("Username\tPassword\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%s\t%s\n", passwords[i].username, passwords[i].password);
    }
}

void main() {
    printf("Welcome to the password manager!\n");

    int choice;
    while (1) {
        printf("1. Add password\n2. Remove password\n3. Update password\n4. View passwords\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                remove_password();
                break;
            case 3:
                update_password();
                break;
            case 4:
                view_passwords();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}