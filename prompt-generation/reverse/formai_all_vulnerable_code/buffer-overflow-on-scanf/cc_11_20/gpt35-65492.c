//FormAI DATASET v1.0 Category: Phone Book ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 50         // maximum number of contacts in the phone book
#define MAX_NAME_LENGTH 30      // maximum length of name of a contact

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone_number[11];
} contact_t;

int main() {
    contact_t phone_book[MAX_CONTACTS];
    int num_contacts = 0;       // current number of contacts in the phone book
    char option;

    printf("*** Welcome to the Phone Book Application ***\n");

    do {
        printf("\nOptions:\n1. Add a new contact\n2. Search for a contact\n3. View all contacts\n4. Exit\n");
        printf("Choose an option: ");
        scanf(" %c", &option);

        switch (option) {
            case '1':   // add a new contact
                if (num_contacts >= MAX_CONTACTS) {
                    printf("Maximum number of contacts reached!\n");
                } else {
                    contact_t new_contact;
                    printf("Enter name: ");
                    scanf("%s", new_contact.name);
                    printf("Enter phone number: ");
                    scanf("%s", new_contact.phone_number);
                    phone_book[num_contacts] = new_contact;
                    num_contacts++;
                    printf("Contact added successfully!\n");
                }
                break;
            
            case '2':   // search for a contact
                if (num_contacts == 0) {
                    printf("No contacts found!\n");
                } else {
                    char search_name[MAX_NAME_LENGTH];
                    printf("Enter name to search: ");
                    scanf("%s", search_name);
                    int found = 0;
                    for (int i = 0; i < num_contacts; i++) {
                        if (strcmp(phone_book[i].name, search_name) == 0) {
                            printf("Contact Found!\n");
                            printf("Name: %s\nPhone Number: %s\n", phone_book[i].name, phone_book[i].phone_number);
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        printf("Contact not found!\n");
                    }
                }
                break;
            
            case '3':   // view all contacts
                if (num_contacts == 0) {
                    printf("No contacts found!\n");
                } else {
                    printf("All Contacts:\n");
                    for (int i = 0; i < num_contacts; i++) {
                        printf("%d. Name: %s\n   Phone Number: %s\n", i+1, phone_book[i].name, phone_book[i].phone_number);
                    }
                }
                break;
            
            case '4':   // exit
                printf("Exiting Phone Book Application. Goodbye.\n");
                break;
            
            default:
                printf("Invalid option. Please try again.\n");         
        }

    } while (option != '4');

    return 0;
}