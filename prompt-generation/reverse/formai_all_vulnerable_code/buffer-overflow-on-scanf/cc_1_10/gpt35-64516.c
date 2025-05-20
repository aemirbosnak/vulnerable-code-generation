//FormAI DATASET v1.0 Category: Phone Book ; Style: synchronous
#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct Contact {
    char name[50];
    char number[20];
} Contact;

void add_contact(Contact contacts[], int *num_contacts)
{
    if (*num_contacts == MAX_CONTACTS) {
        printf("Error: Maximum number of contacts reached!\n");
        return;
    }
    
    Contact new_contact;
    printf("Enter name: ");
    scanf("%s", new_contact.name);
    printf("Enter number: ");
    scanf("%s", new_contact.number);
    
    contacts[*num_contacts] = new_contact;
    *num_contacts += 1;
    
    printf("Contact added successfully!\n");
}

void search_contact(Contact contacts[], int num_contacts)
{
    char name[50];
    printf("Enter name to search: ");
    scanf("%s", name);
    
    int found = 0;
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            printf("Name: %s\nNumber: %s\n", contacts[i].name, contacts[i].number);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Contact not found!\n");
    }
}

void print_contacts(Contact contacts[], int num_contacts)
{
    printf("Contacts:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("Name: %s\nNumber: %s\n", contacts[i].name, contacts[i].number);
    }
}

int main()
{
    Contact contacts[MAX_CONTACTS];
    int num_contacts = 0;
    
    while (1) {
        printf("Menu:\n1) Add contact\n2) Search contact\n3) Print contacts\n4) Exit\n");
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_contact(contacts, &num_contacts);
                break;
            case 2:
                search_contact(contacts, num_contacts);
                break;
            case 3:
                print_contacts(contacts, num_contacts);
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
}