//FormAI DATASET v1.0 Category: Mailing list manager ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Contact;

typedef struct {
    Contact contacts[MAX_EMAILS];
    int num_contacts;
} MailingList;

void add_contact(MailingList* list, Contact contact) {
    if (list->num_contacts == MAX_EMAILS) {
        printf("Mailing list is full. Cannot add any more contacts.\n");
    } else {
        list->contacts[list->num_contacts] = contact;
        list->num_contacts++;
    }
}

void remove_contact(MailingList* list, int index) {
    if (index < 0 || index >= list->num_contacts) {
        printf("Invalid index given.\n");
    } else {
        for (int i = index; i < list->num_contacts - 1; i++) {
            list->contacts[i] = list->contacts[i+1];
        }
        list->num_contacts--;
    }
}

void print_list(MailingList list) {
    printf("Mailing List:\n");
    printf("Name\t\t\tEmail\n");
    printf("----\t\t\t-----\n");
    for (int i = 0; i < list.num_contacts; i++) {
        printf("%s\t\t%s\n", list.contacts[i].name, list.contacts[i].email);
    }
}

int main() {
    MailingList list;
    list.num_contacts = 0;
    
    int choice;
    do {
        printf("\n");
        printf("Mailing List Manager\n");
        printf("--------------------\n");
        printf("1. Add Contact\n");
        printf("2. Remove Contact\n");
        printf("3. Print List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                Contact new_contact;
                printf("Enter contact name: ");
                scanf("%s", new_contact.name);
                printf("Enter contact email: ");
                scanf("%s", new_contact.email);
                add_contact(&list, new_contact);
                printf("Contact added successfully!\n");
                break;
            }
            case 2: {
                int index;
                printf("Enter index of contact to remove: ");
                scanf("%d", &index);
                remove_contact(&list, index);
                printf("Contact removed successfully!\n");
                break;
            }
            case 3: {
                print_list(list);
                break;
            }
            case 4:
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);
    
    return 0;
}