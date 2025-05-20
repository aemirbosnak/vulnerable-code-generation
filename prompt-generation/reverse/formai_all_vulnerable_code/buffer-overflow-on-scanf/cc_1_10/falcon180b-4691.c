//Falcon-180B DATASET v1.0 Category: Password management ; Style: configurable
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

void add_password(char *username, char *password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: maximum number of passwords reached.\n");
        return;
    }
    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);
    num_passwords++;
}

int search_password(char *username) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            printf("Password for %s: %s\n", username, passwords[i].password);
            return 1;
        }
    }
    printf("Password not found for %s.\n", username);
    return 0;
}

int main() {
    char choice;
    do {
        printf("Password Manager\n");
        printf("1. Add password\n");
        printf("2. Search password\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);
        switch (choice) {
            case '1':
                printf("Enter username: ");
                char username[MAX_PASSWORD_LENGTH];
                scanf("%s", username);
                printf("Enter password: ");
                char password[MAX_PASSWORD_LENGTH];
                scanf("%s", password);
                add_password(username, password);
                break;
            case '2':
                printf("Enter username: ");
                char search_username[MAX_PASSWORD_LENGTH];
                scanf("%s", search_username);
                search_password(search_username);
                break;
            case '3':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= '3');
    return 0;
}