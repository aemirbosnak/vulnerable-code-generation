//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the PhoneBook struct with name, phone number, and timestamp
typedef struct {
    char name[50];
    char number[20];
    time_t timestamp;
} PhoneEntry;

// Define the PhoneBook array with maximum size and initialize all entries
#define MAX_ENTRIES 100
PhoneEntry phonebook[MAX_ENTRIES];
int numEntries = 0;

// Function to generate a unique ID for each entry
int generateID() {
    static int id = 0;
    return id++;
}

// Function to add a new entry to the phonebook
void addEntry(char* name, char* number) {
    if (numEntries < MAX_ENTRIES) {
        int id = generateID();
        strcpy(phonebook[numEntries].name, name);
        strcpy(phonebook[numEntries].number, number);
        phonebook[numEntries].timestamp = time(NULL);
        numEntries++;
        printf("Entry %d added: %s - %s\n", id, name, number);
    } else {
        printf("Phonebook is full.\n");
    }
}

// Function to search for an entry by name
void searchEntry(char* name) {
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Found entry for %s: %s - %s\n", name, phonebook[i].number, ctime(&phonebook[i].timestamp));
            return;
        }
    }
    printf("Entry not found.\n");
}

// Function to display all entries in the phonebook
void displayAll() {
    printf("Phonebook:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("Entry %d: %s - %s - %s\n", i+1, phonebook[i].name, phonebook[i].number, ctime(&phonebook[i].timestamp));
    }
}

// Main function with menu and user input
int main() {
    int choice;
    char name[50], number[20];

    while (1) {
        printf("\nPhonebook Menu:\n");
        printf("1. Add new entry\n");
        printf("2. Search for an entry\n");
        printf("3. Display all entries\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", number);
                addEntry(name, number);
                break;
            case 2:
                printf("Enter name to search: ");
                scanf("%s", name);
                searchEntry(name);
                break;
            case 3:
                displayAll();
                break;
            case 4:
                printf("Exiting phonebook...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}