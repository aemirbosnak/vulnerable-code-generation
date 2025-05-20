//FormAI DATASET v1.0 Category: Phone Book ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

struct contact {
    char name[50];
    char number[20];
    char email[50];
};

struct contact contacts[MAX_CONTACTS];
int num_contacts = 0;

void add_contact(char name[], char number[], char email[]) {
    // Check if the array is full
    if (num_contacts == MAX_CONTACTS) {
        printf("Sorry, the phone book is full. Cannot add new contact.\n");
        return;
    }
    
    // Check if the contact already exists
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            printf("Sorry, contact already exists in the phone book.\n");
            return;
        }
    }
    
    // Add the contact to the phone book
    strcpy(contacts[num_contacts].name, name);
    strcpy(contacts[num_contacts].number, number);
    strcpy(contacts[num_contacts].email, email);
    num_contacts++;
    
    printf("Contact added to the phone book.\n");
}

void search_contact(char name[]) {
    // Search for the contact in the phone book
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            printf("Contact details:\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Number: %s\n", contacts[i].number);
            printf("Email: %s\n", contacts[i].email);
            return;
        }
    }
    
    printf("Sorry, contact does not exist in the phone book.\n");
}

void list_contacts() {
    if (num_contacts == 0) {
        printf("Phone book is empty.\n");
        return;
    }
    
    printf("Contacts in the phone book:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%s (%s, %s)\n", contacts[i].name, contacts[i].number, contacts[i].email);
    }
}

int main() {
    int choice;
    char name[50], number[20], email[50];
    
    while (1) {
        printf("Phone Book:\n");
        printf("1. Add new contact\n");
        printf("2. Search contact\n");
        printf("3. List all contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter number: ");
                scanf("%s", number);
                printf("Enter email: ");
                scanf("%s", email);
                add_contact(name, number, email);
                break;
            case 2:
                printf("Enter name: ");
                scanf("%s", name);
                search_contact(name);
                break;
            case 3:
                list_contacts();
                break;
            case 4:
                printf("Exiting phone book.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
        
        printf("\n");
    }
    
    return 0;
}