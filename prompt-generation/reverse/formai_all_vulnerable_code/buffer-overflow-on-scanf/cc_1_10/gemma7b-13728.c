//Gemma-7B DATASET v1.0 Category: Password management ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_PASSWORDS 10

typedef struct Password {
    char *name;
    char *password;
    struct Password *next;
} Password;

void add_password(Password **head) {
    Password *new_password = malloc(sizeof(Password));
    new_password->name = malloc(20);
    new_password->password = malloc(20);
    new_password->next = NULL;

    printf("Enter name: ");
    scanf("%s", new_password->name);

    printf("Enter password: ");
    scanf("%s", new_password->password);

    if (*head == NULL) {
        *head = new_password;
    } else {
        (*head)->next = new_password;
    }
}

void print_passwords(Password *head) {
    while (head) {
        printf("Name: %s\n", head->name);
        printf("Password: %s\n", head->password);
        printf("\n");
        head = head->next;
    }
}

int main() {
    Password *passwords = NULL;

    while (1) {
        printf("Options:\n");
        printf("1. Add Password\n");
        printf("2. Print Passwords\n");
        printf("3. Exit\n");

        int choice = 0;
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password(&passwords);
                break;
            case 2:
                print_passwords(passwords);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}