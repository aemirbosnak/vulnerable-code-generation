//Falcon-180B DATASET v1.0 Category: Password management ; Style: portable
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

    printf("Enter index of password to delete: ");
    scanf("%d", &index);

    if (index >= 0 && index < num_passwords) {
        memset(&passwords[index], 0, sizeof(Password));
        num_passwords--;
    } else {
        printf("Invalid index.\n");
    }
}

void search_password() {
    char search_username[MAX_PASSWORD_LENGTH];

    printf("Enter username to search: ");
    scanf("%s", search_username);

    int index = -1;
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, search_username) == 0) {
            index = i;
            break;
        }
    }

    if (index >= 0) {
        printf("Password for %s: %s\n", search_username, passwords[index].password);
    } else {
        printf("Password not found.\n");
    }
}

int main() {
    int choice;

    do {
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
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}