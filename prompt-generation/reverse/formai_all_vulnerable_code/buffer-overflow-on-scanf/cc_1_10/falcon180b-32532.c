//Falcon-180B DATASET v1.0 Category: Password management ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} password_t;

password_t passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char* username, char* password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
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
            printf("Password removed successfully.\n");
            return;
        }
    }

    printf("Error: Password not found.\n");
}

void list_passwords() {
    int i;

    if (num_passwords == 0) {
        printf("No passwords found.\n");
        return;
    }

    for (i = 0; i < num_passwords; i++) {
        printf("%s : %s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    int choice;

    do {
        printf("1. Add password\n");
        printf("2. Remove password\n");
        printf("3. List passwords\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char username[MAX_PASSWORD_LENGTH];
                char password[MAX_PASSWORD_LENGTH];

                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);

                add_password(username, password);
                break;
            }
            case 2: {
                char username[MAX_PASSWORD_LENGTH];

                printf("Enter username: ");
                scanf("%s", username);

                remove_password(username);
                break;
            }
            case 3:
                list_passwords();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 4);

    return 0;
}