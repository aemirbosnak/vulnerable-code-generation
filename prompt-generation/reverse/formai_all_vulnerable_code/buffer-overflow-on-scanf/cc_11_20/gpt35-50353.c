//FormAI DATASET v1.0 Category: Phone Book ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
    char name[50];
    char number[15];
    char email[100];
    char address[100];
};

int menu() {
    printf("\n------------------------\n");
    printf("      CYBERPHONE\n");
    printf("------------------------\n");
    printf("1. Add a Contact\n");
    printf("2. View All Contacts\n");
    printf("3. Search a Contact\n");
    printf("4. Edit a Contact\n");
    printf("5. Delete a Contact\n");
    printf("6. Exit\n");
    printf("------------------------\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);
    return choice;
}

int main() {
    printf("Welcome to CyberPhone!\n");
    int num_contacts = 0; // number of contacts
    struct contact contacts[50]; // array of contacts
    
    while (1) {
        int choice = menu();
        
        if (choice == 1) { // Add a Contact
            printf("\nEnter name: ");
            scanf("%s", contacts[num_contacts].name);
            printf("Enter number: ");
            scanf("%s", contacts[num_contacts].number);
            printf("Enter email: ");
            scanf("%s", contacts[num_contacts].email);
            printf("Enter address: ");
            scanf("%s", contacts[num_contacts].address);
            num_contacts++;
            printf("\nContact added!\n");
        }
        else if (choice == 2) { // View All Contacts
            if (num_contacts == 0) {
                printf("\nNo contacts found!\n");
            }
            else {
                printf("\nContacts:\n");
                for (int i = 0; i < num_contacts; i++) {
                    printf("%d. Name: %s\n   Number: %s\n   Email: %s\n   Address: %s\n", i+1, contacts[i].name, contacts[i].number, contacts[i].email, contacts[i].address);
                }
            }
        }
        else if (choice == 3) { // Search a Contact
            if (num_contacts == 0) {
                printf("\nNo contacts found!\n");
            }
            else {
                char search_name[50];
                printf("\nEnter name to search: ");
                scanf("%s", search_name);
                int found = 0;
                for (int i = 0; i < num_contacts; i++) {
                    if (strcmp(search_name, contacts[i].name) == 0) {
                        printf("\nContact found!\n");
                        printf("Name: %s\nNumber: %s\nEmail: %s\nAddress: %s\n", contacts[i].name, contacts[i].number, contacts[i].email, contacts[i].address);
                        found = 1;
                        break;
                    }
                }
                if (found == 0) {
                    printf("\nContact not found!\n");
                }
            }
        }
        else if (choice == 4) { // Edit a Contact
            if (num_contacts == 0) {
                printf("\nNo contacts found!\n");
            }
            else {
                char edit_name[50];
                printf("\nEnter name to edit: ");
                scanf("%s", edit_name);
                int found = 0;
                for (int i = 0; i < num_contacts; i++) {
                    if (strcmp(edit_name, contacts[i].name) == 0) {
                        printf("\nContact found!\n");
                        printf("Name: %s\nNumber: %s\nEmail: %s\nAddress: %s\n", contacts[i].name, contacts[i].number, contacts[i].email, contacts[i].address);
                        printf("\nEnter new name: ");
                        scanf("%s", contacts[i].name);
                        printf("Enter new number: ");
                        scanf("%s", contacts[i].number);
                        printf("Enter new email: ");
                        scanf("%s", contacts[i].email);
                        printf("Enter new address: ");
                        scanf("%s", contacts[i].address);
                        found = 1;
                        printf("\nContact edited!\n");
                        break;
                    }
                }
                if (found == 0) {
                    printf("\nContact not found!\n");
                }
            }
        }
        else if (choice == 5) { // Delete a Contact
            if (num_contacts == 0) {
                printf("\nNo contacts found!\n");
            }
            else {
                char delete_name[50];
                printf("\nEnter name to delete: ");
                scanf("%s", delete_name);
                int found = 0;
                for (int i = 0; i < num_contacts; i++) {
                    if (strcmp(delete_name, contacts[i].name) == 0) {
                        printf("\nContact found!\n");
                        printf("Name: %s\nNumber: %s\nEmail: %s\nAddress: %s\n", contacts[i].name, contacts[i].number, contacts[i].email, contacts[i].address);
                        for (int j = i; j < num_contacts-1; j++) {
                            strcpy(contacts[j].name, contacts[j+1].name);
                            strcpy(contacts[j].number, contacts[j+1].number);
                            strcpy(contacts[j].email, contacts[j+1].email);
                            strcpy(contacts[j].address, contacts[j+1].address);
                        }
                        num_contacts--;
                        found = 1;
                        printf("\nContact deleted!\n");
                        break;
                    }
                }
                if (found == 0) {
                    printf("\nContact not found!\n");
                }
            }
        }
        else if (choice == 6) { // Exit
            printf("\nThank you for using CyberPhone!\n");
            break;
        }
        else { // Invalid Choice
            printf("\nInvalid choice! Please try again.\n");
        }
    }
    
    return 0;
}