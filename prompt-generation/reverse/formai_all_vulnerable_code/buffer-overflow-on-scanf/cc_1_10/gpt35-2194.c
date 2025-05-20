//FormAI DATASET v1.0 Category: Phone Book ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
    char name[50];
    char phone[20];
    char email[50];
};

void displayContacts(struct contact phonebook[], int numContacts) {
    printf("\nContacts in phone book:\n");
    for (int i = 0; i < numContacts; i++) {
        printf("%s | %s | %s\n", phonebook[i].name, phonebook[i].phone, phonebook[i].email);
    }
}

void addContact(struct contact phonebook[], int numContacts) {
    char name[50];
    char phone[20];
    char email[50];
    
    printf("\nEnter name: ");
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = 0;
    
    printf("Enter phone number (format xxx-xxx-xxxx): ");
    fgets(phone, 20, stdin);
    phone[strcspn(phone, "\n")] = 0;
    
    printf("Enter email: ");
    fgets(email, 50, stdin);
    email[strcspn(email, "\n")] = 0;
    
    strcpy(phonebook[numContacts].name, name);
    strcpy(phonebook[numContacts].phone, phone);
    strcpy(phonebook[numContacts].email, email);
    
    printf("\nNew Contact Added!\n");
}

void searchContact(struct contact phonebook[], int numContacts) {
    char name[50];
    
    printf("\nEnter name to search: ");
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = 0;
    
    int found = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(name, phonebook[i].name) == 0) {
            printf("\nFound contact:\n%s | %s | %s\n", phonebook[i].name, phonebook[i].phone, phonebook[i].email);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nContact not found!\n");
    }
}

int main() {
    int numContacts = 0;
    int choice;
    struct contact phonebook[100];
    
    printf("Welcome to the Mind-Bending Phone Book!\n\n");
    
    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Display all contacts\n");
        printf("2. Add a new contact\n");
        printf("3. Search for a contact\n");
        printf("4. Quit\n\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();
        
        switch (choice) {
            case 1:
                displayContacts(phonebook, numContacts);
                break;
            case 2:
                addContact(phonebook, numContacts);
                numContacts++;
                break;
            case 3:
                searchContact(phonebook, numContacts);
                break;
            case 4:
                printf("\nThank you for using the Mind-Bending Phone Book!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}