//FormAI DATASET v1.0 Category: Phone Book ; Style: happy
#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone_number[15];
} Contact;

void print_menu(void);
Contact input_contact(void);
void print_contacts(Contact[], int);
void search_contacts(Contact[], int);
void add_contact(Contact[], int *);
void delete_contact(Contact[], int *);

int main(void) {
    Contact phonebook[MAX_CONTACTS];
    int num_contacts = 0;

    int choice;
    do {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact(phonebook, &num_contacts);
                break;

            case 2:
                delete_contact(phonebook, &num_contacts);
                break;

            case 3:
                search_contacts(phonebook, num_contacts);
                break;

            case 4:
                print_contacts(phonebook, num_contacts);
                break;

            case 5:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please choose again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void print_menu(void) {
    printf("Welcome to the Happy Phone Book!\n");
    printf("1. Add contact\n");
    printf("2. Delete contact\n");
    printf("3. Search contacts\n");
    printf("4. Print all contacts\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

Contact input_contact(void) {
    Contact new_contact;
    printf("Enter the name: ");
    scanf("%s", new_contact.name);
    printf("Enter the phone number: ");
    scanf("%s", new_contact.phone_number);
    return new_contact;
}

void print_contacts(Contact contacts[], int num_contacts) {
    if (num_contacts == 0) {
        printf("No contacts to display!\n");
        return;
    }
    printf("All contacts:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%s: %s\n", contacts[i].name, contacts[i].phone_number);
    }
}

void search_contacts(Contact contacts[], int num_contacts) {
    printf("Enter the name to search for: ");
    char name[50];
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            printf("%s: %s\n", contacts[i].name, contacts[i].phone_number);
            found = 1;
        }
    }

    if (!found) {
        printf("No matching contacts found!\n");
    }
}

void add_contact(Contact contacts[], int *num_contacts) {
    contacts[*num_contacts] = input_contact();
    (*num_contacts)++;
    printf("Contact added successfully!\n");
}

void delete_contact(Contact contacts[], int *num_contacts) {
    printf("Enter the name of the contact to delete: ");
    char name[50];
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < *num_contacts; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            for (int j = i; j < (*num_contacts) - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*num_contacts)--;
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Contact deleted successfully!\n");
    } else {
        printf("Contact not found!\n");
    }
}