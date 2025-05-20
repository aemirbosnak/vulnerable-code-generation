//Falcon-180B DATASET v1.0 Category: Password management ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} passwords[MAX_PASSWORDS];

int num_passwords = 0;

void add_password() {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);

    num_passwords++;
}

void delete_password() {
    int index;
    char username[MAX_PASSWORD_LENGTH];

    printf("Enter username to delete: ");
    scanf("%s", username);

    for (index = 0; index < num_passwords; index++) {
        if (strcmp(passwords[index].username, username) == 0) {
            memmove(&passwords[index], &passwords[index + 1], (num_passwords - index - 1) * sizeof(passwords[0]));
            num_passwords--;
            break;
        }
    }
}

void search_password() {
    char username[MAX_PASSWORD_LENGTH];

    printf("Enter username to search: ");
    scanf("%s", username);

    int index = 0;
    while (index < num_passwords) {
        if (strcmp(passwords[index].username, username) == 0) {
            printf("Username: %s\n", passwords[index].username);
            printf("Password: %s\n", passwords[index].password);
            break;
        }
        index++;
    }
}

int main() {
    while (1) {
        printf("1. Add password\n");
        printf("2. Delete password\n");
        printf("3. Search password\n");
        printf("4. Exit\n");
        int choice;
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
                printf("Invalid choice.\n");
        }
    }

    return 0;
}