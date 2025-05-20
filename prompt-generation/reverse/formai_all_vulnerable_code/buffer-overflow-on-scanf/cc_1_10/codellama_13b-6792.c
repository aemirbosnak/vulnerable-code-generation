//Code Llama-13B DATASET v1.0 Category: Phone Book ; Style: detailed
// C Phone Book Example Program

#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 20
#define MAX_CONTACTS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
} Contact;

void print_menu();
void add_contact(Contact contacts[], int *contact_count);
void search_contact(Contact contacts[], int *contact_count);
void edit_contact(Contact contacts[], int *contact_count);
void delete_contact(Contact contacts[], int *contact_count);

int main() {
    Contact contacts[MAX_CONTACTS] = {};
    int contact_count = 0;

    print_menu();

    while (1) {
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact(contacts, &contact_count);
                break;
            case 2:
                search_contact(contacts, &contact_count);
                break;
            case 3:
                edit_contact(contacts, &contact_count);
                break;
            case 4:
                delete_contact(contacts, &contact_count);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}

void print_menu() {
    printf("------------------------------------\n");
    printf("   C Phone Book Example Program\n");
    printf("------------------------------------\n");
    printf("1. Add new contact\n");
    printf("2. Search contact\n");
    printf("3. Edit contact\n");
    printf("4. Delete contact\n");
    printf("5. Exit\n");
    printf("------------------------------------\n");
}

void add_contact(Contact contacts[], int *contact_count) {
    if (*contact_count >= MAX_CONTACTS) {
        printf("Contact limit reached. Cannot add more contacts.\n");
        return;
    }

    printf("Enter name: ");
    fgets(contacts[*contact_count].name, MAX_NAME_LENGTH, stdin);
    printf("Enter phone number: ");
    fgets(contacts[*contact_count].phone_number, MAX_PHONE_NUMBER_LENGTH, stdin);

    *contact_count += 1;
    printf("Contact added successfully.\n");
}

void search_contact(Contact contacts[], int *contact_count) {
    char name[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    fgets(name, MAX_NAME_LENGTH, stdin);

    for (int i = 0; i < *contact_count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Name: %s\nPhone number: %s\n", contacts[i].name, contacts[i].phone_number);
            return;
        }
    }

    printf("Contact not found.\n");
}

void edit_contact(Contact contacts[], int *contact_count) {
    char name[MAX_NAME_LENGTH];
    printf("Enter name to edit: ");
    fgets(name, MAX_NAME_LENGTH, stdin);

    for (int i = 0; i < *contact_count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Enter new phone number: ");
            fgets(contacts[i].phone_number, MAX_PHONE_NUMBER_LENGTH, stdin);
            printf("Contact edited successfully.\n");
            return;
        }
    }

    printf("Contact not found.\n");
}

void delete_contact(Contact contacts[], int *contact_count) {
    char name[MAX_NAME_LENGTH];
    printf("Enter name to delete: ");
    fgets(name, MAX_NAME_LENGTH, stdin);

    for (int i = 0; i < *contact_count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < *contact_count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            *contact_count -= 1;
            printf("Contact deleted successfully.\n");
            return;
        }
    }

    printf("Contact not found.\n");
}