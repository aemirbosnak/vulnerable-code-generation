//Falcon-180B DATASET v1.0 Category: Password management ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords;

void add_password(char* name, char* password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    strcpy(passwords[num_passwords].name, name);
    strcpy(passwords[num_passwords].password, password);

    num_passwords++;
}

void remove_password(char* name) {
    int i;

    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            memset(passwords[i].name, 0, MAX_PASSWORD_LENGTH);
            memset(passwords[i].password, 0, MAX_PASSWORD_LENGTH);

            num_passwords--;
            break;
        }
    }
}

void change_password(char* name, char* new_password) {
    int i;

    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            strcpy(passwords[i].password, new_password);
            break;
        }
    }
}

void print_passwords() {
    int i;

    for (i = 0; i < num_passwords; i++) {
        printf("Name: %s, Password: %s\n", passwords[i].name, passwords[i].password);
    }
}

int main() {
    int choice;

    do {
        printf("Password Management System\n");
        printf("1. Add Password\n");
        printf("2. Remove Password\n");
        printf("3. Change Password\n");
        printf("4. Print Passwords\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter name: ");
            char name[MAX_PASSWORD_LENGTH];
            scanf("%s", name);

            printf("Enter password: ");
            char password[MAX_PASSWORD_LENGTH];
            scanf("%s", password);

            add_password(name, password);
            break;

        case 2:
            printf("Enter name: ");
            scanf("%s", name);

            remove_password(name);
            break;

        case 3:
            printf("Enter name: ");
            scanf("%s", name);

            printf("Enter new password: ");
            char new_password[MAX_PASSWORD_LENGTH];
            scanf("%s", new_password);

            change_password(name, new_password);
            break;

        case 4:
            print_passwords();
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }

    } while (1);

    return 0;
}