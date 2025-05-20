//Falcon-180B DATASET v1.0 Category: Password management ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 32

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char* username, char* password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Cannot add more passwords.\n");
        return;
    }

    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);
    num_passwords++;

    printf("Password added successfully.\n");
}

void remove_password(char* username) {
    int i;

    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            memset(passwords[i].password, 0, MAX_PASSWORD_LENGTH);
            num_passwords--;
            printf("Password removed successfully.\n");
            break;
        }
    }
}

void list_passwords() {
    printf("Username\tPassword\n");
    printf("--------\t---------\n");

    int i;
    for (i = 0; i < num_passwords; i++) {
        printf("%s\t%s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    char choice;

    do {
        printf("Password Manager\n");
        printf("1. Add Password\n");
        printf("2. Remove Password\n");
        printf("3. List Passwords\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1': {
                char username[MAX_PASSWORD_LENGTH];
                char password[MAX_PASSWORD_LENGTH];

                printf("Enter username: ");
                scanf("%s", username);

                printf("Enter password: ");
                scanf("%s", password);

                add_password(username, password);
                break;
            }

            case '2': {
                char username[MAX_PASSWORD_LENGTH];

                printf("Enter username: ");
                scanf("%s", username);

                remove_password(username);
                break;
            }

            case '3': {
                list_passwords();
                break;
            }

            case '4': {
                printf("Exiting...\n");
            }

            default: {
                printf("Invalid choice.\n");
            }
        }
    } while (choice!= '4');

    return 0;
}