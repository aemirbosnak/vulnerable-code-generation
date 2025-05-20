//FormAI DATASET v1.0 Category: File handling ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_ADDRESS_LENGTH 200
#define MAX_PHONE_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

// Function to print a contact's information
void printContact(Contact c) {
    printf("Name: %s\n", c.name);
    printf("Address: %s\n", c.address);
    printf("Phone: %s\n", c.phone);
}

// Function to create a new contact and save it to a file
void createContact() {
    Contact c;
    printf("Enter name: ");
    fgets(c.name, MAX_NAME_LENGTH, stdin);
    printf("Enter address: ");
    fgets(c.address, MAX_ADDRESS_LENGTH, stdin);
    printf("Enter phone: ");
    fgets(c.phone, MAX_PHONE_LENGTH, stdin);

    // Remove newline character from input
    c.name[strcspn(c.name, "\n")] = 0;
    c.address[strcspn(c.address, "\n")] = 0;
    c.phone[strcspn(c.phone, "\n")] = 0;
    
    FILE *fp = fopen("contacts.txt", "a");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return;
    }
    fprintf(fp, "%s\n%s\n%s\n", c.name, c.address, c.phone);
    fclose(fp);
}

// Function to display all contacts stored in the file
void displayContacts() {
    FILE *fp = fopen("contacts.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return;
    }
    Contact c;
    int contactCount = 0;
    while (fgets(c.name, MAX_NAME_LENGTH, fp) != NULL) {
        fgets(c.address, MAX_ADDRESS_LENGTH, fp);
        fgets(c.phone, MAX_PHONE_LENGTH, fp);
        c.name[strcspn(c.name, "\n")] = 0;
        c.address[strcspn(c.address, "\n")] = 0;
        c.phone[strcspn(c.phone, "\n")] = 0;
        printf("Contact %d:\n", ++contactCount);
        printContact(c);
        printf("\n");
    }
    fclose(fp);
}

int main() {
    int option;
    do {
        printf("Options:\n1. Create new contact\n2. Display all contacts\n3. Exit\n");
        scanf("%d", &option);
        getchar(); // Consume newline character left in input buffer
        
        switch (option) {
            case 1:
                createContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option selected.\n");
                break;
        }
    } while (option != 3);
    return 0;
}