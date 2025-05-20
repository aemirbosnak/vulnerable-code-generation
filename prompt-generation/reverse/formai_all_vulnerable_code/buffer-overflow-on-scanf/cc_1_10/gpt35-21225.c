//FormAI DATASET v1.0 Category: Phone Book ; Style: grateful
#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

// Structure to hold contact information
typedef struct {
    char name[50];
    char email[50];
    char phone_number[20];
} Contact;

// Function to add a contact to the phone book
void add_contact(Contact* contact_list, int* num_contacts) {
    if (*num_contacts == MAX_CONTACTS) {
        printf("Error: phone book is full.\n");
        return;
    }

    // Get user input
    printf("Enter contact name: ");
    scanf("%s", contact_list[*num_contacts].name);
    printf("Enter contact email: ");
    scanf("%s", contact_list[*num_contacts].email);
    printf("Enter contact phone number: ");
    scanf("%s", contact_list[*num_contacts].phone_number);

    // Increment number of contacts
    (*num_contacts)++;
}

// Function to search for contacts by name
void search_contacts(Contact* contact_list, int num_contacts) {
    // Get user input
    char search_name[50];
    printf("Enter name to search for: ");
    scanf("%s", search_name);

    // Search for contacts
    int num_results = 0;
    for (int i = 0; i < num_contacts; i++) {
        if (strstr(contact_list[i].name, search_name) != NULL) {
            printf("%s - %s - %s\n", contact_list[i].name, contact_list[i].email, contact_list[i].phone_number);
            num_results++;
        }
    }

    // Display number of results
    if (num_results == 0) {
        printf("No contacts found.\n");
    } else if (num_results == 1) {
        printf("1 contact found.\n");
    } else {
        printf("%d contacts found.\n", num_results);
    }
}

int main() {
    Contact contact_list[MAX_CONTACTS];
    int num_contacts = 0;
    int choice;

    printf("Welcome to the Grateful Phone Book!\n");

    // Display menu and get user input
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add contact\n");
        printf("2. Search contacts\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        // Perform action based on user choice
        switch (choice) {
            case 1:
                add_contact(contact_list, &num_contacts);
                break;
            case 2:
                search_contacts(contact_list, num_contacts);
                break;
            case 3:
                printf("Thank you for using the Grateful Phone Book!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}