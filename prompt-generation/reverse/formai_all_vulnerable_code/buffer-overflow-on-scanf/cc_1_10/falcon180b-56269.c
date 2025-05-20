//Falcon-180B DATASET v1.0 Category: Password management ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char password[MAX_PASSWORD_LENGTH + 1];
    char username[MAX_PASSWORD_LENGTH + 1];
} Password;

void add_password(Password *passwords, int num_passwords, char *password, char *username) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    strcpy(passwords[num_passwords].password, password);
    strcpy(passwords[num_passwords].username, username);

    num_passwords++;
}

void delete_password(Password *passwords, int num_passwords, char *username) {
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            memmove(&passwords[i], &passwords[i+1], sizeof(Password) * (num_passwords - i - 1));
            num_passwords--;
            break;
        }
    }
}

void print_passwords(Password *passwords, int num_passwords) {
    int i;
    for (i = 0; i < num_passwords; i++) {
        printf("%s - %s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    while (1) {
        printf("Enter 1 to add a password, 2 to delete a password, 3 to print passwords, or 0 to exit:\n");
        int choice;
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        }

        if (choice == 1) {
            char password[MAX_PASSWORD_LENGTH + 1];
            char username[MAX_PASSWORD_LENGTH + 1];

            printf("Enter password:\n");
            scanf("%s", password);

            printf("Enter username:\n");
            scanf("%s", username);

            add_password(passwords, num_passwords, password, username);
        } else if (choice == 2) {
            char username[MAX_PASSWORD_LENGTH + 1];

            printf("Enter username to delete:\n");
            scanf("%s", username);

            delete_password(passwords, num_passwords, username);
        } else if (choice == 3) {
            print_passwords(passwords, num_passwords);
        }
    }

    return 0;
}