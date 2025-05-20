//Code Llama-13B DATASET v1.0 Category: Phone Book ; Style: Sherlock Holmes
// C Phone Book Example Program in a Sherlock Holmes Style

#include <stdio.h>
#include <string.h>

// Structure to store contact details
struct contact {
    char name[50];
    char number[20];
};

// Function to add a contact to the phone book
void add_contact(struct contact *contacts, int *size, int *capacity) {
    if (*size == *capacity) {
        *capacity *= 2;
        contacts = realloc(contacts, *capacity * sizeof(struct contact));
    }
    printf("Enter name: ");
    fgets(contacts[*size].name, 50, stdin);
    printf("Enter number: ");
    fgets(contacts[*size].number, 20, stdin);
    (*size)++;
}

// Function to search for a contact in the phone book
struct contact *search_contact(struct contact *contacts, int size, char *name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            return &contacts[i];
        }
    }
    return NULL;
}

// Function to print all contacts in the phone book
void print_contacts(struct contact *contacts, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s: %s\n", contacts[i].name, contacts[i].number);
    }
}

int main() {
    struct contact *contacts = NULL;
    int size = 0;
    int capacity = 1;

    // Add contacts to the phone book
    add_contact(contacts, &size, &capacity);
    add_contact(contacts, &size, &capacity);
    add_contact(contacts, &size, &capacity);

    // Search for a contact in the phone book
    char name[50];
    printf("Enter name to search: ");
    fgets(name, 50, stdin);
    struct contact *result = search_contact(contacts, size, name);
    if (result != NULL) {
        printf("Found contact: %s: %s\n", result->name, result->number);
    } else {
        printf("Contact not found.\n");
    }

    // Print all contacts in the phone book
    print_contacts(contacts, size);

    return 0;
}