//Gemma-7B DATASET v1.0 Category: Password management ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PASSWORDS 10

typedef struct Password {
    char *name;
    char *pass;
    struct Password *next;
} Password;

Password *insert_password(Password *head) {
    Password *new_password = malloc(sizeof(Password));
    new_password->name = malloc(20);
    new_password->pass = malloc(20);
    new_password->next = NULL;

    printf("Enter password name: ");
    scanf("%s", new_password->name);

    printf("Enter password: ");
    scanf("%s", new_password->pass);

    if (head == NULL) {
        head = new_password;
    } else {
        head->next = new_password;
    }

    return head;
}

void print_passwords(Password *head) {
    Password *current = head;

    while (current) {
        printf("Name: %s, Password: %s\n", current->name, current->pass);
        current = current->next;
    }
}

int main() {
    Password *head = NULL;

    while (1) {
        char choice;

        printf("Enter 'i' to insert a new password, 'p' to print passwords, or 'q' to quit: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'i':
                head = insert_password(head);
                break;
            case 'p':
                print_passwords(head);
                break;
            case 'q':
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}