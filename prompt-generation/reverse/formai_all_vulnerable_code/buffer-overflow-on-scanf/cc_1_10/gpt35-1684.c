//FormAI DATASET v1.0 Category: Phone Book ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a phone book entry
struct PhoneBook {
    char name[50];
    char phone_number[20];
};

// Define a function to add an entry to the phone book
void addEntry(struct PhoneBook phone_book[], int *size) {
    char name[50];
    char phone_number[20];
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter phone number: ");
    scanf("%s", phone_number);
    strcpy(phone_book[*size].name, name);
    strcpy(phone_book[*size].phone_number, phone_number);
    *size += 1;
    printf("\nEntry added successfully!\n\n");
}

// Define a function to search for an entry in the phone book
void searchEntry(struct PhoneBook phone_book[], int size) {
    char name[50];
    printf("Enter name to search: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(name, phone_book[i].name) == 0) {
            printf("\n%s's phone number is %s\n\n", phone_book[i].name, phone_book[i].phone_number);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nSorry, no entry found for %s\n\n", name);
    }
}

// Define a function to display all entries in the phone book
void displayEntries(struct PhoneBook phone_book[], int size) {
    printf("\n\nPHONE BOOK ENTRIES\n\n");
    for (int i = 0; i < size; i++) {
        printf("%s - %s\n", phone_book[i].name, phone_book[i].phone_number);
    }
    printf("\n");
}

// Define the main function
int main() {
    struct PhoneBook phone_book[100];
    int size = 0;
    int choice;
    do {
        printf("\n\nPHONE BOOK MENU\n");
        printf("1. Add an entry\n");
        printf("2. Search for an entry\n");
        printf("3. Display all entries\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEntry(phone_book, &size);
                break;
            case 2:
                searchEntry(phone_book, size);
                break;
            case 3:
                displayEntries(phone_book, size);
                break;
            case 4:
                printf("\nGoodbye!\n\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n\n");
        }
    } while (choice != 4);
    return 0;
}