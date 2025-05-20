//Gemma-7B DATASET v1.0 Category: Password management ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10

typedef struct Password {
    char *name;
    char *password;
    struct Password *next;
} Password;

Password *insertPassword(Password *head) {
    Password *new_password = malloc(sizeof(Password));
    new_password->name = malloc(20);
    new_password->password = malloc(20);
    new_password->next = NULL;

    printf("Enter the name of the password:** ");
    scanf("%s", new_password->name);

    printf("Enter the password:** ");
    scanf("%s", new_password->password);

    if (head == NULL) {
        head = new_password;
    } else {
        new_password->next = head;
        head = new_password;
    }

    return head;
}

void printPasswords(Password *head) {
    Password *current = head;

    printf("List of passwords:\n");
    while (current) {
        printf("Name: %s, Password: %s\n", current->name, current->password);
        current = current->next;
    }
}

int main() {
    Password *head = NULL;

    while (1) {
        printf("Enter 'add' to add a password, 'print' to print all passwords, or 'exit' to exit: ");
        char command[20];
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            head = insertPassword(head);
        } else if (strcmp(command, "print") == 0) {
            printPasswords(head);
        } else if (strcmp(command, "exit") == 0) {
            exit(0);
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}