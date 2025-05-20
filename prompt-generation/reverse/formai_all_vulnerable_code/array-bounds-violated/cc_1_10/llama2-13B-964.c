//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the phone book structure
typedef struct {
    char name[50];  // Name of the contact
    char number[20]; // Phone number
    int age;        // Age of the contact
} contact;

// Define a list of contacts
contact contacts[10];

// Function to add a new contact
void add_contact(char *name, char *number, int age) {
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Error: Contact already exists.\n");
            return;
        }
    }
    strcpy(contacts[i].name, name);
    strcpy(contacts[i].number, number);
    contacts[i].age = age;
    i++;
}

// Function to search for a contact
int search_contact(char *name) {
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to display all contacts
void display_contacts() {
    int i;
    for (i = 0; i < 10; i++) {
        printf("%d. %s %s %d\n", i + 1, contacts[i].name, contacts[i].number, contacts[i].age);
    }
}

// Function to main function
int main() {
    // Add some contacts
    add_contact("John Doe", "555-1234", 30);
    add_contact("Jane Doe", "555-5678", 25);
    add_contact("Bob Smith", "555-9012", 40);

    // Search for a contact
    int found = search_contact("John Doe");
    if (found != -1) {
        printf("Found John Doe at index %d\n", found);
    } else {
        printf("Not found\n");
    }

    // Display all contacts
    display_contacts();

    return 0;
}