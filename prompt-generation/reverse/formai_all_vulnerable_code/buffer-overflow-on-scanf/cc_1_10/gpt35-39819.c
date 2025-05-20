//FormAI DATASET v1.0 Category: Phone Book ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a structure to store contact information */
typedef struct {
    char name[50];
    char phone_number[20];
    char email[50];
} contact_t;

/* Define a function to add a new contact */
void add_contact(contact_t **phone_book, int *num_contacts) {
    /* Allocate memory for the new contact */
    *phone_book = (contact_t*) realloc(*phone_book, (*num_contacts + 1) * sizeof(contact_t));
    
    /* Prompt user for contact information */
    printf("\nEnter name: ");
    scanf("%s", (*phone_book)[*num_contacts].name);
    printf("Enter phone number: ");
    scanf("%s", (*phone_book)[*num_contacts].phone_number);
    printf("Enter email: ");
    scanf("%s", (*phone_book)[*num_contacts].email);
    
    /* Increment the number of contacts in the phone book */
    (*num_contacts)++;
}

/* Define a function to display all contacts in the phone book */
void display_contacts(contact_t *phone_book, int num_contacts) {
    printf("\nContacts:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%d. Name: %s\n   Phone Number: %s\n   Email: %s\n", i+1, phone_book[i].name, phone_book[i].phone_number, phone_book[i].email);
    }
}

/* Define a function to search for a contact by name */
void search_contact(contact_t *phone_book, int num_contacts) {
    /* Prompt user for the name of the contact to search for */
    char search_name[50];
    printf("\nEnter name to search for: ");
    scanf("%s", search_name);
    
    /* Search for the contact */
    int match_found = 0;
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, search_name) == 0) {
            printf("\nMatch found:\n");
            printf("Name: %s\nPhone Number: %s\nEmail: %s\n", phone_book[i].name, phone_book[i].phone_number, phone_book[i].email);
            match_found = 1;
            break;
        }
    }
    if (!match_found) {
        printf("\nNo match found for name: %s\n", search_name);
    }
}

/* Main function */
int main() {
    contact_t *phone_book = NULL;  /* Initialize phone book to NULL */
    int num_contacts = 0;  /* Initialize number of contacts to 0 */
    
    printf("Welcome to the phone book!\n");
    int choice;
    do {
        printf("\nMENU\n");
        printf("1. Add Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact by Name\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_contact(&phone_book, &num_contacts);
                break;
            case 2:
                if (num_contacts == 0) {
                    printf("\nThere are no contacts in the phone book.\n");
                } else {
                    display_contacts(phone_book, num_contacts);
                }
                break;
            case 3:
                if (num_contacts == 0) {
                    printf("\nThere are no contacts in the phone book.\n");
                } else {
                    search_contact(phone_book, num_contacts);
                }
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 4);
    
    /* Free memory allocated for phone book */
    free(phone_book);
    
    return 0;
}