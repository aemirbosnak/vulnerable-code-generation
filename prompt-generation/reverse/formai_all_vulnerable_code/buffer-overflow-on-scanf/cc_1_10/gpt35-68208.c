//FormAI DATASET v1.0 Category: Phone Book ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for phone book entry
typedef struct {
    char name[50];
    char phone[20];
} entry_t;

// Function to add a new entry to the phone book
void add_entry(entry_t* phone_book, int* size) {
    // Prompt user for new entry information
    printf("Enter name: ");
    scanf("%s", phone_book[*size].name);
    printf("Enter phone number: ");
    scanf("%s", phone_book[*size].phone);
    
    // Increase phone_book size
    *size = *size + 1;
    
    printf("Entry added!\n");
}

// Function to remove an entry from the phone book
void remove_entry(entry_t* phone_book, int* size) {
    // Prompt user for entry name to be removed
    char name_remove[50];
    printf("Enter name to remove: ");
    scanf("%s", name_remove);
    
    // Search for entry to remove
    int index_remove = -1;
    for (int i = 0; i < *size; i++) {
        if (strcmp(phone_book[i].name, name_remove) == 0) {
            index_remove = i;
            break;
        }
    }
    
    // Remove entry if found
    if (index_remove != -1) {
        for (int i = index_remove; i < *size - 1; i++) {
            phone_book[i] = phone_book[i + 1];
        }
        *size = *size - 1;
        printf("Entry removed!\n");
    } else {
        printf("Entry not found.\n");
    }
}

// Function to display all entries in the phone book
void display_entries(entry_t* phone_book, int size) {
    printf("Phone Book Entries:\n");
    for (int i = 0; i < size; i++) {
        printf("Name: %s, Phone: %s\n", phone_book[i].name, phone_book[i].phone);
    }
}

// Main function
int main() {
    // Initialize phone_book and size
    entry_t phone_book[100];
    int size = 0;
    
    // Options menu loop
    int choice;
    while (1) {
        printf("Phone Book Options:\n");
        printf("1. Add entry\n");
        printf("2. Remove entry\n");
        printf("3. Display all entries\n");
        printf("4. Quit program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // Perform corresponding option based on choice
        switch(choice) {
            case 1:
                add_entry(phone_book, &size);
                break;
            case 2:
                remove_entry(phone_book, &size);
                break;
            case 3:
                display_entries(phone_book, size);
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}