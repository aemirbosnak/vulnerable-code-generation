//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 20
#define MAX_ENTRIES 100

// Structure to store contact information
typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
} contact_t;

// Function to read contact information from a file
contact_t *read_contacts(const char *filename) {
    contact_t *contacts = malloc(MAX_ENTRIES * sizeof(contact_t));
    int i = 0;
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    while (i < MAX_ENTRIES && fscanf(file, "%s %s", contacts[i].name, contacts[i].phone_number) == 2) {
        i++;
    }

    fclose(file);
    return contacts;
}

// Function to write contact information to a file
void write_contacts(const char *filename, contact_t *contacts) {
    int i = 0;
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    for (i = 0; i < MAX_ENTRIES; i++) {
        fprintf(file, "%s %s\n", contacts[i].name, contacts[i].phone_number);
    }

    fclose(file);
}

// Function to search for a contact by name
contact_t *search_contact(contact_t *contacts, const char *name) {
    int i = 0;

    for (i = 0; i < MAX_ENTRIES; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            return &contacts[i];
        }
    }

    return NULL;
}

int main() {
    // Load contact information from a file
    contact_t *contacts = read_contacts("contacts.txt");

    // Display the contacts
    printf("Contacts:\n");
    for (int i = 0; i < MAX_ENTRIES; i++) {
        printf("%d. %s %s\n", i + 1, contacts[i].name, contacts[i].phone_number);
    }

    // Add a new contact
    char new_name[] = "John Doe";
    char new_phone_number[] = "555-1234";
    contact_t new_contact = {new_name, new_phone_number};

    // Search for a contact by name
    contact_t *found_contact = search_contact(contacts, "Jane Doe");

    // Write the contact information to a new file
    write_contacts("new_contacts.txt", contacts);

    // Free memory
    free(contacts);

    return 0;
}