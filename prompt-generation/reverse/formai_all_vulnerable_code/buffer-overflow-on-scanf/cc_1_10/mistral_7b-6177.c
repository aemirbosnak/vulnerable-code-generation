//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    char phone[20];
    int flag;
} Contact;

Contact contacts[MAX_ENTRIES];
int num_contacts = 0;

void add_contact() {
    if (num_contacts >= MAX_ENTRIES) {
        printf("Phone book is full.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", contacts[num_contacts].name);
    getchar(); // consume newline

    printf("Enter phone number: ");
    fgets(contacts[num_contacts].phone, sizeof(contacts[num_contacts].phone), stdin);
    contacts[num_contacts].phone[strcspn(contacts[num_contacts].phone, "\n")] = '\0';

    printf("Contact added successfully.\n");
    contacts[num_contacts].flag = 1;
    num_contacts++;
}

void search_contact() {
    char name[50];
    int i;

    printf("Enter name to search: ");
    scanf("%s", name);

    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0 && contacts[i].flag == 1) {
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            return;
        }
    }

    printf("Contact not found.\n");
}

void delete_contact() {
    char name[50];
    int i, j;

    printf("Enter name to delete: ");
    scanf("%s", name);

    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0 && contacts[i].flag == 1) {
            for (j = i; j < num_contacts - 1; j++) {
                contacts[j] = contacts[j+1];
            }
            contacts[num_contacts-1].flag = 0;
            num_contacts--;
            printf("Contact deleted successfully.\n");
            return;
        }
    }

    printf("Contact not found.\n");
}

void display_contacts() {
    int i;

    printf("\nContacts:\n");

    for (i = 0; i < num_contacts; i++) {
        if (contacts[i].flag == 1) {
            printf("%d. %s - %s\n", i+1, contacts[i].name, contacts[i].phone);
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nPhone Book\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Delete Contact\n");
        printf("4. Display Contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                search_contact();
                break;
            case 3:
                delete_contact();
                break;
            case 4:
                display_contacts();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}