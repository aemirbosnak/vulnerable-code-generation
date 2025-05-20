//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: visionary
#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 50

typedef struct {
    char name[50];
    char phone[15];
} Contact;

Contact contacts[MAX_CONTACTS];
int numContacts = 0;

int main() {
    int choice, i;
    char name[50], phone[15];
    
    printf("Welcome to the C Phone Book!\n");
    printf("-----------------------------\n");
    
    while (1) {
        printf("\n1. Add a new contact\n");
        printf("2. Delete a contact\n");
        printf("3. Search for a contact\n");
        printf("4. Display all contacts\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                printf("Enter the phone number: ");
                fgets(phone, sizeof(phone), stdin);
                phone[strcspn(phone, "\n")] = 0;
                
                if (numContacts >= MAX_CONTACTS) {
                    printf("The phone book is full.\n");
                    break;
                }
                
                strcpy(contacts[numContacts].name, name);
                strcpy(contacts[numContacts].phone, phone);
                numContacts++;
                
                printf("Contact added successfully.\n");
                break;
                
            case 2:
                printf("Enter the name of the contact to delete: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                
                for (i = 0; i < numContacts; i++) {
                    if (strcmp(contacts[i].name, name) == 0) {
                        for (int j = i; j < numContacts - 1; j++) {
                            contacts[j] = contacts[j + 1];
                        }
                        numContacts--;
                        break;
                    }
                }
                
                if (numContacts == 0) {
                    printf("Contact not found.\n");
                } else {
                    printf("Contact deleted successfully.\n");
                }
                
                break;
                
            case 3:
                printf("Enter the name of the contact to search for: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                
                for (i = 0; i < numContacts; i++) {
                    if (strcmp(contacts[i].name, name) == 0) {
                        printf("Name: %s\n", contacts[i].name);
                        printf("Phone: %s\n", contacts[i].phone);
                        break;
                    }
                }
                
                if (i == numContacts) {
                    printf("Contact not found.\n");
                }
                
                break;
                
            case 4:
                printf("Displaying all contacts:\n");
                for (i = 0; i < numContacts; i++) {
                    printf("Name: %s\n", contacts[i].name);
                    printf("Phone: %s\n", contacts[i].phone);
                }
                break;
                
            case 5:
                printf("Exiting the program.\n");
                break;
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}