//Falcon-180B DATASET v1.0 Category: Password management ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(Password* password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    strcpy(passwords[num_passwords].username, password->username);
    strcpy(passwords[num_passwords].password, password->password);

    num_passwords++;
}

int find_password(char* username) {
    int i;

    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            return i;
        }
    }

    return -1;
}

void print_passwords() {
    int i;

    for (i = 0; i < num_passwords; i++) {
        printf("Username: %s\n", passwords[i].username);
        printf("Password: %s\n\n", passwords[i].password);
    }
}

int main() {
    Password password;
    int choice;

    do {
        printf("Sherlock Holmes' Password Manager\n");
        printf("1. Add password\n");
        printf("2. Find password\n");
        printf("3. Print all passwords\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter username: ");
            scanf("%s", password.username);
            printf("Enter password: ");
            scanf("%s", password.password);
            add_password(&password);
            break;

        case 2:
            printf("Enter username: ");
            scanf("%s", password.username);
            find_password(password.username);
            break;

        case 3:
            print_passwords();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}