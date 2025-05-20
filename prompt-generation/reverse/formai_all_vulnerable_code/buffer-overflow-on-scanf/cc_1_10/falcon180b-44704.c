//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[MAX_SIZE];
    char address[MAX_SIZE];
    char phone[MAX_SIZE];
} contact;

void add_contact(contact* contacts, int* num_contacts) {
    printf("Enter name: ");
    scanf("%[^\n]", contacts[*num_contacts].name);

    printf("Enter address: ");
    scanf("%[^\n]", contacts[*num_contacts].address);

    printf("Enter phone number: ");
    scanf("%[^\n]", contacts[*num_contacts].phone);

    (*num_contacts)++;
}

void view_contact(contact contact) {
    printf("Name: %s\n", contact.name);
    printf("Address: %s\n", contact.address);
    printf("Phone number: %s\n", contact.phone);
}

void search_contact(contact* contacts, int num_contacts, char* query) {
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, query) == 0) {
            view_contact(contacts[i]);
        }
    }
}

int main() {
    contact contacts[MAX_SIZE];
    int num_contacts = 0;

    printf("Welcome to the futuristic contact database!\n");

    while (1) {
        printf("Enter 1 to add a contact\n");
        printf("Enter 2 to view a contact\n");
        printf("Enter 3 to search for a contact\n");
        printf("Enter 4 to exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact(contacts, &num_contacts);
                break;
            case 2:
                printf("Enter contact number: ");
                int contact_num;
                scanf("%d", &contact_num);
                if (contact_num >= 0 && contact_num < num_contacts) {
                    view_contact(contacts[contact_num]);
                } else {
                    printf("Invalid contact number.\n");
                }
                break;
            case 3:
                printf("Enter search query: ");
                char query[MAX_SIZE];
                scanf("%[^\n]", query);
                search_contact(contacts, num_contacts, query);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}