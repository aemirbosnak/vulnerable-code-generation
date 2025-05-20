//Code Llama-13B DATASET v1.0 Category: Phone Book ; Style: secure
// A secure C phone book program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store phone book entries
struct phone_book_entry {
    char name[50];
    char phone_number[20];
};

// Function to add an entry to the phone book
void add_entry(struct phone_book_entry* phone_book, int* phone_book_size) {
    // Get user input for name and phone number
    char name[50];
    char phone_number[20];
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter phone number: ");
    scanf("%s", phone_number);

    // Check if the phone book is full
    if (*phone_book_size >= 100) {
        printf("Phone book is full, cannot add more entries\n");
        return;
    }

    // Add the new entry to the phone book
    strcpy(phone_book[*phone_book_size].name, name);
    strcpy(phone_book[*phone_book_size].phone_number, phone_number);
    *phone_book_size += 1;
}

// Function to search for an entry in the phone book
void search_entry(struct phone_book_entry* phone_book, int phone_book_size) {
    // Get user input for the name to search for
    char name[50];
    printf("Enter name to search for: ");
    scanf("%s", name);

    // Search for the entry in the phone book
    for (int i = 0; i < phone_book_size; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            printf("Found entry: %s - %s\n", phone_book[i].name, phone_book[i].phone_number);
            return;
        }
    }

    // If the entry is not found, print an error message
    printf("Entry not found\n");
}

// Function to remove an entry from the phone book
void remove_entry(struct phone_book_entry* phone_book, int* phone_book_size) {
    // Get user input for the name to remove
    char name[50];
    printf("Enter name to remove: ");
    scanf("%s", name);

    // Search for the entry in the phone book
    for (int i = 0; i < *phone_book_size; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            // Remove the entry from the phone book
            for (int j = i; j < *phone_book_size - 1; j++) {
                phone_book[j] = phone_book[j + 1];
            }
            *phone_book_size -= 1;
            printf("Entry removed\n");
            return;
        }
    }

    // If the entry is not found, print an error message
    printf("Entry not found\n");
}

// Function to print the phone book
void print_phone_book(struct phone_book_entry* phone_book, int phone_book_size) {
    printf("Phone book:\n");
    for (int i = 0; i < phone_book_size; i++) {
        printf("%s - %s\n", phone_book[i].name, phone_book[i].phone_number);
    }
}

int main() {
    // Initialize the phone book
    struct phone_book_entry phone_book[100];
    int phone_book_size = 0;

    // Main menu
    char option;
    do {
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Remove entry\n");
        printf("4. Print phone book\n");
        printf("5. Quit\n");
        printf("Enter option: ");
        scanf(" %c", &option);

        switch (option) {
            case '1':
                add_entry(phone_book, &phone_book_size);
                break;
            case '2':
                search_entry(phone_book, phone_book_size);
                break;
            case '3':
                remove_entry(phone_book, &phone_book_size);
                break;
            case '4':
                print_phone_book(phone_book, phone_book_size);
                break;
            case '5':
                return 0;
                break;
            default:
                printf("Invalid option\n");
                break;
        }
    } while (option != '5');

    return 0;
}