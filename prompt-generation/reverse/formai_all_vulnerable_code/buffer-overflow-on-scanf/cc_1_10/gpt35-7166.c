//FormAI DATASET v1.0 Category: Phone Book ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 50
#define MAX_NAME_LENGTH 20
#define MAX_NUMBER_LENGTH 12

// Structure to hold phone book entry
typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} PhoneBookEntry;

// Array to hold phone book entries
PhoneBookEntry phoneBook[MAX_ENTRIES];

// Number of phone book entries
int numEntries = 0;

// Function to add an entry to the phone book
void addEntry(char *name, char *number) {
    // Check if phone book is full
    if(numEntries >= MAX_ENTRIES) {
        printf("Phone book is full!\n");
        return;
    }
    
    // Check if entry with same name already exists
    for(int i = 0; i < numEntries; i++) {
        if(strcmp(name, phoneBook[i].name) == 0) {
            printf("Entry with name %s already exists!\n", name);
            return;
        }
    }
    
    // Add entry to phone book
    strcpy(phoneBook[numEntries].name, name);
    strcpy(phoneBook[numEntries].number, number);
    numEntries++;
    printf("Entry added successfully!\n");
}

// Function to search for an entry in the phone book
void searchEntry(char *name) {
    // Check if phone book is empty
    if(numEntries == 0) {
        printf("Phone book is empty!\n");
        return;
    }
    
    // Search for entry in phone book
    for(int i = 0; i < numEntries; i++) {
        if(strcmp(name, phoneBook[i].name) == 0) {
            printf("Name: %s\tNumber: %s\n", phoneBook[i].name, phoneBook[i].number);
            return;
        }
    }
    
    // Entry not found
    printf("Entry with name %s not found!\n", name);
}

// Function to remove an entry from the phone book
void removeEntry(char *name) {
    // Check if phone book is empty
    if(numEntries == 0) {
        printf("Phone book is empty!\n");
        return;
    }
    
    // Search for entry in phone book
    for(int i = 0; i < numEntries; i++) {
        if(strcmp(name, phoneBook[i].name) == 0) {
            // Shift elements to remove entry
            for(int j = i; j < numEntries - 1; j++) {
                strcpy(phoneBook[j].name, phoneBook[j+1].name);
                strcpy(phoneBook[j].number, phoneBook[j+1].number);
            }
            numEntries--;
            printf("Entry removed successfully!\n");
            return;
        }
    }
    
    // Entry not found
    printf("Entry with name %s not found!\n", name);
}

// Function to display all entries in the phone book
void displayEntries() {
    // Check if phone book is empty
    if(numEntries == 0) {
        printf("Phone book is empty!\n");
        return;
    }
    
    // Display all entries in phone book
    for(int i = 0; i < numEntries; i++) {
        printf("Name: %s\tNumber: %s\n", phoneBook[i].name, phoneBook[i].number);
    }
}

int main() {
    char name[MAX_NAME_LENGTH], number[MAX_NUMBER_LENGTH], option;
    int n;

    printf("Welcome to C Phone Book!\n");
    
    do {
        printf("\n1. Add entry\n2. Search entry\n3. Remove entry\n4. Display all entries\n5. Exit\n");
        scanf(" %c", &option);
        
        switch(option) {
            case '1':
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter number: ");
                scanf("%s", number);
                addEntry(name, number);
                break;
            case '2':
                printf("Enter name: ");
                scanf("%s", name);
                searchEntry(name);
                break;
            case '3':
                printf("Enter name: ");
                scanf("%s", name);
                removeEntry(name);
                break;
            case '4':
                displayEntries();
                break;
            case '5':
                printf("Thank you for using C Phone Book!\n");
                break;
            default:
                printf("Invalid option!\n");
        }
    } while(option != '5');
    
    return 0;
}