//FormAI DATASET v1.0 Category: Phone Book ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char name[50];
    char phone[20];
};

void addContact(struct Contact *phonebook, int *numContacts);
void searchContact(struct Contact *phonebook, int numContacts);

int main() {
    struct Contact phonebook[100];
    int numContacts = 0;
    char choice;
    
    printf("Welcome to the Linux Phonebook!\n");
    
    while (1) {
        printf("\nEnter 'a' to add a contact, 's' to search for a contact, or 'q' to quit: ");
        scanf(" %c", &choice);
        
        switch (choice) {
            case 'a':
                addContact(phonebook, &numContacts);
                break;
            case 's':
                searchContact(phonebook, numContacts);
                break;
            case 'q':
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }
    
    return 0;
}

void addContact(struct Contact *phonebook, int *numContacts) {
    printf("\nEnter the name: ");
    scanf(" %[^\n]s", phonebook[*numContacts].name);
    printf("Enter the phone number: ");
    scanf(" %[^\n]s", phonebook[*numContacts].phone);
    
    printf("%s has been added to the phonebook.\n", phonebook[*numContacts].name);
    
    (*numContacts)++;
}

void searchContact(struct Contact *phonebook, int numContacts) {
    char name[50];
    printf("\nEnter the name to search for: ");
    scanf(" %[^\n]s", name);
    
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\nPhone: %s\n", phonebook[i].name, phonebook[i].phone);
            return;
        }
    }
    
    printf("%s not found in the phonebook.\n", name);
}