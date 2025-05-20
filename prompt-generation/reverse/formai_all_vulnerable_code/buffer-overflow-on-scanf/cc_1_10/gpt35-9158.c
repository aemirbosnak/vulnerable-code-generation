//FormAI DATASET v1.0 Category: Phone Book ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 15

typedef struct contact {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
    struct contact *next;
} Contact;

Contact *head = NULL;

void add_contact() {
    Contact *new_contact = (Contact*) malloc(sizeof(Contact));
    printf("\nEnter the name: ");
    scanf("%s", new_contact->name);
    printf("Enter the phone number: ");
    scanf("%s", new_contact->phone_number);
    new_contact->next = head;
    head = new_contact;
    printf("\nContact added successfully!");
}

void search_contact() {
    char search_name[MAX_NAME_LENGTH];
    printf("\nEnter the name to search: ");
    scanf("%s", search_name);
    Contact *current_contact = head;
    while (current_contact != NULL) {
        if (strcmp(current_contact->name, search_name) == 0) {
            printf("\nName: %s, Phone Number: %s", current_contact->name, current_contact->phone_number);
            return;
        }
        current_contact = current_contact->next;
    }
    printf("\nContact not found!");
}

void display_contacts(Contact *contact) {
    if (contact == NULL) {
        printf("\nPhone Book is empty!");
        return;
    }
    printf("\nName: %s, Phone Number: %s\n", contact->name, contact->phone_number);
    if (contact->next != NULL) {
        display_contacts(contact->next);
    }
}

void delete_contact() {
    char delete_name[MAX_NAME_LENGTH];
    printf("\nEnter the name to delete: ");
    scanf("%s", delete_name);
    Contact *current_contact = head;
    Contact *previous_contact = NULL;
    while (current_contact != NULL) {
        if (strcmp(current_contact->name, delete_name) == 0) {
            if (previous_contact == NULL) {
                head = current_contact->next;
            } else {
                previous_contact->next = current_contact->next;
            }
            free(current_contact);
            printf("\nContact deleted successfully!");
            return;
        }
        previous_contact = current_contact;
        current_contact = current_contact->next;
    }
    printf("\nContact not found!");
}

int main() {
    while (1) {
        int choice;
        printf("\n\n------ MENU ------\n");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Display all contacts\n");
        printf("4. Delete contact\n");
        printf("5. Exit\n");
        printf("-------------------\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: add_contact(); break;
            case 2: search_contact(); break;
            case 3: display_contacts(head); break;
            case 4: delete_contact(); break;
            case 5: exit(0);
            default: printf("\nInvalid choice! Try again.");
        }
    }
    return 0;
}