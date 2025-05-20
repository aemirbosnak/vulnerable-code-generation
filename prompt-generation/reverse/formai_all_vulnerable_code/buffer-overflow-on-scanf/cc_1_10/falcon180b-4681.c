//Falcon-180B DATASET v1.0 Category: Password management ; Style: modular
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
int num_passwords;

void initialize() {
    num_passwords = 0;
}

void add_password(char* username, char* password) {
    if (num_passwords == MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);
    num_passwords++;
}

void remove_password(char* username) {
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            memset(&passwords[i], 0, sizeof(Password));
            num_passwords--;
            return;
        }
    }

    printf("Error: Password not found.\n");
}

void display_passwords() {
    int i;
    for (i = 0; i < num_passwords; i++) {
        printf("Username: %s\nPassword: %s\n\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    initialize();

    char choice;
    do {
        printf("Password Manager\n");
        printf("1. Add password\n2. Remove password\n3. Display passwords\n4. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1': {
                char username[MAX_PASSWORD_LENGTH], password[MAX_PASSWORD_LENGTH];
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
                display_passwords();
                break;
            }
            case '4': {
                printf("Exiting program.\n");
                break;
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    } while (choice!= '4');

    return 0;
}