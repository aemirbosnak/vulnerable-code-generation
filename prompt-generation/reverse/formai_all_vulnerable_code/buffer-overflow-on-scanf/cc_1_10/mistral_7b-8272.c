//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char name[50];
    char email[100];
    struct list_node *next;
} list_node;

list_node *head = NULL;

void add_to_list(char *name, char *email) {
    list_node *new_node = (list_node *)malloc(sizeof(list_node));
    strcpy(new_node->name, name);
    strcpy(new_node->email, email);
    new_node->next = head;
    head = new_node;
}

bool find_email(char *email) {
    list_node *current = head;
    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            printf("Oh look, we already have %s (%s) on the list!\n", current->name, current->email);
            return true;
        }
        current = current->next;
    }
    return false;
}

int main() {
    char command[100], name[50], email[100];
    bool valid_command = false;

    printf("===========================================================\n");
    printf("== Welcome to the Funnymail Mailing List Manager! ==\n");
    printf("===========================================================\n");

    while (1) {
        printf("\nPlease enter a command (add, find, quit): ");
        scanf("%s", command);

        if (strcmp(command, "quit") == 0) {
            break;
        }

        switch (command[0]) {
            case 'a':
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);

                if (find_email(email)) {
                    printf("That email is already taken, try another one!\n");
                    continue;
                }

                add_to_list(name, email);
                printf("%s (%s) added to the list!\n", name, email);
                break;

            case 'f':
                printf("Enter email to search for: ");
                scanf("%s", email);

                if (!find_email(email)) {
                    printf("That email is not on the list!\n");
                }
                break;

            default:
                printf("Invalid command! Please try again.\n");
                break;
        }

        valid_command = true;
    }

    printf("===========================================================\n");
    printf("== Goodbye! The Funnymail Mailing List Manager is now closed ==\n");
    printf("===========================================================\n");

    return 0;
}