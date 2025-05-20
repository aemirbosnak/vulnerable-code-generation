//FormAI DATASET v1.0 Category: Mailing list manager ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct contact_s {
    char *name;
    char *email;
    struct contact_s *next;
} Contact;

Contact *head = NULL;

void addContact(char *name, char *email) {
    Contact *newContact = (Contact*) malloc(sizeof(Contact));
    newContact->name = (char*) malloc(sizeof(char) * (strlen(name) + 1));
    newContact->email = (char*) malloc(sizeof(char) * (strlen(email) + 1));
    strcpy(newContact->name, name);
    strcpy(newContact->email, email);
    if (head == NULL) {
        head = newContact;
        head->next = NULL;
    } else {
        newContact->next = head;
        head = newContact;
    }
}

void printList(Contact *contact) {
    if (contact != NULL) {
        printf("\nName: %s  Email: %s\n", contact->name, contact->email);
        printList(contact->next);
    }
}

void deleteContact(Contact *prev, Contact *current, char *name) {
    if (current == NULL) {
        printf("Contact does not exist.\n");
    } else {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->name);
            free(current->email);
            free(current);
            printf("Contact deleted successfully.\n");
        } else {
            deleteContact(current, current->next, name);
        }
    }
}

int main() {
    int choice;
    char name[100], email[100];
    do {
        printf("\n---------------------------");
        printf("\nContact List Management Menu");
        printf("\n---------------------------");
        printf("\n1. Add Contact");
        printf("\n2. Delete Contact");
        printf("\n3. Print List");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                printf("\nEnter Name: ");
                fgets(name, 100, stdin);
                name[strlen(name) - 1] = '\0';
                printf("Enter Email: ");
                fgets(email, 100, stdin);
                email[strlen(email) - 1] = '\0';
                addContact(name, email);
                printf("\nContact added successfully.\n");
                break;
            case 2:
                printf("\nEnter Name: ");
                fgets(name, 100, stdin);
                name[strlen(name) - 1] = '\0';
                deleteContact(NULL, head, name);
                break;
            case 3:
                printf("\n---------------------------");
                printf("\nContacts");
                printf("\n---------------------------");
                printList(head);
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while(choice != 4);

    return 0;
}