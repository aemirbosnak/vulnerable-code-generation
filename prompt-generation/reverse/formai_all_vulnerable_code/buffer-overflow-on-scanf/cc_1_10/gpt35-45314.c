//FormAI DATASET v1.0 Category: Phone Book ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20
#define MAX_CONTACTS 100

struct Contact {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    struct Contact *next;
};

struct Contact *head = NULL;
int numContacts = 0;

void addContact() {
    if (numContacts == MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }
    char name[MAX_NAME_LENGTH], phone[MAX_PHONE_LENGTH];
    printf("Enter the contact's name:\n");
    scanf("%s", name);
    printf("Enter the contact's phone number:\n");
    scanf("%s", phone);
    struct Contact *newContact = malloc(sizeof(struct Contact));
    strcpy(newContact->name, name);
    strcpy(newContact->phone, phone);
    newContact->next = NULL;
    if (head == NULL) {
        head = newContact;
    } else {
        struct Contact *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newContact;
    }
    numContacts++;
    printf("Contact added successfully!\n");
}

void searchContacts() {
    if (head == NULL) {
        printf("Phone book is empty!\n");
        return;
    }
    char keyword[MAX_NAME_LENGTH];
    printf("Enter a keyword to search for:\n");
    scanf("%s", keyword);
    struct Contact *current = head;
    int count = 0;
    while (current != NULL) {
        if (strstr(current->name, keyword) != NULL) {
            printf("%s: %s\n", current->name, current->phone);
            count++;
        }
        current = current->next;
    }
    if (count == 0) {
        printf("No matching contacts found.\n");
    } else {
        printf("%d contacts found.\n", count);
    }
}

void deleteContact() {
    if (head == NULL) {
        printf("Phone book is empty!\n");
        return;
    }
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the contact to delete:\n");
    scanf("%s", name);
    if (strcmp(head->name, name) == 0) {
        struct Contact *temp = head;
        head = head->next;
        free(temp);
        numContacts--;
        printf("Contact deleted successfully!\n");
        return;
    }
    struct Contact *prev = head;
    struct Contact *current = head->next;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            prev->next = current->next;
            free(current);
            numContacts--;
            printf("Contact deleted successfully!\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Contact not found!\n");
}

void printContacts() {
    if (head == NULL) {
        printf("Phone book is empty!\n");
        return;
    }
    struct Contact *current = head;
    while (current != NULL) {
        printf("%s: %s\n", current->name, current->phone);
        current = current->next;
    }
    printf("%d contacts in phone book.\n", numContacts);
}

int main() {
    int choice;
    while (1) {
        printf("\nPhone Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Search Contacts\n");
        printf("3. Delete Contact\n");
        printf("4. Print Contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5):\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                searchContacts();
                break;
            case 3:
                deleteContact();
                break;
            case 4:
                printContacts();
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}