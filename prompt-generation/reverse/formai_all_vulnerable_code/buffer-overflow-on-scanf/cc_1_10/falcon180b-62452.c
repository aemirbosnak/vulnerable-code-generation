//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIST_SIZE 1000
#define MAX_EMAIL_LEN 100
#define MAX_NAME_LEN 50

// Define the structure for each contact in the mailing list
typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Contact;

// Function to add a new contact to the mailing list
void add_contact(Contact* contacts, int num_contacts, char* name, char* email) {
    if (num_contacts >= MAX_LIST_SIZE) {
        printf("Mailing list is full. Cannot add new contact.\n");
        return;
    }

    strcpy(contacts[num_contacts].name, name);
    strcpy(contacts[num_contacts].email, email);

    num_contacts++;
}

// Function to remove a contact from the mailing list
void remove_contact(Contact* contacts, int num_contacts, char* email) {
    int i;

    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].email, email) == 0) {
            memmove(&contacts[i], &contacts[i+1], (num_contacts - i - 1) * sizeof(Contact));
            num_contacts--;
            break;
        }
    }
}

// Function to print the entire mailing list
void print_list(Contact* contacts, int num_contacts) {
    int i;

    for (i = 0; i < num_contacts; i++) {
        printf("Name: %s\nEmail: %s\n", contacts[i].name, contacts[i].email);
    }
}

// Function to search for a contact by name or email
int search_contact(Contact* contacts, int num_contacts, char* search_query) {
    int i;

    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, search_query) == 0 || strcmp(contacts[i].email, search_query) == 0) {
            return i;
        }
    }

    return -1; // Contact not found
}

// Main function to interact with the user and manage the mailing list
int main() {
    Contact contacts[MAX_LIST_SIZE];
    int num_contacts = 0;
    char input[MAX_EMAIL_LEN];

    while (1) {
        printf("Mailing List Manager\n");
        printf("1. Add contact\n2. Remove contact\n3. Print list\n4. Search contact\n5. Exit\n");
        scanf("%d", &num_contacts);

        switch (num_contacts) {
        case 1:
            printf("Enter name: ");
            scanf("%s", &input);
            printf("Enter email: ");
            scanf("%s", &input);
            add_contact(contacts, num_contacts, input, input);
            break;

        case 2:
            printf("Enter email to remove: ");
            scanf("%s", &input);
            remove_contact(contacts, num_contacts, input);
            break;

        case 3:
            print_list(contacts, num_contacts);
            break;

        case 4:
            printf("Enter search query: ");
            scanf("%s", &input);
            int index = search_contact(contacts, num_contacts, input);

            if (index!= -1) {
                printf("Found contact at index %d\n", index);
            } else {
                printf("Contact not found.\n");
            }
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid option.\n");
        }
    }

    return 0;
}