//FormAI DATASET v1.0 Category: Phone Book ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone_number[15];
} Contact;

void display_menu();
void add_contact(Contact contacts[], int *num_contacts);
void display_all_contacts(Contact contacts[], int num_contacts);
void search_contact(Contact contacts[], int num_contacts);
void delete_contact(Contact contacts[], int *num_contacts);

int main() {
    Contact contacts[MAX_CONTACTS];
    int num_contacts = 0;
    int choice;

    do {
        display_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact(contacts, &num_contacts);
                break;
            case 2:
                display_all_contacts(contacts, num_contacts);
                break;
            case 3:
                search_contact(contacts, num_contacts);
                break;
            case 4:
                delete_contact(contacts, &num_contacts);
                break;
            case 5:
                printf("\nExiting phone book. Bye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void display_menu() {
    printf("\n==== PHONE BOOK MENU ====\n");
    printf("\n1. Add contact");
    printf("\n2. Display all contacts");
    printf("\n3. Search for a contact");
    printf("\n4. Delete a contact");
    printf("\n5. Exit\n");
}

void add_contact(Contact contacts[], int *num_contacts) {
    Contact new_contact;
    printf("\nEnter name: ");
    scanf("%s", new_contact.name);
    printf("\nEnter phone number: ");
    scanf("%s", new_contact.phone_number);
    contacts[*num_contacts] = new_contact;
    (*num_contacts)++;
    printf("\nNew contact added successfully.\n");
}

void display_all_contacts(Contact contacts[], int num_contacts) {
    if (num_contacts == 0) {
        printf("\nThere are no contacts to display.\n");
        return;
    }

    printf("\n==== ALL CONTACTS (%d) ====\n", num_contacts);
    for (int i = 0; i < num_contacts; i++) {
        printf("%s --- %s\n", contacts[i].name, contacts[i].phone_number);
    }
}

void search_contact(Contact contacts[], int num_contacts) {
    if (num_contacts == 0) {
        printf("\nThere are no contacts to search.\n");
        return;
    }

    char search_name[50];
    printf("\nEnter name to search: ");
    scanf("%s", search_name);
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, search_name) == 0) {
            printf("\nContact found!\n%s --- %s\n", contacts[i].name, contacts[i].phone_number);
            return;
        }
    }
    printf("\nContact not found.\n");
}

void delete_contact(Contact contacts[], int *num_contacts) {
    if (*num_contacts == 0) {
        printf("\nThere are no contacts to delete.\n");
        return;
    }

    char delete_name[50];
    printf("\nEnter name to delete: ");
    scanf("%s", delete_name);
    int found_index = -1;
    for (int i = 0; i < *num_contacts; i++) {
        if (strcmp(contacts[i].name, delete_name) == 0) {
            found_index = i;
            break;
        }
    }
    if (found_index == -1) {
        printf("\nContact not found.\n");
    } else {
        for (int i = found_index; i < *num_contacts - 1; i++) {
            contacts[i] = contacts[i + 1];
        }
        (*num_contacts)--;
        printf("\nContact deleted successfully.\n");
    }
}