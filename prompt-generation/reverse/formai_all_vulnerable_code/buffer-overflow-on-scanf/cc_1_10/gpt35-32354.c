//FormAI DATASET v1.0 Category: Phone Book ; Style: real-life
#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    long int number;
} contact_t;

void add_contact(contact_t contacts[], int *num_contacts);
void search_contact(contact_t contacts[], int num_contacts);
void display_contacts(contact_t contacts[], int num_contacts);
void delete_contact(contact_t contacts[], int *num_contacts);

int main() {
    int choice, num_contacts = 0;
    contact_t contacts[MAX_CONTACTS];

    do {
        printf("\n\nPhone Book\n");
        printf("1. Add a contact\n");
        printf("2. Search for a contact\n");
        printf("3. Display all contacts\n");
        printf("4. Delete a contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_contact(contacts, &num_contacts);
                break;
            case 2:
                search_contact(contacts, num_contacts);
                break;
            case 3:
                display_contacts(contacts, num_contacts);
                break;
            case 4:
                delete_contact(contacts, &num_contacts);
                break;
            case 5:
                printf("\nExiting Phone Book. Have a nice day!\n\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while(choice != 5);

    return 0;
}

void add_contact(contact_t contacts[], int *num_contacts) {
    if(*num_contacts == MAX_CONTACTS) {
        printf("\nPhone book is full. Cannot add a new contact.\n");
        return;
    }

    printf("\nEnter the name of the contact: ");
    scanf("%s", contacts[*num_contacts].name);

    printf("Enter the phone number of the contact: ");
    scanf("%ld", &contacts[*num_contacts].number);

    printf("\nContact added successfully!\n");

    (*num_contacts)++;
}

void search_contact(contact_t contacts[], int num_contacts) {
    char name[50];
    int i, found = 0;

    printf("\nEnter the name of the contact you want to search for: ");
    scanf("%s", name);

    for(i = 0; i < num_contacts; i++) {
        if(strcmp(name, contacts[i].name) == 0) {
            printf("\nName: %s\n", contacts[i].name);
            printf("Phone number: %ld\n", contacts[i].number);
            found = 1;
            break;
        }
    }

    if(!found)
        printf("\nContact not found.\n");
}

void display_contacts(contact_t contacts[], int num_contacts) {
    int i;

    if(num_contacts == 0) {
        printf("\nPhone book is empty.\n");
        return;
    }

    printf("\nContacts:\n");

    for(i = 0; i < num_contacts; i++) {
        printf("%d. Name: %s\n", i+1, contacts[i].name);
        printf("   Phone number: %ld\n", contacts[i].number);
    }
}

void delete_contact(contact_t contacts[], int *num_contacts) {
    char name[50];
    int i, found = 0;

    if(*num_contacts == 0) {
        printf("\nPhone book is empty. Cannot delete a contact.\n");
        return;
    }

    printf("\nEnter the name of the contact you want to delete: ");
    scanf("%s", name);

    for(i = 0; i < *num_contacts; i++) {
        if(strcmp(name, contacts[i].name) == 0) {
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("\nContact not found.\n");
        return;
    }

    for(; i < *num_contacts-1; i++)
        contacts[i] = contacts[i+1];

    (*num_contacts)--;

    printf("\nContact deleted successfully.\n");
}