//MISTRAL-7B DATASET v1.0 Category: Password management ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PASSWORDS 10
#define PASSWORD_LENGTH 50

typedef struct {
    char username[PASSWORD_LENGTH];
    char password[PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void create_password(const char* username, const char* password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Password manager is full.\n");
        return;
    }

    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);
    num_passwords++;
}

void print_password(const char* username) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            printf("Password for %s: %s\n", username, passwords[i].password);
            return;
        }
    }

    printf("Username not found.\n");
}

int main() {
    char command[PASSWORD_LENGTH];
    char username[PASSWORD_LENGTH];
    char password[PASSWORD_LENGTH];

    while (true) {
        printf("Gracious Password Manager> ");
        scanf("%s", command);

        if (strcmp(command, "create") == 0) {
            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter password: ");
            scanf("%s", password);
            create_password(username, password);
        } else if (strcmp(command, "show") == 0) {
            printf("Enter username: ");
            scanf("%s", username);
            print_password(username);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}