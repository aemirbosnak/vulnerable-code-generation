//FormAI DATASET v1.0 Category: Mailing list manager ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct subscriber {
    char name[50];
    char email[50];
    struct subscriber *next;
};

void add_subscriber(struct subscriber **head, char *name, char *email);
void remove_subscriber(struct subscriber **head, char *email);
void print_subscribers(struct subscriber *head);
void clear_list(struct subscriber **head);

int main() {
    struct subscriber *head = NULL;
    char input[50];
    char name[50];
    char email[50];

    while (strcmp(input, "exit") != 0) {
        printf("Enter a command (add, remove, list, exit): ");
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter email: ");
            scanf("%s", email);
            add_subscriber(&head, name, email);
        } else if (strcmp(input, "remove") == 0) {
            printf("Enter email: ");
            scanf("%s", email);
            remove_subscriber(&head, email);
        } else if (strcmp(input, "list") == 0) {
            print_subscribers(head);
        }
    }

    clear_list(&head);

    return 0;
}

void add_subscriber(struct subscriber **head, char *name, char *email) {
    struct subscriber *new_sub = (struct subscriber *)malloc(sizeof(struct subscriber));
    strcpy(new_sub->name, name);
    strcpy(new_sub->email, email);
    new_sub->next = *head;
    *head = new_sub;
    printf("Added %s ( %s)\n", name, email);
}

void remove_subscriber(struct subscriber **head, char *email) {
    struct subscriber *current = *head;
    struct subscriber *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Removed %s\n", email);
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("%s not found\n", email);
}

void print_subscribers(struct subscriber *head) {
    printf("Subscribers:\n");

    while (head != NULL) {
        printf("%s ( %s)\n", head->name, head->email);
        head = head->next;
    }
}

void clear_list(struct subscriber **head) {
    struct subscriber *current = *head;
    
    while (current != NULL) {
        struct subscriber *temp = current;
        current = current->next;
        free(temp);
    }

    *head = NULL;
}