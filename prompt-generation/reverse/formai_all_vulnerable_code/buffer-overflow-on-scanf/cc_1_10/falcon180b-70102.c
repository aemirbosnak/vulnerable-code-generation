//Falcon-180B DATASET v1.0 Category: Password management ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} password_t;

password_t passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char* name, char* password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Cannot add more passwords. Maximum limit reached.\n");
        return;
    }

    strcpy(passwords[num_passwords].name, name);
    strcpy(passwords[num_passwords].password, password);
    num_passwords++;
}

bool lookup_password(char* name, char* password) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            strcpy(password, passwords[i].password);
            return true;
        }
    }
    return false;
}

void main() {
    char command[MAX_PASSWORD_LENGTH];
    while (true) {
        printf("Enter command (add/lookup/exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            char name[MAX_PASSWORD_LENGTH];
            char password[MAX_PASSWORD_LENGTH];
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter password: ");
            scanf("%s", password);
            add_password(name, password);
        } else if (strcmp(command, "lookup") == 0) {
            char name[MAX_PASSWORD_LENGTH];
            char password[MAX_PASSWORD_LENGTH];
            printf("Enter name to lookup: ");
            scanf("%s", name);
            if (lookup_password(name, password)) {
                printf("Password for %s: %s\n", name, password);
            } else {
                printf("Password not found for %s.\n", name);
            }
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }
}