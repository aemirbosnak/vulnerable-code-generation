//Code Llama-13B DATASET v1.0 Category: Phone Book ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 30
#define MAX_NUM_CONTACTS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone_number[15];
} Contact;

void add_contact(Contact contacts[], int *num_contacts) {
    printf("Enter the name of the contact: ");
    scanf("%s", contacts[*num_contacts].name);
    printf("Enter the phone number of the contact: ");
    scanf("%s", contacts[*num_contacts].phone_number);
    (*num_contacts)++;
}

void display_contacts(Contact contacts[], int num_contacts) {
    for (int i = 0; i < num_contacts; i++) {
        printf("%s: %s\n", contacts[i].name, contacts[i].phone_number);
    }
}

void delete_contact(Contact contacts[], int *num_contacts) {
    printf("Enter the name of the contact to delete: ");
    scanf("%s", contacts[*num_contacts].name);
    for (int i = 0; i < *num_contacts; i++) {
        if (strcmp(contacts[i].name, contacts[*num_contacts].name) == 0) {
            for (int j = i; j < *num_contacts; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*num_contacts)--;
            break;
        }
    }
}

void search_contact(Contact contacts[], int num_contacts) {
    printf("Enter the name of the contact to search for: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("%s: %s\n", contacts[i].name, contacts[i].phone_number);
            break;
        }
    }
}

int main() {
    Contact contacts[MAX_NUM_CONTACTS];
    int num_contacts = 0;

    while (1) {
        printf("Enter 1 to add a contact, 2 to display all contacts, 3 to delete a contact, 4 to search for a contact, and 5 to exit: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_contact(contacts, &num_contacts);
                break;
            case 2:
                display_contacts(contacts, num_contacts);
                break;
            case 3:
                delete_contact(contacts, &num_contacts);
                break;
            case 4:
                search_contact(contacts, num_contacts);
                break;
            case 5:
                return 0;
        }
    }

    return 0;
}