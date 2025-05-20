//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_ADDRESS_LENGTH 255

struct Contact {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    struct Contact *next;
};

void addContact(struct Contact **head) {
    struct Contact *newContact = malloc(sizeof(struct Contact));
    newContact->next = NULL;

    printf("Enter name: ");
    scanf("%s", newContact->name);

    printf("Enter address: ");
    scanf("%s", newContact->address);

    *head = newContact;
}

void printContacts(struct Contact *head) {
    struct Contact *current = head;

    while (current) {
        printf("Name: %s\n", current->name);
        printf("Address: %s\n", current->address);
        printf("\n");

        current = current->next;
    }
}

int main() {
    struct Contact *head = NULL;

    // Add some contacts
    addContact(&head);
    addContact(&head);
    addContact(&head);

    // Print the contacts
    printContacts(head);

    return 0;
}