//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 1000

typedef struct contact {
    char name[50];
    char phone[15];
} Contact;

Contact phonebook[MAX_CONTACTS];
int num_contacts = 0;

void add_contact() {
    char name[50];
    char phone[15];

    printf("Enter the name of the contact: ");
    scanf("%s", name);

    printf("Enter the phone number of the contact: ");
    scanf("%s", phone);

    strcpy(phonebook[num_contacts].name, name);
    strcpy(phonebook[num_contacts].phone, phone);

    num_contacts++;

    printf("Contact added successfully!\n");
}

void view_contacts() {
    int i;

    printf("Phonebook:\n");
    for (i = 0; i < num_contacts; i++) {
        printf("%d. %s - %s\n", i+1, phonebook[i].name, phonebook[i].phone);
    }
}

void search_contact() {
    char name[50];
    int i;

    printf("Enter the name of the contact to search: ");
    scanf("%s", name);

    for (i = 0; i < num_contacts; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Contact found:\n");
            printf("%s - %s\n", phonebook[i].name, phonebook[i].phone);
            return;
        }
    }

    printf("Contact not found.\n");
}

void delete_contact() {
    char name[50];

    printf("Enter the name of the contact to delete: ");
    scanf("%s", name);

    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            memmove(&phonebook[i], &phonebook[i+1], (num_contacts - i - 1) * sizeof(Contact));
            num_contacts--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }

    printf("Contact not found.\n");
}

int main() {
    int choice;

    do {
        printf("\nPhonebook Menu:\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_contact();
            break;
        case 2:
            view_contacts();
            break;
        case 3:
            search_contact();
            break;
        case 4:
            delete_contact();
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 5);

    return 0;
}