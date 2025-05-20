//FormAI DATASET v1.0 Category: Phone Book ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PhoneBook {
    char name[50];
    char phone[15];
    char email[50];
    struct PhoneBook* next;
} PhoneBook;

PhoneBook* head = NULL;

void addContact() {
    PhoneBook* newContact = (PhoneBook*) malloc(sizeof(PhoneBook));
    printf("Enter name: ");
    scanf("%s", newContact->name);
    printf("Enter phone number: ");
    scanf("%s", newContact->phone);
    printf("Enter email address: ");
    scanf("%s", newContact->email);
    newContact->next = NULL;
    if (head == NULL) {
        head = newContact;
    } else {
        PhoneBook* current = head;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = newContact;
    }
    printf("\nContact added successfully!\n\n");
}

void searchContact() {
    char searchTerm[50];
    printf("Enter name to search: ");
    scanf("%s", searchTerm);
    PhoneBook* current = head;
    int count = 0;
    while(current != NULL) {
        if (strcmp(current->name, searchTerm) == 0) {
            printf("\nContact found!\n");
            printf("Name: %s\nPhone: %s\nEmail: %s\n\n", current->name, current->phone, current->email);
            count++;
        }
        current = current->next;
    }
    if (count == 0) {
        printf("\nContact not found!\n\n");
    }
}

void displayContacts() {
    if (head == NULL) {
        printf("\nNo contacts in phone book!\n\n");
    } else {
        PhoneBook* current = head;
        printf("\n");
        while(current != NULL) {
            printf("Name: %s\nPhone: %s\nEmail: %s\n\n", current->name, current->phone, current->email);
            current = current->next;
        }
    }
}

void deleteContact() {
    char searchTerm[50];
    printf("Enter name to delete: ");
    scanf("%s", searchTerm);
    if (head == NULL) {
        printf("\nPhone book is empty!\n\n");
    } else if (strcmp(head->name, searchTerm) == 0) {
        head = head->next;
        printf("\nContact deleted!\n\n");
    } else {
        PhoneBook* current = head;
        PhoneBook* previous = NULL;
        int found = 0;
        while(current != NULL) {
            if (strcmp(current->name, searchTerm) == 0) {
                previous->next = current->next;
                found = 1;
                printf("\nContact deleted!\n\n");
                break;
            }
            previous = current;
            current = current->next;
        }
        if (found == 0) {
            printf("\nContact not found!\n\n");
        }
    }
}

int main() {
    int choice;
    while(1) {
        printf("Choose an option:\n");
        printf("1. Add a contact\n");
        printf("2. Search for a contact\n");
        printf("3. Display all contacts\n");
        printf("4. Delete a contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch(choice) {
            case 1:
                addContact();
                break;
            case 2:
                searchContact();
                break;
            case 3:
                displayContacts();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                printf("Thank you for using the phone book!\n");
                return 0;
            default:
                printf("Invalid choice! Please enter a valid choice.\n\n");
        }
    }
    return 0;
}