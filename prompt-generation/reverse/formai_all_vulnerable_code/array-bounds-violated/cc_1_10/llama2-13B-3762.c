//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 20
#define MAX_PHONE_NUMBER_LENGTH 10

// Define a struct to store name and phone number
struct contact {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
};

// Function to print a friendly message
void say_hello(void) {
    printf("Hello, world! 👋\n");
}

// Function to create a new contact
struct contact create_contact(char *name, char *phone_number) {
    struct contact new_contact;
    strcpy(new_contact.name, name);
    strcpy(new_contact.phone_number, phone_number);
    return new_contact;
}

// Function to print all contacts
void print_contacts(struct contact *contacts) {
    int i;
    for (i = 0; i < 10; i++) {
        printf("%d. %s %s\n", i + 1, contacts[i].name, contacts[i].phone_number);
    }
}

int main(void) {
    // Create some contacts
    struct contact contact1 = create_contact("John", "555-1234");
    struct contact contact2 = create_contact("Jane", "555-5678");
    struct contact contact3 = create_contact("Bob", "555-9012");

    // Store the contacts in an array
    struct contact contacts[3] = {contact1, contact2, contact3};

    // Print all the contacts
    print_contacts(contacts);

    // Add a new contact
    struct contact new_contact = create_contact("Alice", "555-1111");
    contacts[3] = new_contact;

    // Print all the contacts again
    print_contacts(contacts);

    // Remove a contact
    contacts[0] = contacts[1];
    free(contacts[1].name);
    free(contacts[1].phone_number);

    // Print all the contacts again
    print_contacts(contacts);

    return 0;
}