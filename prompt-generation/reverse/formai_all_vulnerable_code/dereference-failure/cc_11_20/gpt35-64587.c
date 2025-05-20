//FormAI DATASET v1.0 Category: Mailing list manager ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_PHONE_LENGTH 20

struct Contact {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone_number[MAX_PHONE_LENGTH];
};

typedef struct Contact Contact;

int main() {
    int choice, num_contacts = 0;
    Contact* contacts = NULL;
    char input[MAX_NAME_LENGTH];
    
    while (1) {
        printf("1. Add contact\n");
        printf("2. Search for contact\n");
        printf("3. Print all contacts\n");
        printf("4. Quit\n");
        printf("Enter a choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                // Get input for new contact
                printf("\nEnter contact name: ");
                scanf("%s", input);
                contacts = realloc(contacts, (num_contacts + 1) * sizeof(Contact));
                strcpy(contacts[num_contacts].name, input);
                
                printf("Enter contact email address: ");
                scanf("%s", input);
                strcpy(contacts[num_contacts].email, input);
                
                printf("Enter contact phone number: ");
                scanf("%s", input);
                strcpy(contacts[num_contacts].phone_number, input);
                
                num_contacts++;
                printf("\nContact added!\n\n");
                break;
            
            case 2:
                // Search for a contact
                printf("\nEnter search term: ");
                scanf("%s", input);
                
                for (int i = 0; i < num_contacts; i++) {
                    if (strstr(contacts[i].name, input) != NULL || strstr(contacts[i].email, input) != NULL || strstr(contacts[i].phone_number, input) != NULL) {
                        printf("%s\n", contacts[i].name);
                        printf("%s\n", contacts[i].email);
                        printf("%s\n", contacts[i].phone_number);
                        printf("\n");
                    }
                }
                
                break;
            
            case 3:
                // Print all contacts
                printf("\n");
                for (int i = 0; i < num_contacts; i++) {
                    printf("%s\n", contacts[i].name);
                    printf("%s\n", contacts[i].email);
                    printf("%s\n", contacts[i].phone_number);
                    printf("\n");
                }
                break;
            
            case 4:
                // Quit program
                printf("\nGoodbye!\n");
                free(contacts);
                return 0;
            
            default:
                // Invalid input
                printf("\nInvalid choice, please try again.\n\n");
        }
    }
}