//FormAI DATASET v1.0 Category: Mailing list manager ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_LIST_SIZE 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} contact;

typedef struct {
    contact contacts[MAX_LIST_SIZE];
    int numContacts;
} maillist;

int menu();
void addContact(maillist *);
void deleteContact(maillist *);
void searchContact(maillist *);
void printContacts(maillist *);

int main() {
    maillist list = { .numContacts = 0 };
    int choice = menu();
    while (choice != 5) {
        switch (choice) {
            case 1:
                addContact(&list);
                break;
            case 2:
                deleteContact(&list);
                break;
            case 3:
                searchContact(&list);
                break;
            case 4:
                printContacts(&list);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
        choice = menu();
    }
    return 0;
}

int menu() {
    int choice;
    printf("\nMain Menu\n");
    printf("1. Add Contact\n");
    printf("2. Delete Contact\n");
    printf("3. Search Contact\n");
    printf("4. Print Contacts\n");
    printf("5. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void addContact(maillist *list) {
    if (list->numContacts == MAX_LIST_SIZE) {
        printf("The list is full\n");
        return;
    }
    printf("Enter the name: ");
    scanf("%s", list->contacts[list->numContacts].name);
    printf("Enter the email: ");
    scanf("%s", list->contacts[list->numContacts].email);
    list->numContacts++;
    printf("Contact added successfully\n");
}

void deleteContact(maillist *list) {
    char nameToDelete[MAX_NAME_LENGTH];
    printf("Enter the name of the contact to delete: ");
    scanf("%s", nameToDelete);
    for (int i = 0; i < list->numContacts; i++) {
        if (strcmp(nameToDelete, list->contacts[i].name) == 0) {
            for (int j = i; j < list->numContacts - 1; j++) {
                list->contacts[j] = list->contacts[j+1];
            }
            list->numContacts--;
            printf("Contact deleted successfully\n");
            return;
        }
    }
    printf("Contact not found\n");
}

void searchContact(maillist *list) {
    char nameToSearch[MAX_NAME_LENGTH];
    printf("Enter the name of the contact to search: ");
    scanf("%s", nameToSearch);
    for (int i = 0; i < list->numContacts; i++) {
        if (strcmp(nameToSearch, list->contacts[i].name) == 0) {
            printf("Name: %s\n", list->contacts[i].name);
            printf("Email: %s\n", list->contacts[i].email);
            return;
        }
    }
    printf("Contact not found\n");
}

void printContacts(maillist *list) {
    if (list->numContacts == 0) {
        printf("The list is empty\n");
        return;
    }
    printf("\nList of Contacts\n");
    for (int i = 0; i < list->numContacts; i++) {
        printf("%d. Name: %s   Email: %s\n", i+1, list->contacts[i].name, list->contacts[i].email);
    }
}