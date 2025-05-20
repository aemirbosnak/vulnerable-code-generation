//GEMINI-pro DATASET v1.0 Category: Password management ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct password_entry {
    char *username;
    char *password;
    struct password_entry *next;
} password_entry;

password_entry *head = NULL;

void add_password(char *username, char *password) {
    password_entry *new_entry = malloc(sizeof(password_entry));
    new_entry->username = strdup(username);
    new_entry->password = strdup(password);
    new_entry->next = head;
    head = new_entry;
}

void delete_password(char *username) {
    password_entry *current = head;
    password_entry *previous = NULL;

    while (current != NULL && strcmp(current->username, username) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Username not found.\n");
        return;
    }

    if (previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current->username);
    free(current->password);
    free(current);
}

void print_passwords() {
    password_entry *current = head;

    while (current != NULL) {
        printf("%s: %s\n", current->username, current->password);
        current = current->next;
    }
}

int main() {
    char *username;
    char *password;
    int choice;

    do {
        printf("1. Add password\n");
        printf("2. Delete password\n");
        printf("3. Print passwords\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                add_password(username, password);
                break;
            case 2:
                printf("Enter username: ");
                scanf("%s", username);
                delete_password(username);
                break;
            case 3:
                print_passwords();
                break;
            case 4:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}