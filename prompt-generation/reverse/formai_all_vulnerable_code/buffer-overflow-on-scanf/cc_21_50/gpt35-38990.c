//FormAI DATASET v1.0 Category: Phone Book ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold contacts
typedef struct {
    char name[50];
    char phone[20];
} Contact;

int main() {
    // Declare variables
    Contact phonebook[100];
    int num_contacts = 0;
    int choice;

    printf("Welcome to the Decentralized Phonebook\n");

    // Main menu
    do {
        printf("\n--- Main Menu ---\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Edit Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Display All Contacts\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Add contact
                if(num_contacts < 100) {
                    printf("Enter name: ");
                    scanf("%s", phonebook[num_contacts].name);
                    printf("Enter phone number: ");
                    scanf("%s", phonebook[num_contacts].phone);
                    num_contacts++;
                    printf("Contact added successfully!\n");
                }
                else {
                    printf("Phonebook is full!\n");
                }
                break;

            case 2: // Search contact
                if(num_contacts > 0) {
                    char search_name[50];
                    printf("Enter name to search: ");
                    scanf("%s", search_name);
                    int found = 0;
                    for(int i = 0; i < num_contacts; i++) {
                        if(strcmp(search_name, phonebook[i].name) == 0) {
                            printf("Name: %s\nPhone: %s\n", phonebook[i].name, phonebook[i].phone);
                            found = 1;
                            break;
                        }
                    }
                    if(!found) {
                        printf("No contact found!\n");
                    }
                }
                else {
                    printf("Phonebook is empty!\n");
                }
                break;

            case 3: // Edit contact
                if(num_contacts > 0) {
                    char edit_name[50];
                    printf("Enter name of contact to edit: ");
                    scanf("%s", edit_name);
                    int found = 0;
                    for(int i = 0; i < num_contacts; i++) {
                        if(strcmp(edit_name, phonebook[i].name) == 0) {
                            printf("Enter new phone number: ");
                            scanf("%s", phonebook[i].phone);
                            printf("Contact edited successfully!\n");
                            found = 1;
                            break;
                        }
                    }
                    if(!found) {
                        printf("No contact found!\n");
                    }
                }
                else {
                    printf("Phonebook is empty!\n");
                }
                break;

            case 4: // Delete contact
                if(num_contacts > 0) {
                    char delete_name[50];
                    printf("Enter name of contact to delete: ");
                    scanf("%s", delete_name);
                    int found = 0;
                    for(int i = 0; i < num_contacts; i++) {
                        if(strcmp(delete_name, phonebook[i].name) == 0) {
                            for(int j = i; j < num_contacts - 1; j++) {
                                strcpy(phonebook[j].name, phonebook[j+1].name);
                                strcpy(phonebook[j].phone, phonebook[j+1].phone);
                            }
                            num_contacts--;
                            printf("Contact deleted successfully!\n");
                            found = 1;
                            break;
                        }
                    }
                    if(!found) {
                        printf("No contact found!\n");
                    }
                }
                else {
                    printf("Phonebook is empty!\n");
                }
                break;

            case 5: // Display all contacts
                if(num_contacts > 0) {
                    printf("Contacts:\n");
                    for(int i = 0; i < num_contacts; i++) {
                        printf("Name: %s\nPhone: %s\n", phonebook[i].name, phonebook[i].phone);
                    }
                }
                else {
                    printf("Phonebook is empty!\n");
                }
                break;

            case 0: // Exit
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 0);

    return 0;
}