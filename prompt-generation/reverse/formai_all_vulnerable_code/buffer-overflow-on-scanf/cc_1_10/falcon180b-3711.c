//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

// Contact struct
typedef struct {
    char name[50];
    char phone[15];
} Contact;

// Function to add a contact
void addContact(Contact* contacts, int count, char* name, char* phone) {
    if (count >= MAX_CONTACTS) {
        printf("Phone book is full. Cannot add more contacts.\n");
        return;
    }

    strcpy(contacts[count].name, name);
    strcpy(contacts[count].phone, phone);

    count++;
}

// Function to search for a contact by name
int searchContactByName(Contact* contacts, int count, char* name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Name: %s\nPhone: %s\n", contacts[i].name, contacts[i].phone);
            return i;
        }
    }

    printf("Contact not found.\n");
    return -1;
}

// Function to search for a contact by phone number
int searchContactByPhone(Contact* contacts, int count, char* phone) {
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].phone, phone) == 0) {
            printf("Name: %s\nPhone: %s\n", contacts[i].name, contacts[i].phone);
            return i;
        }
    }

    printf("Contact not found.\n");
    return -1;
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int count = 0;

    // Add some contacts
    addContact(contacts, count, "John Doe", "123-456-7890");
    addContact(contacts, count, "Jane Doe", "987-654-3210");
    addContact(contacts, count, "Bob Smith", "555-555-5555");

    // Search for a contact by name
    char name[50];
    printf("Enter name to search: ");
    scanf("%s", name);
    int index = searchContactByName(contacts, count, name);
    if (index!= -1) {
        printf("Contact found at index %d.\n", index);
    }

    // Search for a contact by phone number
    char phone[15];
    printf("Enter phone number to search: ");
    scanf("%s", phone);
    index = searchContactByPhone(contacts, count, phone);
    if (index!= -1) {
        printf("Contact found at index %d.\n", index);
    }

    return 0;
}