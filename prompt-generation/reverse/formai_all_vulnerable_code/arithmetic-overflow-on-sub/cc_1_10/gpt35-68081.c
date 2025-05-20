//FormAI DATASET v1.0 Category: Phone Book ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define the phonebook structure
struct phonebook {
    char name[50];
    long int number;
};

// Global Variables
int MAX = 100;
int size = 0;
struct phonebook* book;

// Function Prototypes
void addContact(char*, long int);
void deleteContact(int);
void searchContact(char*);
void displayContacts();

// Function to add a new contact
void addContact(char* name, long int number) {
    if (size >= MAX) {
        printf("Phone book is full. Please delete some contacts to add new.\n");
        return;
    }
    strcpy(book[size].name, name);
    book[size].number = number;
    size++;
    printf("Contact added successfully.\n");
}

// Function to delete a contact
void deleteContact(int index) {
    if (index >= size) {
        printf("Invalid index. Please try again.\n");
        return;
    }
    while (index < size-1) {
        strcpy(book[index].name, book[index+1].name);
        book[index].number = book[index+1].number;
        index++;
    }
    size--;
    printf("Contact deleted successfully.\n");
}

// Function to search a contact
void searchContact(char* name) {
    int i, found = 0;
    for (i = 0; i < size; i++) {
        if (strcmp(name, book[i].name) == 0) {
            found = 1;
            printf("Name: %s | Number: %ld\n", book[i].name, book[i].number);
        }
    }
    if (found == 0) {
        printf("No contacts found.\n");
    }
}

// Function to display all contacts
void displayContacts() {
    if (size == 0) {
        printf("Phone book is empty.\n");
        return;
    }
    int i;
    for (i = 0; i < size; i++) {
        printf("%d. Name: %s | Number: %ld\n", i+1, book[i].name, book[i].number);
    }
}

// Main Function
int main() {
    book = (struct phonebook*) malloc(MAX * sizeof(struct phonebook));
    int choice;
    char name[50];
    long int number;
    while (1) {
        printf("\n\n1. Add Contact\n2. Delete Contact\n3. Search Contact\n4. Display Contacts\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter name: ");
                scanf(" %[^\n]s", name);
                printf("Enter number: ");
                scanf("%ld", &number);
                addContact(name, number);
                break;
            case 2:
                printf("Enter index of contact to be deleted: ");
                int index;
                scanf("%d", &index);
                deleteContact(index-1);
                break;
            case 3:
                printf("Enter name of contact to be searched: ");
                scanf(" %[^\n]s", name);
                searchContact(name);
                break;
            case 4:
                displayContacts();
                break;
            case 5:
                printf("Thanks for using Phone Book!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    free(book);
    return 0;
}