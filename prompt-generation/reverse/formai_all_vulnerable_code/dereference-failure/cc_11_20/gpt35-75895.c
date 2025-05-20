//FormAI DATASET v1.0 Category: Phone Book ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contacts {
    char name[30];
    char phone_number[15];
    struct contacts *next;
};

int main() {
    printf("Welcome to the Curious Phone Book!\n");
    printf("What would you like to do?\n");
    
    // Create an empty head pointer
    struct contacts *head = NULL;
    
    while(1) {
        printf("\n1. Add a contact\n2. Search for a contact\n3. Display all contacts\n4. Quit\n\n");
        int choice;
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: {
                printf("Enter name: ");
                char name[30];
                scanf("%s", name);
                
                printf("Enter phone number: ");
                char phone_num[15];
                scanf("%s", phone_num);
                
                // Initialize a new contact
                struct contacts *new_contact = (struct contacts*) malloc(sizeof(struct contacts));
                strcpy(new_contact->name, name);
                strcpy(new_contact->phone_number, phone_num);
                
                // Add the new contact to the list
                if(head == NULL) {
                    head = new_contact;
                    new_contact->next = NULL;
                } else {
                    new_contact->next = head;
                    head = new_contact;
                }
                printf("\n%s has been added to your contacts.\n", name);
                break;
            }
            
            case 2: {
                printf("Enter contact name: ");
                char search_name[30];
                scanf("%s", search_name);
                struct contacts *search_contact = head;
                int contact_found = 0;
                
                // Find the contact
                while(search_contact != NULL) {
                    if(strcmp(search_contact->name, search_name) == 0) {
                        printf("Contact found! %s's phone number is %s.\n", search_name, search_contact->phone_number);
                        contact_found = 1;
                        break;
                    }
                    search_contact = search_contact->next;
                }
                if(contact_found == 0) {
                    printf("%s not found in contacts.\n", search_name);
                }
                break;
            }
            
            case 3: {
                printf("Your Phone Book:\n");
                struct contacts *current_contact = head;
                
                // Print all contacts
                while(current_contact != NULL) {
                    printf("%s\t%s\n", current_contact->name, current_contact->phone_number);
                    current_contact = current_contact->next;
                }
                break;
            }
            
            case 4: {
                printf("Goodbye!\n");
                exit(0);
            }
            
            default: {
                printf("Invalid choice. Try Again!\n");
                break;
            }
        }
    }
    return 0;
}