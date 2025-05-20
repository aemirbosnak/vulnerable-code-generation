//FormAI DATASET v1.0 Category: Phone Book ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contacts {
    char name[50];
    char phoneNum[20];
    struct Contacts *next;
};

void addContact(struct Contacts **head) {
    struct Contacts *newContact = (struct Contacts*)malloc(sizeof(struct Contacts));
    printf("Enter name: ");
    scanf("%s", newContact->name);
    printf("Enter phone number: ");
    scanf("%s", newContact->phoneNum);
    newContact->next = *head;
    *head = newContact;
    printf("\nContact added!\n\n");
}

void editContact(struct Contacts *head, char name[50]) {
    while (head != NULL) {
        if (strcmp(head->name, name) == 0) {
            printf("Enter new phone number: ");
            scanf("%s", head->phoneNum);
            printf("\nContact updated!\n\n");
            return;
        }
        head = head->next;
    }
    printf("\nContact not found.\n\n");
}

void deleteContact(struct Contacts **head, char name[50]) {
    struct Contacts *temp = *head, *prev;

    if (temp != NULL && strcmp(temp->name, name) == 0) {
        *head = temp->next;
        free(temp);
        printf("\nContact deleted!\n\n");
        return;
    }
 
    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\nContact not found.\n\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("\nContact deleted!\n\n");
}

void searchContact(struct Contacts *head, char name[50]) {
    int found = 0;

    while (head != NULL) {
        if (strcmp(head->name, name) == 0) {
            printf("\n%s - %s\n\n", head->name, head->phoneNum);
            found = 1;
        }
        head = head->next;
    }

    if (!found) {
        printf("\nContact not found.\n\n");
    }
}

void displayContacts(struct Contacts *head) {
    printf("\n********** CONTACTS **********\n\n");
    while (head != NULL) {
        printf("%s - %s\n", head->name, head->phoneNum);
        head = head->next;
    }
    printf("\n*******************************\n\n");
}

void menu(struct Contacts **head) {
    int choice;
    char name[50];

    do {
        printf("1 - Add contact\n");
        printf("2 - Edit contact\n");
        printf("3 - Delete contact\n");
        printf("4 - Search contact\n");
        printf("5 - Display all contacts\n");
        printf("6 - Exit\n\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addContact(head);
                break;
            case 2:
                printf("Enter name of contact to edit: ");
                scanf("%s", name);
                editContact(*head, name);
                break;
            case 3:
                printf("Enter name of contact to delete: ");
                scanf("%s", name);
                deleteContact(head, name);
                break;
            case 4:
                printf("Enter name of contact to search: ");
                scanf("%s", name);
                searchContact(*head, name);
                break;
            case 5:
                displayContacts(*head);
                break;
            case 6:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice.\n\n");
        }
    } while (choice != 6);
}

int main() {
    struct Contacts *head = NULL;
    menu(&head);
    return 0;
}