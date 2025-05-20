//FormAI DATASET v1.0 Category: Phone Book ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000

//Structure to hold the contact details
struct contact {
    char name[MAX];
    char phone[MAX];
    char email[MAX];
};

//Function to display the menu
void displayMenu() {
    printf("\n\nPhone Book\n\n");
    printf("1. Add Contact\n");
    printf("2. View All Contacts\n");
    printf("3. Search Contacts\n");
    printf("4. Edit Contact\n");
    printf("5. Delete Contact\n");
    printf("6. Exit\n");
    printf("\nEnter your choice: ");
}

//Function to add contact details
void addContact(struct contact* phonebook, int* count) {
    printf("\nEnter name: ");
    scanf(" %[^\n]", phonebook[*count].name);
    
    printf("Enter phone number: ");
    scanf(" %[^\n]", phonebook[*count].phone);
    
    printf("Enter email address: ");
    scanf(" %[^\n]", phonebook[*count].email);
    
    (*count)++;
    printf("\nContact added successfully!\n");
}

//Function to view all contacts
void viewAllContacts(struct contact* phonebook, int count) {
    if(count==0) printf("\nPhone book is empty!\n");
    else {
        printf("\nName\t\tPhone Number\t\tEmail Address\n");
        for(int i=0;i<count;i++) {
            printf("%s\t\t%s\t\t%s\n", phonebook[i].name, phonebook[i].phone, phonebook[i].email);
        }
    }
}

//Function to search contacts
void searchContact(struct contact* phonebook, int count) {
    char name[MAX];
    printf("\nEnter name to search: ");
    scanf(" %[^\n]", name);

    int found = 0;
    for(int i=0;i<count;i++) {
        if(strcmp(phonebook[i].name, name)==0) {
            printf("\nName\t\tPhone Number\t\tEmail Address\n");
            printf("%s\t\t%s\t\t%s\n", phonebook[i].name, phonebook[i].phone, phonebook[i].email);
            found = 1;
            break;
        }
    }

    if(!found) printf("\nContact not found!\n");
}

//Function to edit contact details
void editContact(struct contact* phonebook, int count) {
    char name[MAX];
    printf("\nEnter name to edit: ");
    scanf(" %[^\n]", name);

    int found = 0;
    for(int i=0;i<count;i++) {
        if(strcmp(phonebook[i].name, name)==0) {
            printf("\nEnter new phone number: ");
            scanf(" %[^\n]", phonebook[i].phone);
            
            printf("Enter new email address: ");
            scanf(" %[^\n]", phonebook[i].email);

            printf("\nContact edited successfully!\n");
            found = 1;
            break;
        }
    }

    if(!found) printf("\nContact not found!\n");
}

//Function to delete contact
void deleteContact(struct contact* phonebook, int* count) {
    char name[MAX];
    printf("\nEnter name to delete: ");
    scanf(" %[^\n]", name);

    int found = 0;
    for(int i=0;i<(*count);i++) {
        if(strcmp(phonebook[i].name, name)==0) {
            for(int j=i;j<(*count)-1;j++) {
                phonebook[j] = phonebook[j+1];
            }
            (*count)--;
            printf("\nContact deleted successfully!\n");
            found = 1;
            break;
        }
    }
    
    if(!found) printf("\nContact not found!\n");
}

int main() {
    struct contact phonebook[MAX];
    int count = 0;
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);
        switch(choice) {
            case 1: addContact(phonebook, &count);
                    break;
            case 2: viewAllContacts(phonebook, count);
                    break;
            case 3: searchContact(phonebook, count);
                    break;
            case 4: editContact(phonebook, count);
                    break;
            case 5: deleteContact(phonebook, &count);
                    break;
            case 6: printf("\nExiting Phone Book. Goodbye!\n");
                    exit(0);
            default: printf("Invalid choice. Please try again!\n");
        }
    } while (choice!=6);

    return 0;
}