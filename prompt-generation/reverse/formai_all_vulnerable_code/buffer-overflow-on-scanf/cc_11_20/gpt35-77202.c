//FormAI DATASET v1.0 Category: Phone Book ; Style: statistical
#include <stdio.h>
#include <string.h>

// struct representing a phone contact
struct Contact {
    char name[50];
    char phone_number[20];
};

int main() {
    printf("*** C Phone Book ***\n\n");

    // create an array of contacts to hold phone book data
    struct Contact contacts[100];
    int num_contacts = 0;

    // loop to prompt user for phone book actions
    char option;
    do {
        printf("Enter 'a' to add a contact, 'd' to delete a contact, or 'p' to print all contacts. Enter 'q' to quit.\n");
        scanf(" %c", &option);

        switch(option) {
            case 'a': // add a contact
                printf("Enter the contact's name: ");
                scanf(" %[^\n]s", contacts[num_contacts].name); // use %[^\n]s to read a whole line as input
                printf("Enter the contact's phone number: ");
                scanf(" %s", contacts[num_contacts].phone_number);
                num_contacts++;
                printf("Contact added.\n\n");
                break;
            case 'd': // delete a contact
                printf("Enter the name of the contact to delete: ");
                char name_to_delete[50];
                scanf(" %[^\n]s", name_to_delete);
                int contact_index = -1; // initialize to -1 to denote the contact wasn't found
                for (int i = 0; i < num_contacts; i++) {
                    if (strcmp(name_to_delete, contacts[i].name) == 0) {
                        contact_index = i;
                        break;
                    }
                }
                if (contact_index > -1) {
                    for (int i = contact_index; i < num_contacts-1; i++) {
                        strcpy(contacts[i].name, contacts[i+1].name);
                        strcpy(contacts[i].phone_number, contacts[i+1].phone_number);
                    }
                    num_contacts--;
                    printf("Contact deleted.\n\n");
                } else {
                    printf("Contact not found.\n\n");
                }
                break;
            case 'p': // print all contacts
                printf("Phone Book:\n");
                for (int i = 0; i < num_contacts; i++) {
                    printf("%s: %s\n", contacts[i].name, contacts[i].phone_number);
                }
                printf("\n");
                break;
            case 'q': // quit program
                printf("Goodbye!\n");
                break;
            default: // invalid option entered
                printf("Invalid option.\n\n");
        }

    } while (option != 'q');

    return 0;
}