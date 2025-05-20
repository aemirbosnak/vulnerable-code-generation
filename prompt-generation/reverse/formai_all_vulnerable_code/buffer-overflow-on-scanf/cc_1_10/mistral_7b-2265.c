//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    int phone_number;
    struct contact *next;
} contact;

contact *phone_book = NULL;
int num_contacts = 0;

void add_contact(char *name, int phone_number);
void search_contact_dfs(contact *current, char *name, int depth);
void print_contact(contact *contact);

int main() {
    char name[MAX_NAME_LEN];
    int choice, phone_number;

    while (1) {
        printf("1. Add Contact\n2. Search Contact\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Phone Number: ");
                scanf("%d", &phone_number);
                add_contact(name, phone_number);
                break;
            case 2:
                printf("Enter Name to Search: ");
                scanf("%s", name);
                search_contact_dfs(phone_book, name, 0);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

void add_contact(char *name, int phone_number) {
    contact *new_contact = (contact *)malloc(sizeof(contact));

    strcpy(new_contact->name, name);
    new_contact->phone_number = phone_number;
    new_contact->next = NULL;

    if (phone_book == NULL) {
        phone_book = new_contact;
        num_contacts++;
    } else {
        contact *current = phone_book;

        while (current->next != NULL) {
            current = current->next;
        }

        current->next = new_contact;
        num_contacts++;
    }
}

void search_contact_dfs(contact *current, char *name, int depth) {
    if (current == NULL) {
        printf("Search failed! Name not found.\n");
        return;
    }

    if (strcmp(current->name, name) == 0) {
        print_contact(current);
        return;
    }

    search_contact_dfs(current->next, name, depth + 1);
}

void print_contact(contact *contact) {
    printf("\nName: %s\nPhone Number: %d\n", contact->name, contact->phone_number);
}