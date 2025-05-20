//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[15];
} Contact;

Contact contacts[MAX_CONTACTS];
int num_contacts = 0;

void add_contact(const char* name, const char* phone) {
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Contact already exists.\n");
            return;
        }
    }

    if (num_contacts == MAX_CONTACTS) {
        printf("Phone book is full.\n");
        return;
    }

    strcpy(contacts[num_contacts].name, name);
    strcpy(contacts[num_contacts].phone, phone);
    num_contacts++;
    printf("Contact added successfully.\n");
}

void search_contact(const char* name, const char* phone) {
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Name: %s\nPhone: %s\n", contacts[i].name, contacts[i].phone);
        } else if (strcmp(contacts[i].phone, phone) == 0) {
            printf("Name: %s\nPhone: %s\n", contacts[i].name, contacts[i].phone);
        }
    }
}

void delete_contact(const char* name, const char* phone) {
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            strcpy(contacts[i].name, "");
            strcpy(contacts[i].phone, "");
            num_contacts--;
            printf("Contact deleted successfully.\n");
            return;
        } else if (strcmp(contacts[i].phone, phone) == 0) {
            strcpy(contacts[i].name, "");
            strcpy(contacts[i].phone, "");
            num_contacts--;
            printf("Contact deleted successfully.\n");
            return;
        }
    }

    printf("Contact not found.\n");
}

void update_contact(const char* name, const char* phone) {
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            strcpy(contacts[i].phone, phone);
            printf("Contact updated successfully.\n");
            return;
        }
    }

    printf("Contact not found.\n");
}

int main() {
    char name[50], phone[15];
    int choice;

    printf("Phone Book\n");
    printf("1. Add Contact\n");
    printf("2. Search Contact\n");
    printf("3. Delete Contact\n");
    printf("4. Update Contact\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    while (choice!= 5) {
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phone);
                add_contact(name, phone);
                break;
            case 2:
                printf("Enter name or phone number to search: ");
                scanf("%s", name);
                search_contact(name, phone);
                break;
            case 3:
                printf("Enter name or phone number to delete: ");
                scanf("%s", name);
                delete_contact(name, phone);
                break;
            case 4:
                printf("Enter name or phone number to update: ");
                scanf("%s", name);
                update_contact(name, phone);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        printf("Enter your choice: ");
        scanf("%d", &choice);
    }

    return 0;
}