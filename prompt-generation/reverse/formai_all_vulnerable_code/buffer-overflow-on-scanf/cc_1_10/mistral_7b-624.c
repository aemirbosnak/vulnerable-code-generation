//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIST_SIZE 100

typedef struct mailing_list {
    char name[50];
    struct mailing_list *next;
} mailing_list;

mailing_list *head = NULL;
mailing_list *current = NULL;

void add_to_list(char *name) {
    mailing_list *new_entry = (mailing_list *) malloc(sizeof(mailing_list));

    strcpy(new_entry->name, name);
    new_entry->next = NULL;

    if (head == NULL) {
        head = new_entry;
        current = head;
    } else {
        current->next = new_entry;
        current = new_entry;
    }
}

void remove_from_list(char *name) {
    mailing_list *prev = NULL;
    mailing_list *current = head;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Member not found.\n");
}

void display_list() {
    mailing_list *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Mailing List:\n");
    while (temp != NULL) {
        printf("%s\n", temp->name);
        temp = temp->next;
    }
}

int main() {
    char command[10], name[50];
    int choice;

    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Add Member\n");
        printf("2. Remove Member\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%s", command);

        choice = atoi(command);

        switch (choice) {
            case 1:
                printf("Enter member name: ");
                scanf("%s", name);
                add_to_list(name);
                break;
            case 2:
                printf("Enter member name to remove: ");
                scanf("%s", name);
                remove_from_list(name);
                break;
            case 3:
                display_list();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}