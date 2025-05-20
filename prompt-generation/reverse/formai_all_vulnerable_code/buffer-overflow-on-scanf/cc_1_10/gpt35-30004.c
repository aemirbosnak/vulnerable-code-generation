//FormAI DATASET v1.0 Category: Phone Book ; Style: ultraprecise
#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[30];
    char phone_number[20];
} Contact;

int num_contacts = 0;
Contact contacts[MAX_CONTACTS];

void add_contact() {
    if (num_contacts >= MAX_CONTACTS) {
        printf("Error: too many contacts\n");
        return;
    }
    Contact new_contact;
    printf("Enter name: ");
    scanf(" %[^\n]", new_contact.name);
    printf("Enter phone number: ");
    scanf(" %s", new_contact.phone_number);
    contacts[num_contacts] = new_contact;
    num_contacts++;
    printf("Contact added successfully!\n");
}

void list_contacts() {
    if (num_contacts == 0) {
        printf("No contacts found\n");
        return;
    }
    printf("Contacts:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%s - %s\n", contacts[i].name, contacts[i].phone_number);
    }
}

void search_contact() {
    if (num_contacts == 0) {
        printf("No contacts found\n");
        return;
    }
    char search_query[30];
    printf("Enter name or phone number to search: ");
    scanf(" %[^\n]", search_query);
    for (int i = 0; i < num_contacts; i++) {
        if (strstr(contacts[i].name, search_query) != NULL || strstr(contacts[i].phone_number, search_query) != NULL) {
            printf("%s - %s\n", contacts[i].name, contacts[i].phone_number);
        }
    }
}

void delete_contact() {
    if (num_contacts == 0) {
        printf("No contacts found\n");
        return;
    }
    char delete_query[30];
    printf("Enter name or phone number to delete: ");
    scanf(" %[^\n]", delete_query);
    for (int i = 0; i < num_contacts; i++) {
        if (strstr(contacts[i].name, delete_query) != NULL || strstr(contacts[i].phone_number, delete_query) != NULL) {
            for (int j = i; j < num_contacts - 1; j++) {
                contacts[j] = contacts[j+1];
            }
            num_contacts--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found\n");
}

int main() {
    while (1) {
        printf("\nC Phone Book\n");
        printf("1. Add Contact\n");
        printf("2. List Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                list_contacts();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                delete_contact();
                break;
            case 5:
                printf("Exiting C Phone Book... Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}