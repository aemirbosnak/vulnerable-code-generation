//MISTRAL-7B DATASET v1.0 Category: Password management ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 50

struct password {
    char username[PASSWORD_LENGTH];
    char password[PASSWORD_LENGTH];
};

struct password database[MAX_PASSWORDS];
int count = 0;

void create_password(char *username, char *password) {
    if (count >= MAX_PASSWORDS) {
        printf("Database is full.\n");
        return;
    }

    strcpy(database[count].username, username);
    strcpy(database[count].password, password);
    count++;
}

void find_password(char *username) {
    for (int i = 0; i < count; i++) {
        if (strcmp(database[i].username, username) == 0) {
            printf("Password for %s: %s\n", database[i].username, database[i].password);
            return;
        }
    }

    printf("User not found.\n");
}

int main() {
    char username[PASSWORD_LENGTH];
    char password[PASSWORD_LENGTH];
    char command;

    while (true) {
        printf("Enter command (C)reate, (F)ind, (Q)uit: ");
        scanf(" %c", &command);

        switch (command) {
            case 'C':
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                create_password(username, password);
                break;
            case 'F':
                printf("Enter username: ");
                scanf("%s", username);
                find_password(username);
                break;
            case 'Q':
                exit(0);
            default:
                printf("Invalid command.\n");
        }
    }

    return 0;
}