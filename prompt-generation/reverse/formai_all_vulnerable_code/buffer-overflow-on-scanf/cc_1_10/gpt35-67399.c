//FormAI DATASET v1.0 Category: Mailing list manager ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct to hold contact information
typedef struct contact {
    char name[50];
    char email[50];
    struct contact *next;
} Contact;

//Function to add a new contact to the list
void addContact(Contact **head) {
    Contact *newContact = (Contact *)malloc(sizeof(Contact));
    printf("Enter name: ");
    scanf("%s", newContact->name);
    printf("Enter email: ");
    scanf("%s", newContact->email);
    newContact->next = NULL;
    
    if (*head == NULL) {
        //If the list is empty, set the new contact as the head
        *head = newContact;
    } else {
        Contact *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newContact;
    }
    printf("\nNew contact added successfully!\n\n");
}

//Function to print all the contacts in the list
void printContacts(Contact **head) {
    if (*head == NULL) {
        printf("No contacts found!\n\n");
    } else {
        Contact *temp = *head;
        printf("%-20s %-20s\n", "Name", "Email");
        printf("----------------------------------------\n");
        while (temp != NULL) {
            printf("%-20s %-20s\n", temp->name, temp->email);
            temp = temp->next;
        }
        printf("\n");
    }
}

//Function to search for a contact by name
void searchContact(Contact **head, char* name) {
    if (*head == NULL) {
        printf("No contacts found!\n\n");
    } else {
        Contact *temp = *head;
        while (temp != NULL) {
            if (strcmp(temp->name, name) == 0) {
                printf("Contact found!\n\n");
                printf("%-20s %-20s\n", "Name", "Email");
                printf("----------------------------------------\n");
                printf("%-20s %-20s\n", temp->name, temp->email);
                return;
            }
            temp = temp->next;
        }
        printf("Contact not found!\n\n");
    }
}

//Function to delete a contact by name
void deleteContact(Contact **head, char* name) {
    if (*head == NULL) {
        printf("No contacts found!\n\n");
    } else {
        Contact *temp = *head;
        if (strcmp(temp->name, name) == 0) {
            *head = (*head)->next;
            free(temp);
            printf("Contact deleted!\n\n");
            return;
        }
        while (temp->next != NULL) {
            if (strcmp(temp->next->name, name) == 0) {
                Contact *deleteContact = temp->next;
                temp->next = deleteContact->next;
                free(deleteContact);
                printf("Contact deleted!\n\n");
                return;
            }
            temp = temp->next;
        }
        printf("Contact not found!\n\n");
    }
}

int main() {
    Contact *head = NULL;
    int choice;
    
    while (1) {
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        
        switch(choice) {
            case 1:
                addContact(&head);
                break;
            case 2:
                printContacts(&head);
                break;
            case 3:
                printf("Enter name of contact to search: ");
                char searchName[50];
                scanf("%s", searchName);
                printf("\n");
                searchContact(&head, searchName);
                break;
            case 4:
                printf("Enter name of contact to delete: ");
                char deleteName[50];
                scanf("%s", deleteName);
                printf("\n");
                deleteContact(&head, deleteName);
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n\n");
        }
    }
    return 0;
}