//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Structure to store a contact
struct contact {
    char name[50];
    char phone_number[20];
};

// Function to add a contact
void add_contact(struct contact *phonebook, int * num_contacts) {
    printf("Enter name: ");
    scanf("%s", phonebook[*num_contacts].name);

    printf("Enter phone number: ");
    scanf("%s", phonebook[*num_contacts].phone_number);

    (*num_contacts)++; // Increment the number of contacts
}

// Function to search for a contact
void search_contact(struct contact *phonebook, int num_contacts) {
    char search_name[50];

    printf("Enter the name you want to search for: ");
    scanf("%s", search_name);

    int found = 0;

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phonebook[i].name, search_name) == 0) {
            printf("Name: %s\n", phonebook[i].name);
            printf("Phone number: %s\n", phonebook[i].phone_number);
            found = 1;
        }
    }

    if (!found) printf("Contact not found.\n");
}

// Function to delete a contact
void delete_contact(struct contact *phonebook, int * num_contacts) {
    char delete_name[50];

    printf("Enter the name of the contact you want to delete: ");
    scanf("%s", delete_name);

    int found = 0;

    for (int i = 0; i < *num_contacts; i++) {
        if (strcmp(phonebook[i].name, delete_name) == 0) {
            // Shift the contacts after the deleted contact
            for (int j = i; j < *num_contacts - 1; j++) {
                phonebook[j] = phonebook[j + 1];
            }
            (*num_contacts)--;
            found = 1;
        }
    }

    if (!found) printf("Contact not found.\n");
}

// Function to print the phone book
void print_phonebook(struct contact *phonebook, int num_contacts) {
    printf("\nPhone book:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%s - %s\n", phonebook[i].name, phonebook[i].phone_number);
    }
}

int main() {
    struct contact phonebook[100]; // Array of contacts
    int num_contacts = 0; // Number of contacts

    int choice;

    do {
        printf("\nPhone Book Menu:\n");
        printf("1. Add a contact\n");
        printf("2. Search for a contact\n");
        printf("3. Delete a contact\n");
        printf("4. Print the phone book\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact(phonebook, &num_contacts);
                break;
            case 2:
                search_contact(phonebook, num_contacts);
                break;
            case 3:
                delete_contact(phonebook, &num_contacts);
                break;
            case 4:
                print_phonebook(phonebook, num_contacts);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}