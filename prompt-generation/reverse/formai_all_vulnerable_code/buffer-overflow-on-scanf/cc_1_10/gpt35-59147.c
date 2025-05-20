//FormAI DATASET v1.0 Category: Phone Book ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct phoneBook {
    char name[50];
    char phone_no[20];
    struct phoneBook* next;
};

struct phoneBook* createContact(char name[], char phone_no[]) {
    struct phoneBook* temp = (struct phoneBook*)malloc(sizeof(struct phoneBook));
    strcpy(temp->name, name);
    strcpy(temp->phone_no, phone_no);
    temp->next = NULL;
    return temp;
}

void addContact(struct phoneBook** head, char name[], char phone_no[]) {
    struct phoneBook* newContact = createContact(name, phone_no);
    if (*head == NULL) {
        *head = newContact;
    }
    else {
        struct phoneBook* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newContact;
    }
}

void deleteContact(struct phoneBook** head, char name[]) {
    struct phoneBook* temp = *head;
    struct phoneBook* prev;
    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Contact not found.\n");
        return;
    }
    if (temp == *head) {
        *head = temp->next;
    }
    else {
        prev->next = temp->next;
    }
    free(temp);
}

void searchContact(struct phoneBook* head, char name[]) {
    struct phoneBook* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("%s: %s\n", temp->name, temp->phone_no);
            return;
        }
        temp = temp->next;
    }
    printf("Contact not found.\n");
}

void displayContacts(struct phoneBook* head) {
    struct phoneBook* temp = head;
    if (temp == NULL) {
        printf("Phone book is empty.\n");
    }
    while (temp != NULL) {
        printf("%s: %s\n", temp->name, temp->phone_no);
        temp = temp->next;
    }
}

int main() {
    struct phoneBook* head = NULL;
    int choice;
    char name[50], phone_no[20];
    printf("Dynamic Phone Book Example\n\n");
    do {
        printf("Enter the number of your choice:\n");
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. Search Contact\n");
        printf("4. Display Contacts\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter phone number: ");
            scanf("%s", phone_no);
            addContact(&head, name, phone_no);
            printf("Contact added successfully.\n");
            break;
        case 2:
            printf("Enter name: ");
            scanf("%s", name);
            deleteContact(&head, name);
            break;
        case 3:
            printf("Enter name: ");
            scanf("%s", name);
            searchContact(head, name);
            break;
        case 4:
            displayContacts(head);
            break;
        case 5:
            printf("Exiting application.\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
        printf("\n");
    } while (choice != 5);

    return 0;
}