//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_PHONE_NUMBER_LENGTH 10

// Structure to store contact information
typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
} contact_t;

// Function to read contact information from file
contact_t read_contact(const char* file_name) {
    contact_t contact;
    FILE* file = fopen(file_name, "r");

    // Read name
    fscanf(file, "%s", contact.name);

    // Read phone number
    fscanf(file, "%s", contact.phone_number);

    fclose(file);
    return contact;
}

// Function to write contact information to file
void write_contact(const char* file_name, const contact_t* contact) {
    FILE* file = fopen(file_name, "w");

    // Write name
    fprintf(file, "%s", contact->name);

    // Write phone number
    fprintf(file, "%s", contact->phone_number);

    fclose(file);
}

int main() {
    // Load contact information from file
    contact_t contact = read_contact("romantic_contacts.txt");

    // Print contact information
    printf("Name: %s\nPhone Number: %s\n", contact.name, contact.phone_number);

    // Modify contact information
    strcpy(contact.name, "My Love");
    strcpy(contact.phone_number, "1-800-I-LOVE-YOU");

    // Save modified contact information to file
    write_contact("romantic_contacts.txt", &contact);

    return 0;
}