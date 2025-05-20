//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LEN 30
#define MAX_NUMBER_LEN 15

// Phonebook contact structure
typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} Contact;

// Function to add a contact to the phonebook
void add_contact(Contact* phonebook, int num_contacts, char* name, char* number) {
    if (num_contacts >= MAX_CONTACTS) {
        printf("Phonebook is full! ");
        return;
    }

    strcpy(phonebook[num_contacts].name, name);
    strcpy(phonebook[num_contacts].number, number);
    num_contacts++;
}

// Function to search for a contact in the phonebook
int search_contact(Contact* phonebook, int num_contacts, char* name) {
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Found contact: %s - %s\n", phonebook[i].name, phonebook[i].number);
            return i;
        }
    }

    printf("Contact not found. ");
    return -1;
}

// Function to delete a contact from the phonebook
void delete_contact(Contact* phonebook, int num_contacts, int contact_index) {
    if (contact_index < 0 || contact_index >= num_contacts) {
        printf("Invalid contact index. ");
        return;
    }

    num_contacts--;
    for (int i = contact_index; i < num_contacts; i++) {
        strcpy(phonebook[i].name, phonebook[i+1].name);
        strcpy(phonebook[i].number, phonebook[i+1].number);
    }
}

// Function to display all contacts in the phonebook
void display_contacts(Contact* phonebook, int num_contacts) {
    printf("Phonebook:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%s - %s\n", phonebook[i].name, phonebook[i].number);
    }
}

int main() {
    Contact phonebook[MAX_CONTACTS];
    int num_contacts = 0;

    while (1) {
        printf("1. Add contact\n2. Search contact\n3. Delete contact\n4. Display all contacts\n5. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[MAX_NAME_LEN];
                char number[MAX_NUMBER_LEN];
                printf("Enter contact name: ");
                scanf("%s", name);
                printf("Enter contact number: ");
                scanf("%s", number);
                add_contact(phonebook, num_contacts, name, number);
                break;
            }
            case 2: {
                char name[MAX_NAME_LEN];
                printf("Enter contact name to search: ");
                scanf("%s", name);
                int contact_index = search_contact(phonebook, num_contacts, name);
                if (contact_index!= -1) {
                    printf("Contact found at index %d\n", contact_index);
                }
                break;
            }
            case 3: {
                int contact_index;
                printf("Enter contact index to delete: ");
                scanf("%d", &contact_index);
                delete_contact(phonebook, num_contacts, contact_index);
                break;
            }
            case 4: {
                display_contacts(phonebook, num_contacts);
                break;
            }
            case 5: {
                exit(0);
            }
            default: {
                printf("Invalid choice. ");
            }
        }
    }

    return 0;
}