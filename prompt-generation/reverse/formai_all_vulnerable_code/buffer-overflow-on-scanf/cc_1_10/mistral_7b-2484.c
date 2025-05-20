//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[15];
    struct contact *next;
} contact;

contact *head = NULL;

void add_contact(char *name, char *phone) {
    contact *new_contact = (contact *)malloc(sizeof(contact));
    strcpy(new_contact->name, name);
    strcpy(new_contact->phone, phone);
    new_contact->next = head;
    head = new_contact;
}

void delete_contact(char *name) {
    contact *current = head, *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL)
                head = current->next;
            else
                previous->next = current->next;
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

void search_contact(char *name) {
    contact *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Name: %s\nPhone: %s\n", current->name, current->phone);
            return;
        }
        current = current->next;
    }
    printf("Contact not found.\n");
}

void display_contacts() {
    contact *current = head;
    while (current != NULL) {
        printf("Name: %s\nPhone: %s\n", current->name, current->phone);
        current = current->next;
    }
}

int main() {
    char command[10], name[50], phone[15];
    int choice;

    while (1) {
        printf("\nPhonebook\n1. Add contact\n2. Delete contact\n3. Search contact\n4. Display all contacts\n5. Exit\nEnter your choice: ");
        scanf("%s", command);

        choice = atoi(command);
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phone);
                add_contact(name, phone);
                break;
            case 2:
                printf("Enter name of contact to delete: ");
                scanf("%s", name);
                delete_contact(name);
                break;
            case 3:
                printf("Enter name of contact to search: ");
                scanf("%s", name);
                search_contact(name);
                break;
            case 4:
                display_contacts();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}