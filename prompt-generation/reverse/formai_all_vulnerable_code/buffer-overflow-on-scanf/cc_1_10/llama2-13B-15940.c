//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 25
#define MAX_PHONE_NUMBER_LENGTH 15

// Define a struct to store names and phone numbers
struct contact {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
};

// Function to read a name and phone number from the user
void get_contact(struct contact *contact) {
    printf("What is your loved one's name? ");
    fgets(contact->name, MAX_NAME_LENGTH, stdin);
    printf("What is their phone number? ");
    fgets(contact->phone_number, MAX_PHONE_NUMBER_LENGTH, stdin);
}

// Function to print a list of contacts
void print_contacts(struct contact *contacts) {
    int i;
    for (i = 0; i < sizeof(contacts) / sizeof(contacts[0]); i++) {
        printf("%d. %s %s\n", i + 1, contacts[i].name, contacts[i].phone_number);
    }
}

// Function to add a new contact
void add_contact(struct contact *contacts, int num_contacts) {
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strlen(contacts[i].name) == 0 || strlen(contacts[i].phone_number) == 0) {
            break;
        }
    }
    if (i == num_contacts) {
        printf("Your contact list is full! Please delete an existing contact before adding a new one.\n");
        return;
    }
    contacts[i].name[0] = '\0';
    contacts[i].phone_number[0] = '\0';
    printf("Enter the name of your loved one: ");
    fgets(contacts[i].name, MAX_NAME_LENGTH, stdin);
    printf("Enter their phone number: ");
    fgets(contacts[i].phone_number, MAX_PHONE_NUMBER_LENGTH, stdin);
}

// Function to delete a contact
void delete_contact(struct contact *contacts, int num_contacts, int index) {
    if (index < 0 || index >= num_contacts) {
        printf("Invalid index! Please enter a valid index between 0 and %d.\n", num_contacts - 1);
        return;
    }
    memset(contacts[index].name, 0, MAX_NAME_LENGTH);
    memset(contacts[index].phone_number, 0, MAX_PHONE_NUMBER_LENGTH);
    for (int i = index; i < num_contacts - 1; i++) {
        contacts[i] = contacts[i + 1];
    }
    num_contacts--;
}

int main() {
    int num_contacts = 0;
    struct contact contacts[10];

    // Initialize the contact list
    for (int i = 0; i < 10; i++) {
        contacts[i].name[0] = '\0';
        contacts[i].phone_number[0] = '\0';
    }

    // Read and store contacts
    while (1) {
        int choice;
        printf("Menu:\n");
        printf("1. Add a new contact\n");
        printf("2. Delete a contact\n");
        printf("3. Print all contacts\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_contact(contacts, num_contacts);
                break;
            case 2:
                delete_contact(contacts, num_contacts, 0);
                break;
            case 3:
                print_contacts(contacts);
                break;
            default:
                printf("Invalid choice! Please enter a valid number between 1 and 3.\n");
                break;
        }
    }
    return 0;
}