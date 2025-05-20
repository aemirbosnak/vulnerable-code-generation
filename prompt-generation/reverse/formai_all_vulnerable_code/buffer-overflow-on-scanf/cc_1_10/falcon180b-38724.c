//Falcon-180B DATASET v1.0 Category: Password management ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *username;
    char *password;
} Password;

void addPassword(Password *passwords, int *size, char *username, char *password) {
    passwords = realloc(passwords, sizeof(Password) * (*size + 1));
    passwords[*size].username = strdup(username);
    passwords[*size].password = strdup(password);
    (*size)++;
}

void removePassword(Password *passwords, int *size, char *username) {
    int i;
    for (i = 0; i < *size; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            free(passwords[i].username);
            free(passwords[i].password);
            memmove(&passwords[i], &passwords[i+1], sizeof(Password) * (*size - i - 1));
            (*size)--;
            return;
        }
    }
}

void displayPasswords(Password *passwords, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("Username: %s\nPassword: %s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    Password *passwords = NULL;
    int size = 0;
    char command[100];
    while (1) {
        printf("Enter command: ");
        scanf("%s", command);
        if (strcmp(command, "add") == 0) {
            char *username, *password;
            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter password: ");
            scanf("%s", password);
            addPassword(&passwords, &size, username, password);
        } else if (strcmp(command, "remove") == 0) {
            char *username;
            printf("Enter username: ");
            scanf("%s", username);
            removePassword(&passwords, &size, username);
        } else if (strcmp(command, "display") == 0) {
            displayPasswords(passwords, size);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }
    free(passwords);
    return 0;
}